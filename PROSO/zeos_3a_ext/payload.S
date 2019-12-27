
#include <asm.h>

.section .text.user_signal
ENTRY(signal_return_routine)

popl %eax;      // Remove signal argument

popl %eax;      // Restore the state before the sig. handler
popl %ecx;
popl %edx;
popf;          // Flags restore!

ret             // In the stack only the EIP remains

