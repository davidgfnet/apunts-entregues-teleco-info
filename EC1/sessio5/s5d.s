; Apartat 5.D
.include "macros.s"
.include "crt0.s"

; Afegeix aqui les variables globals addicionals que necessitis
	.data
fila:		.word	4
columna:	.word	8
inc_fila:	.word	0
inc_columna:	.word	1
clock:		.word	0

; Afegeix aqui el codi del programa
	.text
teclat:
	IN	R0,Rdat_tec
	$MOVEI	R1,tteclat
	ADD	R1,R1,R0
	LDB	R0,0(R1)	;R0 = caracter

	$MOVEI	R4,inc_fila
	LD	R4,0(R4)
	$MOVEI	R5,inc_columna
	LD	R5,0(R5)

	
	$MOVEI	R2,'S
	CMPEQ	R3,R0,R2
	BZ	R3, salt1
	MOVI	R5,1
	MOVI	R4,0
salt1:

	$MOVEI	R2,'A
	CMPEQ	R3,R0,R2
	BZ	R3,salt2
	MOVI	R5,-1
	MOVI	R4,0
salt2:

	$MOVEI	R2,'L
	CMPEQ	R3,R0,R2
	BZ	R3,salt3
	MOVI	R4,1
	MOVI	R5,0
salt3:

	$MOVEI	R2,'P
	CMPEQ	R3,R0,R2
	BZ	R3,salt4
	MOVI	R4,-1
	MOVI	R5,0
salt4:

	;guardar incs

	$MOVEI	R2,inc_fila
	$MOVEI	R3,inc_columna
	ST	0(R2),R4
	ST	0(R3),R5

	JMP	R6

rellotge:
	$MOVEI	R0, clock
	LD	R1,0(R0)
	ADDI	R1,R1,1
	ST	0(R0),R1
	
	ADDI	R5,R1,-4
	BNZ	R5,fi_rel

	MOVI	R1,0
	ST	0(R0),R1

	$MOVEI	R1,fila
	LD	R2,0(R1)
	OUT	Rfil_pant, R2    ;out fila ; fila+=inc_fila
	$MOVEI	R0,inc_fila
	LD	R0,0(R0)
	ADD	R4,R2,R0
	ST	0(R1),R4

	$MOVEI	R1,columna
	LD	R2,0(R1)
	OUT	Rcol_pant, R2    ;out columna ; columna+=inc_columna
	$MOVEI	R0,inc_columna
	LD	R0,0(R0)
	ADD	R5,R2,R0
	ST	0(R1),R5

	$MOVEI	R0, ' 
	OUT	Rdat_pant,R0
	$MOVEI	R0, 0xFFFF
	OUT	Rcon_pant,R0

	;R4 = fila, R5 = columna
	ADDI	R0,R4,1
	BZ	R0,fi_programa   ; fila == -1 or columna == -1
	ADDI	R0,R5,1
	BZ	R0,fi_programa

	ADDI	R0,R4,-16
	BZ	R0,fi_programa   ; fila == 16 or columna == 64
	ADDI	R0,R5,-32
	ADDI	R0,R0,-32
	BZ	R0,fi_programa

	OUT	Rfil_pant, R4
	OUT	Rcol_pant, R5
	$MOVEI	R0,'X
	OUT	Rdat_pant,R0
	$MOVEI	R0,0xFFFF
	OUT	Rcon_pant,R0


fi_rel:	JMP	R6

fi_programa:
	HALT
	

main:

	$MOVEI	R0, interrupts_vector
	$MOVEI	R1, rellotge
	ST	0(R0),R1

	$MOVEI	R1, teclat
	ST	2(R0),R1

	MOVI	R0,1
	OUT	Rcon_rel,R0
	OUT	Rcon_tec,R0

	EI

	MOVI	R0,0
bucle:	BZ	R0, bucle

	HALT

