/*
 * sched.c - initializes struct for task 0
 */

#include <sched.h>
#include <mm.h>
#include <segment.h>
#include <mm_address.h>

int pid_number_counter = 0;
struct list_head * runqueue;
struct list_head * emptyqueue;

struct sem_struct sem_list[NR_SEM];

struct protected_task_struct task[NR_TASKS]
  __attribute__((__section__(".data.task")));

/* Erases all the process table
   and sets the default values. 
   Also inits the runqueue */
void initialize_tasks()
{
  int i;
  for (i = 0; i < NR_TASKS; i++)
  {
    task[i].t.task.pid = -1;
    task[i].t.task.init_quantum = INITIAL_QUANTUM;
    task[i].t.task.p_stats.remaining_tics = INITIAL_QUANTUM;
    INIT_LIST_HEAD(&task[i].t.task.plist);
  }
  task[0].t.task.pid = 0;
  runqueue = &task[0].t.task.plist;
  // The task 0 has the code and data pages following the kernel pages
  for (i = 0; i < NUM_PAG_DATA; i++)
  {
    task[0].t.task.phy_data_pages[i] = NUM_PAG_KERNEL+NUM_PAG_CODE+i;
  }

  // Initialize semaphore table
  for (i = 0; i < NR_SEM; i++)
  {
    sem_list[i].value = 0;
    sem_list[i].owner = -1;
    sem_list[i].used  = 0;
    sem_list[i].sem_queue = 0;
  }

  // Init the empty process list
  emptyqueue = &task[1].t.task.plist;
  for (i = 2; i < NR_TASKS; i++) {
    list_add_tail(&task[i].t.task.plist,emptyqueue);
  }
}

union task_union * reserve_pcb() {
  if (emptyqueue == 0) return 0; // No more PCBs avaliable
  if (emptyqueue == emptyqueue->next) {
    // The last one
    union task_union * ret = (union task_union*)emptyqueue;
    emptyqueue = 0;
    return ret;
  }else{
    union task_union * ret = (union task_union*)emptyqueue;
    emptyqueue = emptyqueue->next;
    list_del(&ret->task.plist);
    return ret;
  }
}

void free_pcb(union task_union * pcb) {
  if (emptyqueue == 0) {
    emptyqueue = (struct list_head*)pcb;
    INIT_LIST_HEAD(emptyqueue);
  }else{
    list_add_tail((struct list_head*)pcb,emptyqueue);
  }
}

void init_task0(void)
{
  /* Initializes paging for the process 0 adress space */
  initialize_P0_frames();
  set_user_pages();
  set_cr3();

  initialize_tasks();
}

void update_process_stats()
{
  struct task_struct * curr_task;
  current_task_addr(curr_task);
  curr_task->p_stats.total_tics++;
  curr_task->p_stats.remaining_tics--;
}

/* Checks if a process change is needed and then
   changes the logical address mapping to the process
   Returns the kernel stack base pointer (for TSS)
   so it can be updated
   If block_current it just removes the current
   from the runqueue and picks the following
*/
void processes_scheduler() {
  // Check if the quantum has expired!
  struct task_struct * curr_task;
  current_task_addr(curr_task);

  curr_task->p_stats.total_tics++;
  if (curr_task->p_stats.remaining_tics <= 0)
  {
    // Take deleted tasks from the queue
    // Change to the next process
    runqueue = curr_task->plist.next;
    curr_task = (struct task_struct *)runqueue;
    // Change the page mappings
    task_switch ((union task_union *)curr_task,1);
  }
}

void task_switch(union task_union *t, int eoi) {
    struct task_struct * curr_task;
    current_task_addr(curr_task);
    curr_task->p_stats.total_trans++;
    curr_task->p_stats.remaining_tics = curr_task->init_quantum;

    int i;
    for (i = 0; i < NUM_PAG_DATA; i++)
    {
      set_ss_pag(((L_USER_START+NUM_PAG_CODE*0x1000)>>12)+i,((struct task_struct *)t)->phy_data_pages[i]);
    }
    set_cr3();

  if (eoi) {
    __asm__ __volatile__ (
    "movb $0x20, %al\n"
    "outb %al, $0x20\n"
    );
  }

  __asm__ __volatile__ (
  // ESP and ESP0 change
  "movl %0,%%esp\n"
  "add  %1,%%esp\n"
  "movl $(tss),%%ecx\n"
  "movl %%esp,4(%%ecx)\n"
  "add $(-16*4),%%esp\n"
  // State resore
  "popl %%ebx\n"
  "popl %%ecx\n"
  "popl %%edx\n"
  "popl %%esi\n"
  "popl %%edi\n"
  "popl %%ebp\n"
  "popl %%eax\n"
  "popl %%ds\n"
  "popl %%es\n"
  "popl %%fs\n"
  "popl %%gs\n"
  
  "iret\n"
  ::"r"(t),"c"(KERNEL_STACK_SIZE*4));
}



