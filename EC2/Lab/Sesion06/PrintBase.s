

.text
	.align 4
	.globl PrintBase
	.type PrintBase,@function

PrintBase:
	pushl %ebp
	movl %esp,%ebp

	cmpl $20,12(%ebp)
	jg Error
	cmpl $2,12(%ebp)
	jl Error
	

	pushl $0   # contador
	
	cmpl $('0'),8(%ebp)
	je Zero

	movl 8(%ebp),%eax
while:	
	cmpl $0,%eax
	je Fi
	
	incl -4(%ebp)

	xorl %edx,%edx
	divl 12(%ebp)

	pushl %edx  # Guardar residuo
	jmp while

Fi:
	# Ahora llamamos incl -4(%ebp) veces a convtab i a print char
while2:
	cmpl $0,-4(%ebp)
	je Retorn
	decl -4(%ebp)
	call ConvTab    # tenemos apilado al valor!!!! en eax tendremos el char
	pushl %eax      #imprimir
	call PrintChar
	addl $8,%esp
	
	jmp while2

Zero:
	# Nomes zero, un zero i fora!
	pushl $('0')
	call PrintChar
	jmp Retorn

Error:
	pushl $('*')
	call PrintChar
	
Retorn:

	pushl $('\n')
	call PrintChar
	
	movl %ebp,%esp
	popl %ebp
	ret


