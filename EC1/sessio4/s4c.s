; Apartat 4.C
.include "macros.s"
.include "crt0.s"

; Afegeix aqui les variables globals addicionals que necessitis
	.data
frase:	.asciz "Aquest programa funciona"
	.fill	5, 1, 0			; els 5 caracters restants fins a 30



; Afegeix aqui el codi del programa
	.text
main:
	MOVI	R0, 0
	OUT	Rcon_imp, R0
	$MOVEI	R5, 0x8000

	$MOVEI	R1, frase

bucle:
	LDB	R2, 0(R1)

	BZ	R2, fibucle
	
	preparada:
		IN	R0, Rest_imp
		BZ	R0, preparada

	OUT	Rdat_imp, R2
	OUT	Rcon_imp, R5
	ADDI	R1, R1, 1
	
	BNZ	R2, bucle

fibucle:

	HALT

