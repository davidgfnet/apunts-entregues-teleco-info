/*
 * interrupt.c -
 */
#include <types.h>
#include <interrupt.h>
#include <segment.h>
#include <hardware.h>
#include <io.h>
#include <utils.h>
#include <sys.h>
#include <entry.h>

Gate idt[IDT_ENTRIES];
Register    idtR;

char char_map[] =
{
  '\0','\0','1','2','3','4','5','6',
  '7','8','9','0','\'','¡','\0','\0',
  'q','w','e','r','t','y','u','i',
  'o','p','`','+','\0','\0','a','s',
  'd','f','g','h','j','k','l','ñ',
  '\0','º','\0','ç','z','x','c','v',
  'b','n','m',',','.','-','\0','*',
  '\0','\0','\0','\0','\0','\0','\0','\0',
  '\0','\0','\0','\0','\0','\0','\0','7',
  '8','9','-','4','5','6','+','1',
  '2','3','0','\0','\0','\0','<','\0',
  '\0','\0','\0','\0','\0','\0','\0','\0',
  '\0','\0'
};

void setInterruptHandler(int vector, void (*handler)(), int maxAccessibleFromPL)
{
  /***********************************************************************/
  /* THE INTERRUPTION GATE FLAGS:                          R1: pg. 5-11  */
  /* ***************************                                         */
  /* flags = x xx 0x110 000 ?????                                        */
  /*         |  |  |                                                     */
  /*         |  |   \ D = Size of gate: 1 = 32 bits; 0 = 16 bits         */
  /*         |   \ DPL = Num. higher PL from which it is accessible      */
  /*          \ P = Segment Present bit                                  */
  /***********************************************************************/
  Word flags = (Word)(maxAccessibleFromPL << 13);
  flags |= 0x8E00;    /* P = 1, D = 1, Type = 1110 (Interrupt Gate) */

  idt[vector].lowOffset       = lowWord((DWord)handler);
  idt[vector].segmentSelector = __KERNEL_CS;
  idt[vector].flags           = flags;
  idt[vector].highOffset      = highWord((DWord)handler);
}

void setTrapHandler(int vector, void (*handler)(), int maxAccessibleFromPL)
{
  /***********************************************************************/
  /* THE TRAP GATE FLAGS:                                  R1: pg. 5-11  */
  /* ********************                                                */
  /* flags = x xx 0x111 000 ?????                                        */
  /*         |  |  |                                                     */
  /*         |  |   \ D = Size of gate: 1 = 32 bits; 0 = 16 bits         */
  /*         |   \ DPL = Num. higher PL from which it is accessible      */
  /*          \ P = Segment Present bit                                  */
  /***********************************************************************/
  Word flags = (Word)(maxAccessibleFromPL << 13);

  //flags |= 0x8F00;    /* P = 1, D = 1, Type = 1111 (Trap Gate) */
  /* Changed to 0x8e00 to convert it to an 'interrupt gate' and so
     the system calls will be thread-safe. */
  flags |= 0x8E00;    /* P = 1, D = 1, Type = 1110 (Interrupt Gate) */

  idt[vector].lowOffset       = lowWord((DWord)handler);
  idt[vector].segmentSelector = __KERNEL_CS;
  idt[vector].flags           = flags;
  idt[vector].highOffset      = highWord((DWord)handler);
}
void setIdt()
{
  /* Program interrups/exception service routines */
  idtR.base  = (DWord)idt;
  idtR.limit = IDT_ENTRIES * sizeof(Gate) - 1;
  /* ADD INITIALIZATION CODE FOR INTERRUPT VECTOR */
  set_idt_reg(&idtR);
}

void initialize_idt()
{
  setInterruptHandler(CLOCK_INT_NUMBER,clock_interrupt_handler,0);
  setInterruptHandler(KEYBOARD_INT_NUMBER,keyboard_interrupt_handler,0);

  setTrapHandler(SYSCALL_INT_NUMBER,syscall_interrupt_handler,3);

  setInterruptHandler(0,divide_exception_interrupt_handler,3);
  setInterruptHandler(1,debug_exception_interrupt_handler,3);
  setInterruptHandler(2,nm1_exception_interrupt_handler,3);
  setInterruptHandler(3,breakpoint_exception_interrupt_handler,3);
  setInterruptHandler(4,overflow_exception_interrupt_handler,3);
  setInterruptHandler(5,bounds_exception_interrupt_handler,3);
  setInterruptHandler(6,opcode_exception_interrupt_handler,3);
  setInterruptHandler(7,device_exception_interrupt_handler,3);
  setInterruptHandler(8,doublefault_exception_interrupt_handler,3);
  setInterruptHandler(9,coprocessor_exception_interrupt_handler,3);
  setInterruptHandler(10,tss_exception_interrupt_handler,3);
  setInterruptHandler(11,segment_exception_interrupt_handler,3);
  setInterruptHandler(12,stack_exception_interrupt_handler,3);
  setInterruptHandler(13,protection_exception_interrupt_handler,3);
  setInterruptHandler(14,page_exception_interrupt_handler,3);
  setInterruptHandler(16,float_exception_interrupt_handler,3);
  setInterruptHandler(17,alignment_exception_interrupt_handler,3);

  enable_int();
}





void clock_interrupt_routine (void)
{
  static int ticks = 0;
  static int seconds = 0;
  static int minutes = 0;
  if (++ticks >= 18)
  {
    ticks = 0;
    if (++seconds >= 60)
    {
      minutes++;
      seconds = 0;
    }
  }
  // Clear the clock area
  printf_xy(70,2,"     ");
  // Draw the minutes
  char buffer[32];
  itoa(minutes,buffer);
  if (minutes < 10)
  {
    printc_xy(70,2,'0');
    printf_xy(71,2,buffer);
  }
  else
  {
    printf_xy(70,2,buffer);
  }
  // Draw the seconds
  itoa(seconds,buffer);
  if (seconds < 10)
  {
    printc_xy(73,2,'0');
    printf_xy(74,2,buffer);
  }
  else
  {
    printf_xy(73,2,buffer);
  }
  // Draw the :
  printc_xy(72,2,':');
}


void keyboard_interrupt_routine (void)
{
  unsigned char car = inb(0x60);
  char caracter = char_map[car&0x7F];
  if ((car & 0x80) != 0)
  {
    // This is a break
    printf_xy(69,23,"       ");
  }
  else
  {
    // This is a make
    if (caracter == 0)
    {
      // Control character
      printf_xy(69,23,"Control");
    }
    else
    {
      // Regular character
      printc_xy(73,23,caracter);
    }
  }
}

void divide_exception_interrupt_routine()
{
  printk("\n -- Divide exception --\n");
  while (1);
}

void debug_exception_interrupt_routine()
{
  printk("\n -- Debug exception --\n");
  while (1);
}

void nm1_exception_interrupt_routine()
{
  printk("\n -- NM1 exception --\n");
  while (1);
}

void breakpoint_exception_interrupt_routine()
{
  printk("\n -- Breakpoint exception --\n");
  while (1);
}

void overflow_exception_interrupt_routine()
{
  printk("\n -- Overflow exception --\n");
  while (1);
}

void bounds_exception_interrupt_routine()
{
  printk("\n -- Bounds check exception --\n");
  while (1);
}

void opcode_exception_interrupt_routine()
{
  printk("\n -- Unknown OPCODE exception --\n");
  while (1);
}

void device_exception_interrupt_routine()
{
  printk("\n -- Device exception --\n");
  while (1);
}

void coprocessor_exception_interrupt_routine()
{
  printk("\n -- Coprocessor exception --\n");
  while (1);
}

void float_exception_interrupt_routine()
{
  printk("\n -- Floating point exception --\n");
  while (1);
}

void doublefault_exception_interrupt_routine(int param)
{
  printk("\n -- Double fault exception --\n");
  while (1);
}

void tss_exception_interrupt_routine(int param)
{
  printk("\n -- Invalid TSS exception --\n");
  while (1);
}

void segment_exception_interrupt_routine(int param)
{
  printk("\n -- Segment exception --\n");
  while (1);
}

void stack_exception_interrupt_routine(int param)
{
  printk("\n -- Stack exception --\n");
  while (1);
}

void protection_exception_interrupt_routine(int param)
{
  printk("\n -- General protection exception --\n");
  while (1);
}

void page_exception_interrupt_routine(int param)
{
  printk("\n -- Page exception --\n");
  while (1);
}

void alignment_exception_interrupt_routine(int param)
{
  printk("\n -- Alignment exception --\n");
  while (1);
}


