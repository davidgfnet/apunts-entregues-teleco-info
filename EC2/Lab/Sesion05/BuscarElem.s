# 8  *low
# 12  *high
# 16  *mid
# 20   xx
# 24   v

.text
	.align 4
	.globl BuscarElemento
	.type BuscarElemento,@function
BuscarElemento:
	pushl %ebp
	movl %esp,%ebp

	movl 16(%ebp),%eax        # %eax es &mid
	movl (%eax),%eax          # %eax es mid
	imull $(3*4),%eax         # mid x 12
	movl 24(%ebp), %ebx       # %ebx es v
	movl 4(%ebx, %eax),%ecx     # %ch es v[*mid].k
	movl 8(%ebx, %eax),%edx   # %edx es v[*mid].m
	addl (%edx), %ecx		  # %edx es v[*mid].k + *(v[*mid].m)
	cmpl 20(%ebp),%ecx
	jne BuscarElemento_else
	
	movl 16(%ebp),%eax       # %eax es &mid
	movl (%eax),%eax          # %eax es mid
	jmp BuscarElemento_sortir

BuscarElemento_else:
	
	movl 16(%ebp),%eax       # %eax es mid
	movl (%eax),%eax
	movl 12(%ebp),%ebx       # %ebx es high
	cmpl (%ebx),%eax
	jge BuscarElemento_else2

	movl 12(%ebp),%eax      # %eax es &high
	movl (%eax),%eax        # %eax es high
	movl 16(%ebp),%ebx      # %ebx es &mid
	movl %eax, (%ebx)       # *mid = *high;
	movl 8(%ebp),%eax       # %eax es &low
	addl $1,(%eax)		# *low ++
	movl $-1, %eax          # return -1
	jmp BuscarElemento_sortir

BuscarElemento_else2:

	movl 8(%ebp),%eax      # %eax es &low
	movl (%eax),%eax       # %eax es low
	movl 16(%ebp),%ebx     # %ebx es &mid
	movl %eax, (%ebx)      # *mid = *low;
	movl 12(%ebp),%eax     # %eax es &high
	addl $-1,(%eax)        # *high --
	movl $-1, %eax         # return -1

BuscarElemento_sortir:

	movl %ebp,%esp
	popl %ebp
        ret


