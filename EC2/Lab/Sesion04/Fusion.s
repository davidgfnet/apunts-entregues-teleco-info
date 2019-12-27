.text
	.align 4
	.globl Fusion
	.type Fusion,@function
fusion:
	pushl %ebp
	movl %esp,%ebp

        pushl %ebx
	pushl %esi
	pushl %edi

        movl 8(%ebp), %ebx
        movl 12(%ebp), %esi
        movl 20(%ebp), %edi

        xorl %edx, %edx
        xorl %ecx, %ecx

.Lw1:   cmpl 16(%ebp), %edx
        jge .Le1
        cmpl 16(%ebp), %ecx
        jge .Le1
        movl (%esi, %edx, 4), %eax
        cmpl %eax, (%edi, %ecx, 4)
        jge .Lc
        movl %eax, (%ebx)
        incl edx
        addl $4, %ebx
        jmp .Lw1
.Lc:    movl (%edi, %ecx, 4), %eax
        movl %eax, (%ebx)
        incl %ecx
        incl %ebx 
        jmp .Lw1
.Le1:  
.Lw2:   cmpl %edx, 16(%ebp)
        jge .Le2
        movl (%esi, %edx, 4), %eax
        movl %eax, (%ebx)
        incsl %edx
        incl %ebx
        jmp .Lw2
.Le2:
.Lw3:   cmpl %ecx, 16(%ebp)
        jge .Le3
        movl (%edi, %ecx, 4), %eax
        movl %eax, (%ebx)
        incl %ecx
        addl 4, %ebx 
        jmp .Lw3
.Le4:
        popl %edi
	popl %esi
	popl %ebx

	movl %ebp,%esp
	popl %ebp
	ret
