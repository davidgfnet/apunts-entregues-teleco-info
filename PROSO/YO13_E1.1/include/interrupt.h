/*
 * interrupt.h - Definició de les diferents rutines de tractament d'exepcions
 */

#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

#include <types.h>

/* We use constants cause we don't have memory avaliable ;) */
#define CLOCK_INT_NUMBER 32
#define KEYBOARD_INT_NUMBER 33
#define SYSCALL_INT_NUMBER 0x80

#define IDT_ENTRIES 256

extern Gate idt[IDT_ENTRIES];
extern Register idtR;

void setInterruptHandler(int vector, void (*handler)(), int maxAccessibleFromPL);
void setTrapHandler(int vector, void (*handler)(), int maxAccessibleFromPL);

void setIdt();
void initialize_idt();

void clock_interrupt_routine();
void keyboard_interrupt_routine();

void divide_exception_interrupt_routine();
void debug_exception_interrupt_routine();
void nm1_exception_interrupt_routine();
void breakpoint_exception_interrupt_routine();
void overflow_exception_interrupt_routine();
void bounds_exception_interrupt_routine();
void opcode_exception_interrupt_routine();
void device_exception_interrupt_routine();
void coprocessor_exception_interrupt_routine();
void float_exception_interrupt_routine();
void doublefault_exception_interrupt_routine(int param);
void tss_exception_interrupt_routine(int param);
void segment_exception_interrupt_routine(int param);
void stack_exception_interrupt_routine(int param);
void protection_exception_interrupt_routine(int param);
void page_exception_interrupt_routine(int param);
void alignment_exception_interrupt_routine(int param);


#endif  /* __INTERRUPT_H__ */
