/*
 * mm.c - Memory Management: Paging & segment memory management
 */

#include <types.h>
#include <mm.h>
#include <segment.h>
#include <hardware.h>
#include <sched.h>
#include <fat.h>
#include <utils.h>

extern void signal_return_routine();

Byte phys_mem[TOTAL_PAGES];

/* SEGMENTATION */
/* Memory segements description table */
Descriptor  *gdt = (Descriptor *) GDT_START;
/* Register pointing to the memory segments table */
Register    gdtR;

/* PAGING */
/* Variables containing the page directory and the page table */
  
page_table_entry dir_pages[TOTAL_PAGES]
  __attribute__((__section__(".data.task")));

page_table_entry pagusr_table[TOTAL_PAGES]
  __attribute__((__section__(".data.task")));

/* TSS */
TSS         tss; 



/***********************************************/
/************** PAGING MANAGEMENT **************/
/***********************************************/

/* Init page table directory */
  
void init_dir_pages()
{
  dir_pages[ENTRY_DIR_PAGES].entry = 0;
  dir_pages[ENTRY_DIR_PAGES].bits.pbase_addr = (((unsigned int)&pagusr_table) >> 12);
  dir_pages[ENTRY_DIR_PAGES].bits.user = 1;
  dir_pages[ENTRY_DIR_PAGES].bits.rw = 1;
  dir_pages[ENTRY_DIR_PAGES].bits.present = 1;
}

/* Initializes the page table (kernel pages only) */
void init_table_pages()
{
  int i;
  unsigned int page;
  /* reset all entries */
  for (i=0; i<TOTAL_PAGES; i++)
    pagusr_table[i].entry = 0;

  /* Init kernel pages */
  for (i=0; i<NUM_PAG_KERNEL; i++)
    {
      // Logical page equal to physical page (frame)
      pagusr_table[i].bits.pbase_addr = i;
      pagusr_table[i].bits.rw = 1;
      pagusr_table[i].bits.present = 1;
    }
  /* Protect task_structs */
  for (i=0; i<NR_TASKS; i++)
    {
      page = ((DWord)&task[i].task_protect>>12); //Get the page to protect.
      pagusr_table[page].bits.pbase_addr = page;
      pagusr_table[page].bits.rw = 0; //Disable write access to protected page
      pagusr_table[page].bits.present = 0; /* Generate a Page Fault when accessed */
    }

  /* Init disk IO pages (data for the disk) */
  for (i=0; i<(MAX_BLOCKS/4); i++)
    {
      // Logical page equal to physical page (frame)
      int pagenum = (IO_ADDRESS>>12)+i;
      pagusr_table[pagenum].bits.pbase_addr = pagenum;
      pagusr_table[pagenum].bits.rw = 1;
      pagusr_table[pagenum].bits.present = 1;
    }

    pagusr_table[((int)signal_return_routine)>>12].bits.user = 1;
}

/* Initialize pages for initial process (user pages) */
void set_user_pages( void )
{
 int pag; 
 int first_ph_page = NUM_PAG_KERNEL;

  /* CODE */
  for (pag=PAG_LOG_INIT_CODE_P0;pag<PAG_LOG_INIT_DATA_P0;pag++){
  	pagusr_table[pag].entry = 0;
  	pagusr_table[pag].bits.pbase_addr = first_ph_page;
  	pagusr_table[pag].bits.user = 1;
  	pagusr_table[pag].bits.present = 1;
        first_ph_page++;
  }
  
  /* DATA */ 
  for (pag=PAG_LOG_INIT_DATA_P0;pag<PAG_LOG_INIT_DATA_P0+NUM_PAG_DATA;pag++){
  	pagusr_table[pag].entry = 0;
  	pagusr_table[pag].bits.pbase_addr = first_ph_page;
  	pagusr_table[pag].bits.user = 1;
  	pagusr_table[pag].bits.rw = 1;
  	pagusr_table[pag].bits.present = 1;
    first_ph_page++;
  }
}

/* Writes on CR3 register producing a TLB flush */
void set_cr3()
{
 	asm volatile("movl %0,%%cr3": :"r" (dir_pages));
}

/* Macros for reading/writing the CR0 register, where is shown the paging status */
#define read_cr0() ({ \
         unsigned int __dummy; \
         __asm__( \
                 "movl %%cr0,%0\n\t" \
                 :"=r" (__dummy)); \
         __dummy; \
})
#define write_cr0(x) \
         __asm__("movl %0,%%cr0": :"r" (x));
         
/* Enable paging, modifying the CR0 register */
void set_pe_flag()
{
  unsigned int cr0 = read_cr0();
  cr0 |= 0x80000000;
  write_cr0(cr0);
}

/* Associates logical page 'page' with physical page 'frame' */
void set_ss_pag(unsigned page,unsigned frame)
{
  pagusr_table[page].entry=0;
  pagusr_table[page].bits.pbase_addr=frame;
  pagusr_table[page].bits.user=1;
  pagusr_table[page].bits.rw=1;
  pagusr_table[page].bits.present=1;
}
/* Associates logical page 'page' with physical page 'frame' */
void set_ss_pag_kernel(unsigned page,unsigned frame)
{
  pagusr_table[page].entry=0;
  pagusr_table[page].bits.pbase_addr=frame;
  pagusr_table[page].bits.user=0;
  pagusr_table[page].bits.rw=1;
  pagusr_table[page].bits.present=1;
}
/* Initializes paging for the system address space */
void init_mm()
{
  init_table_pages();
  init_frames();
  init_dir_pages();
  set_cr3();
  set_pe_flag();
}
/***********************************************/
/************** SEGMENTATION MANAGEMENT ********/
/***********************************************/
void setGdt()
{
  /* Configure TSS base address, that wasn't initialized */
  gdt[KERNEL_TSS>>3].lowBase = lowWord((DWord)&(tss));
  gdt[KERNEL_TSS>>3].midBase  = midByte((DWord)&(tss));
  gdt[KERNEL_TSS>>3].highBase = highByte((DWord)&(tss));

  gdtR.base = (DWord)gdt;
  gdtR.limit = 256 * sizeof(Descriptor);

  set_gdt_reg(&gdtR);
}

/***********************************************/
/************* TSS MANAGEMENT*******************/
/***********************************************/
void setTSS()
{
  tss.PreviousTaskLink   = NULL;
  tss.esp0               = KERNEL_ESP;
  tss.ss0                = __KERNEL_DS;
  tss.esp1               = NULL;
  tss.ss1                = NULL;
  tss.esp2               = NULL;
  tss.ss2                = NULL;
  tss.cr3                = NULL;
  tss.eip                = 0;
  tss.eFlags             = INITIAL_EFLAGS; /* Enable interrupts */
  tss.eax                = NULL;
  tss.ecx                = NULL;
  tss.edx                = NULL;
  tss.ebx                = NULL;
  tss.esp                = USER_ESP;
  tss.ebp                = tss.esp;
  tss.esi                = NULL;
  tss.edi                = NULL;
  tss.es                 = __USER_DS;
  tss.cs                 = __USER_CS;
  tss.ss                 = __USER_DS;
  tss.ds                 = __USER_DS;
  tss.fs                 = NULL;
  tss.gs                 = NULL;
  tss.LDTSegmentSelector = KERNEL_TSS;
  tss.debugTrap          = 0;
  tss.IOMapBaseAddress   = NULL;

  set_task_reg(KERNEL_TSS);
}

 
/* Initializes the ByteMap of free physical pages.
 * The kernel pages are marked as used */
int init_frames( void )
{
    int i;
    /* Mark pages as Free */
    for (i=0; i<TOTAL_PAGES; i++) {
        phys_mem[i] = FREE_FRAME;
    }
    /* Mark kernel pages as Used */
    for (i=0; i<NUM_PAG_KERNEL; i++) {
        phys_mem[i] = USED_FRAME;
    }
    return 0;
}

/* initialize_P0_frames - Initializes user code frames and user data frames for Initial Process P0.
 * Returns the First Physical frame for P0 */
int initialize_P0_frames(void)
{
    int i;
    /* Mark User Code AND Data pages as Used */
    for (i=0; i<NUM_PAG_CODE+NUM_PAG_DATA; i++) {
        phys_mem[NUM_PAG_KERNEL+i] = USED_FRAME;
    }
    return NUM_PAG_KERNEL;
}
/* alloc_frame - Search a free physical page (== frame) and mark it as USED_FRAME. 
 * Returns the frame number or -1 if there isn't any frame available. */
int alloc_frame( void )
{
    int i;
    for (i=NUM_PAG_KERNEL; i<TOTAL_PAGES;) {
        if (phys_mem[i] == FREE_FRAME) {
            phys_mem[i] = USED_FRAME;
            return i;
        }
        i += 2; /* NOTE: There will be holes! */
    }

    return -1;
}

/* free_frame - Mark as FREE_FRAME the frame  'frame'.*/
void free_frame( unsigned int frame )
{
    phys_mem[frame] = FREE_FRAME;
}

// Erases the page entry
void del_ss_pag(unsigned pagina_logica)
{
  pagusr_table[pagina_logica].entry=0;
}

void map_task_pages(struct task_struct * t) {
    int i;
    for (i = 0; i < NUM_PAG_DATA; i++)
      set_ss_pag(((L_USER_START+NUM_PAG_CODE*0x1000)>>12)+i,t->phy_data_pages[i]);

    set_cr3();
}

// HEAP MANAGEMENT

struct memory_block_struct {
  struct memory_block_struct * next_block;
  int bs;
  int used;
};

extern struct memory_block_struct kernel_heap_start;
extern struct memory_block_struct kernel_heap_end;
struct memory_block_struct * heap_first_block;

void init_kheap() {
  heap_first_block = (struct memory_block_struct *)&kernel_heap_start;
  int size = ((int)&kernel_heap_end)-((int)&kernel_heap_start);
  heap_first_block->next_block = 0;
  heap_first_block->bs = size;
  heap_first_block->used = 0;

  printk("Init Heap. Heap size avaliable : ");
  char buf[32]; itoa(size,buf); printk(buf); printk(" bytes\n");
}

// Reserves a memory block
void * kmalloc(int size) {
  if (size == 0) return 0;
  size = ((size+255)&(~0xFF));  // round to 256 bytes block
  int need_size = size+sizeof(struct memory_block_struct);
  int min_block_size = size+2*sizeof(struct memory_block_struct);
  
  struct memory_block_struct * curr_block = heap_first_block;
  while (curr_block != 0) {
    if (curr_block->used == 0 && curr_block->bs >= (min_block_size)) {
      int old_size = curr_block->bs;
      curr_block->used = 1;
      curr_block->bs = need_size;
      struct memory_block_struct * new_next_block = (struct memory_block_struct *)(((int)curr_block)+need_size);
      new_next_block->next_block = curr_block->next_block;
      new_next_block->used = 0;
      new_next_block->bs = old_size-need_size;
      
      curr_block->next_block = new_next_block;

      return (void*)(((int)curr_block)+sizeof(struct memory_block_struct));
    }

    curr_block = curr_block->next_block;
  }
  return 0;
}

// Frees a memory block and tries to join free space blocks
void kfree(void *ptr) {
  if (ptr == 0) return;
  struct memory_block_struct * curr_block = (struct memory_block_struct *)(((int)ptr)-sizeof(struct memory_block_struct));
  curr_block->used = 0;

  curr_block = heap_first_block;
  while (curr_block != 0) {
    if (curr_block->next_block == 0) break; // Don't even try

    if (curr_block->used == 0 && curr_block->next_block->used == 0) { // Join the blocks
      curr_block->bs += curr_block->next_block->bs;
      curr_block->next_block = curr_block->next_block->next_block;
    }else{
      curr_block = curr_block->next_block;
    }
  }
}

