/*
 * entry.S - Entry point to system mode from user mode
 */

#include <asm.h>
#include <segment.h>
#include <errno.h>


/**************************************************/
/**** Save & Restore ******************************/
/**                                              **/
/** When we change to privilege level 0 (kernel) **/
/** (through an interrupt, a system call, an     **/
/** exception ...) we must save the state of the **/
/** currently running task (save).               **/
/**                                              **/
/** Stack layout in 'systemCall':                **/
/**                                              **/
/**   0(%esp) - %ebx    \                        **/
/**   4(%esp) - %ecx     |                       **/
/**   8(%esp) - %edx     |                       **/
/**   C(%esp) - %esi     | Register saved        **/
/**  10(%esp) - %edi     |  by 'save'            **/
/**  14(%esp) - %ebp     |                       **/
/**  18(%esp) - %eax     |                       **/
/**  1C(%esp) - %ds      |                       **/
/**  20(%esp) - %es      |                       **/
/**  24(%esp) - %fs      |                       **/
/**  28(%esp) - %gs     /                        **/
/**  2C(%esp) - %eip    \                        **/
/**  30(%esp) - %cs      |                       **/
/**  34(%esp) - %eflags  |  Return context saved **/
/**  38(%esp) - %oldesp  |   by the processor.   **/
/**  3C(%esp) - %oldss  /                        **/
/**                                              **/
/**************************************************/


#define SAVE_ALL \
  pushl %gs; \
  pushl %fs; \
  pushl %es; \
  pushl %ds; \
  pushl %eax; \
  pushl %ebp; \
  pushl %edi; \
  pushl %esi; \
  pushl %edx; \
  pushl %ecx; \
  pushl %ebx; \
  pushl %edx; \
  movl $__KERNEL_DS, %edx;    \
  movl %edx, %ds;           \
  movl %edx, %es; \
  popl %edx;

#define RESTORE_ALL \
  popl %ebx; \
  popl %ecx; \
  popl %edx; \
  popl %esi; \
  popl %edi; \
  popl %ebp; \
  popl %eax; \
  popl %ds; \
  popl %es; \
  popl %fs; \
  popl %gs;

#define EOI \
  pushl %eax; \
  movb $0x20, %al; \
  outb %al, $0x20; \
  popl %eax;

#define GENERIC_HANDLER(a,b) \
  ENTRY(a) \
    SAVE_ALL \
    call b; \
    RESTORE_ALL \
    EOI \
    iret;

/* Does the same as the GENERIC_HANDLER but pushes the
   exception parameter to the top of the stack */
#define EXCEPTION_PARAMETER_HANDLER(a,b) \
  ENTRY(a) \
    SAVE_ALL \
    call b; \
    RESTORE_ALL \
    EOI \
    iret;


/* Clock interrupt */
GENERIC_HANDLER(clock_interrupt_handler,clock_interrupt_routine)
/* Keyboard interrupt */
GENERIC_HANDLER(keyboard_interrupt_handler,keyboard_interrupt_routine)


/* Divide exception */
GENERIC_HANDLER(divide_exception_interrupt_handler,divide_exception_interrupt_routine)
/* Debug exception */
GENERIC_HANDLER(debug_exception_interrupt_handler,debug_exception_interrupt_routine)
/* NM1 exception */
GENERIC_HANDLER(nm1_exception_interrupt_handler,nm1_exception_interrupt_routine)
/* Breakpoint exception */
GENERIC_HANDLER(breakpoint_exception_interrupt_handler,breakpoint_exception_interrupt_routine)
/* Overflow exception */
GENERIC_HANDLER(overflow_exception_interrupt_handler,overflow_exception_interrupt_routine)
/* Bounds check exception */
GENERIC_HANDLER(bounds_exception_interrupt_handler,bounds_exception_interrupt_routine)
/* Invalid OPCODE exception */
GENERIC_HANDLER(opcode_exception_interrupt_handler,opcode_exception_interrupt_routine)
/* Device not avaliable exception */
GENERIC_HANDLER(device_exception_interrupt_handler,device_exception_interrupt_routine)
/* Double fault exception */
EXCEPTION_PARAMETER_HANDLER(doublefault_exception_interrupt_handler,doublefault_exception_interrupt_routine)
/* Coprocessor segment overrun exception */
GENERIC_HANDLER(coprocessor_exception_interrupt_handler,coprocessor_exception_interrupt_routine)
/* Invalid TSS exception */
EXCEPTION_PARAMETER_HANDLER(tss_exception_interrupt_handler,tss_exception_interrupt_routine)
/* Segment not present exception */
EXCEPTION_PARAMETER_HANDLER(segment_exception_interrupt_handler,segment_exception_interrupt_routine)
/* Stack exception */
EXCEPTION_PARAMETER_HANDLER(stack_exception_interrupt_handler,stack_exception_interrupt_routine)
/* General protection exception */
EXCEPTION_PARAMETER_HANDLER(protection_exception_interrupt_handler,protection_exception_interrupt_routine)
/* Page fault exception */
EXCEPTION_PARAMETER_HANDLER(page_exception_interrupt_handler,page_exception_interrupt_routine)
/* Floating point exception */
GENERIC_HANDLER(float_exception_interrupt_handler,float_exception_interrupt_routine)
/* Alignment exception */
EXCEPTION_PARAMETER_HANDLER(alignment_exception_interrupt_handler,alignment_exception_interrupt_routine)


/* The syscall table */
// Currenty only has 8 entries
#define SYSCALL_TABLE_MAX 8
ENTRY(sys_call_table)
 .long sys_ni_syscall  // sys_setup
 .long sys_ni_syscall  // sys_exit
 .long sys_ni_syscall  // sys_fork
 .long sys_ni_syscall  // sys_read
 .long sys_write       // sys_write
 .long sys_ni_syscall  // sys_open
 .long sys_ni_syscall  // sys_close
 .long sys_ni_syscall  // sys_waitpid


/* Syscall trap interrupt */
// We can use eax since it will be overwritten by the 
ENTRY(syscall_interrupt_handler)
  SAVE_ALL
  pushl %edi;        // Push the parameters for the sys_call
  pushl %esi;
  pushl %edx;
  pushl %ecx;
  pushl %ebx;

  cmpl $0,%eax;       // Make sure we don't exceed the table capacity
  jl bad_syscall;
  cmpl $8,%eax;
  jge bad_syscall;

  call *sys_call_table(, %eax, 0x04);
  add   $(5*4),%esp;  // Delete the parameters
  movl %eax,0x18(%esp); // Update the value of eax to avoid being overwritten by RESTORE_ALL
  RESTORE_ALL
  iret;

bad_syscall:
  add   $(5*4),%esp;
  movl $(-ENOSYS),0x18(%esp);
  RESTORE_ALL
  iret;
	

