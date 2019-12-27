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

/* NOTA: Las funciones de restaurar el estado NO PRESERVAN EAX
   De esta forma eax no queda machacado al devolver una syscall
   Cuando es necesario (interrupción/excepción) si es guardado
   También se preservan los registros para usarlos en la syscall
   (antes se machacaba edx) */

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
  movl $__KERNEL_DS, %edx;    \
  movl %edx, %ds;           \
  movl %edx, %es;

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
  movb $0x20, %al; \
  outb %al, $0x20;

// This handler DOES EOI
#define INTERRUPT_HANDLER(a,b) \
  ENTRY(a) \
    SAVE_ALL \
    call b; \
    EOI \
    RESTORE_ALL \
    iret;

// Generic handler for a regular exception
#define GENERIC_HANDLER(a,b) \
  ENTRY(a) \
    SAVE_ALL \
    call b; \
    RESTORE_ALL \
    iret;

// This version pushes the data (4bytes) located
// between %gs and %eip to the top of the stack so
// the handler can have an int parameter to read
// Don't forget to remove bothe the parameter and the
// system parameter
#define EXCEPTION_PARAMETER_HANDLER(a,b) \
  ENTRY(a) \
    SAVE_ALL \
    movl (11*4)(%esp),%eax; \
    pushl %eax; \
    call b; \
    addl $4,%esp; \
    RESTORE_ALL \
    addl $4,%esp; \
    iret;


/* Clock interrupt */
INTERRUPT_HANDLER(clock_interrupt_handler,clock_interrupt_routine)
/* Keyboard interrupt */
INTERRUPT_HANDLER(keyboard_interrupt_handler,keyboard_interrupt_routine)


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


#define NUM_SYSCALLS 65
/* The syscall table */
ENTRY(sys_call_table)
 .long sys_ni_syscall  // sys_setup    0
 .long sys_exit        // sys_exit
 .long sys_fork        // sys_fork
 .long sys_read        // sys_read
 .long sys_write       // sys_write    4
 .long sys_open        // sys_open
 .long sys_close       // sys_close
 .long sys_waitpid     // sys_waitpid  7
 .long sys_ni_syscall  // sys_creat
 .long sys_ni_syscall  // sys_link     9
 .long sys_unlink      // sys_unlink
 .long sys_ni_syscall  // sys_execve
 .long sys_ni_syscall  // sys_chdir
 .long sys_ni_syscall  // sys_time
 .long sys_ni_syscall  // sys_mknod    14
 .long sys_ni_syscall  // sys_chmod
 .long sys_ni_syscall  // sys_lchown
 .long sys_ni_syscall  // sys_break
 .long sys_ni_syscall  // sys_oldstat
 .long sys_ni_syscall  // sys_lseek
 .long sys_getpid      // sys_getpid       20
 .long sys_sem_init    // sys_sem_init 21
 .long sys_sem_wait    // sys_sem_wait 22
 .long sys_sem_signal  // sys_sem_signal 23
 .long sys_sem_destroy // sys_sem_destroy 24
 .long sys_ni_syscall  // sys_stime
 .long sys_ni_syscall  // sys_ptrace
 .long sys_alarm       // sys_alarm      27
 .long sys_ni_syscall  // sys_oldfstat
 .long sys_ni_syscall  // sys_pause
 .long sys_ni_syscall  // sys_utime
 .long sys_ni_syscall  // sys_stty
 .long sys_ni_syscall  // sys_gtty
 .long sys_ni_syscall  // sys_access
 .long sys_nice        // sys_nice    34
 .long sys_get_stats   // sys_get_stats 35
 .long sys_ni_syscall  // sys_sync
 .long sys_kill        // sys_kill     37
 .long sys_ni_syscall  // sys_???      38
 .long sys_ni_syscall  // sys_???      39
 .long sys_ni_syscall  // sys_???      40
 .long sys_dup         // sys_dup      41
 .long sys_pipe        // sys_pipe     42
 .long sys_ni_syscall  // sys_???      43
 .long sys_ni_syscall  // sys_???
 .long sys_ni_syscall  // sys_???
 .long sys_ni_syscall  // sys_???      46
 .long sys_ni_syscall  // sys_???
 .long sys_signal      // sys_signal   48
 .long sys_ni_syscall  // sys_???
 .long sys_ni_syscall  // sys_???       50
 .long sys_ni_syscall  // sys_???
 .long sys_ni_syscall  // sys_???
 .long sys_ni_syscall  // sys_???
 .long sys_ni_syscall  // sys_???
 .long sys_ni_syscall  // sys_???      55
 .long sys_ni_syscall  // sys_???
 .long sys_ni_syscall  // sys_???
 .long sys_ni_syscall  // sys_???      58
 .long sys_ni_syscall  // sys_???
 .long sys_ni_syscall  // sys_???      60
 .long sys_ni_syscall  // sys_???
 .long sys_ni_syscall  // sys_???
 .long sys_dup2        // sys_dup2     63
 .long sys_getppid     // sys_getppid  64
 .long sys_ni_syscall  // sys_???
 .long sys_ni_syscall  // sys_???


/* Syscall trap interrupt */
// We can use eax since it will be overwritten by the 
ENTRY(syscall_interrupt_handler)
  SAVE_ALL

  cmpl $0,%eax;       // Make sure we don't exceed the table capacity
  jl bad_syscall;
  cmpl $(NUM_SYSCALLS),%eax;
  jge bad_syscall;

  call *sys_call_table(, %eax, 0x04);
  movl %eax,0x18(%esp); // Update the value of eax to avoid being overwritten by RESTORE_ALL
  RESTORE_ALL
  iret;

bad_syscall:
  movl $(-ENOSYS),0x18(%esp);
  RESTORE_ALL
  iret;


