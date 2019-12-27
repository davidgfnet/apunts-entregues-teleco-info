
.globl syscall_wrapper
.type syscall_wrapper, @function
.align 0;

  syscall_wrapper:

    popl  %eax
    pushl %ebx
    pushl %esi
    pushl %edi

    movl 8(%ebp),%ebx
    movl 12(%ebp),%ecx
    movl 16(%ebp),%edx
    int $0x80

    cmp $0,%eax
    jns _exit

    not %eax
    add $1,%eax
    movl $(errno),%ebx
    movl %eax,(%ebx)
    movl $(-1),%eax

    _exit:
    popl %edi
    popl %esi
    popl %ebx

    leave
    ret

