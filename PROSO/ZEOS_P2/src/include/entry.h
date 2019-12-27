/*
 * entry.h - Definició del punt d'entrada de les crides al sistema
 */

#ifndef __ENTRY_H__
#define __ENTRY_H__


void clock_interrupt_handler();
void keyboard_interrupt_handler();
void syscall_interrupt_handler();

void divide_exception_interrupt_handler();
void debug_exception_interrupt_handler();
void nm1_exception_interrupt_handler();
void breakpoint_exception_interrupt_handler();
void overflow_exception_interrupt_handler();
void bounds_exception_interrupt_handler();
void opcode_exception_interrupt_handler();
void device_exception_interrupt_handler();
void coprocessor_exception_interrupt_handler();
void float_exception_interrupt_handler();

void doublefault_exception_interrupt_handler(int param);
void coprocessor_exception_interrupt_handler(int param);
void tss_exception_interrupt_handler(int param);
void segment_exception_interrupt_handler(int param);
void stack_exception_interrupt_handler(int param);
void protection_exception_interrupt_handler(int param);
void page_exception_interrupt_handler(int param);
void float_exception_interrupt_handler(int param);
void alignment_exception_interrupt_handler(int param);


#endif  /* __ENTRY_H__ */
