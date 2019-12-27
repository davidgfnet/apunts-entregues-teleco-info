; Apartat 5.B
.include "macros.s"
.include "crt0.s"

; Afegeix aqui les variables globals addicionals que necessitis
	.data



; Afegeix aqui el codi del programa
	.text
teclat:
	IN	R0, Rdat_tec
	$MOVEI	R1, tteclat
	ADD	R1, R1, R0
	LDB	R0, 0(R1)
	
	MOVI	R4, 4
	OUT	Rfil_pant, R4
	MOVI	R4, 8
	OUT	Rcol_pant, R4
	
	$MOVEI	R4, 256
	ADD	R4, R0,R4 
	OUT	Rdat_pant, R4
	
	$MOVEI	R4, 0xFFFF
	OUT	Rcon_pant, R4

	$MOVEI	R5,'F
	SUB	R5,R5,R0
	BNZ	R5,final
	HALT
	
final:	JMP	R6


main:
	$MOVEI	R0, teclat
	$MOVEI	R1, interrupts_vector
	ADDI	R1,R1,2
	ST	0(R1), R0

	MOVI	R0,1
	OUT	Rcon_tec, R0
	EI

bucle:	BNZ	R0, bucle

	HALT


