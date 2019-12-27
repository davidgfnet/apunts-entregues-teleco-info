# 
# 8 x
# 4 N

.text
	.align 4
	.globl Buscar
	.type Buscar,@function
Buscar:
	pushl %ebp
	movl %esp,%ebp

	addl $(-4*4),%esp

	movl $0, -16(%ebp)   # low = 0
	movl $0, -8(%ebp)    # mid = 0
	movl 16(%ebp), %eax  # eax = N
	decl %eax
	movl %eax, -12(%ebp) # high = N-1

CosWhile:
	movl -16(%ebp), %eax   # eax = low
	cmpl -12(%ebp), %eax   # low ** hight
	jg FiWhile


	pushl 8(%ebp)   # push v
	pushl 12(%ebp)  # push x
	pushl %ebp      # push @mid
	addl $-8,(%esp)
	pushl %ebp     # push @high
	addl $-12,(%esp)
	pushl %ebp    # push @low
	addl $-16,(%esp)

	call BuscarElemento
	addl $(5*4),%esp

	movl %eax,-4(%ebp)
	cmpl $0, %eax
	jge FiWhile

	jmp CosWhile

FiWhile:
	movl -4(%ebp),%eax
	addl $(4*4),%esp

	movl %ebp,%esp
	popl %ebp
        ret

