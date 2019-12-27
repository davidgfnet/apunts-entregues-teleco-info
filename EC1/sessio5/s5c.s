; Apartat 5.C
.include "macros.s"
.include "crt0.s"

; Afegeix aqui les variables globals addicionals que necessitis
	.data
frase:	.asciz	"Aquest programa funciona"		; 25 bytes
	.fill	7, 1, 0					; els 7 bytes restants
clock:	.word 	0
car:	.word	0
impres:	.word	0


; Afegeix aqui el codi del programa
	.text
rellotge:
	$MOVEI	R0, clock
	LD	R1, 0(R0)
	ADDI	R1,R1,1		;clock ++
	ST	0(R0),R1

	ADDI	R5,R1,-10	; clock == 10 ?
	BNZ	R5,fi_rel

	MOVI	R1,0
	ST	0(R0),R1	;clock = 0

	OUT	Rcon_rel,R1	;disable clock

espera_imp:
	IN	R5,Rest_imp
	BZ	R5, espera_imp

	$MOVEI	R2, frase
	$MOVEI	R3, car
	LD	R4, 0(R3)
	ADD	R5, R2, R4
	LDB	R0,0(R5)	;R0 = frase[car]
	OUT	Rdat_imp, R0
	$MOVEI	R0,0xFFFF
	OUT	Rcon_imp, R0

	ADDI	R4,R4,1
	ST	0(R3),R4	; car++
	LDB	R0,1(R5)	; frase[car+1]
	BNZ	R0, fi_rel
	
	;frase[car+1]==\0
	$MOVEI	R0, impres
	MOVI	R1, 1
	ST	0(R0),R1  ;impres = 1
	

fi_rel:	JMP	R6

impresora:
	MOVI	R0,1
	OUT	Rcon_rel,R0

	$MOVEI	R0,impres
	LD	R0,0(R0)
	BZ	R0, sortir_imp

	HALT	;s'ha impres tot el que era necessari
	

sortir_imp:
	JMP	R6

main:
	$MOVEI	R0, interrupts_vector
	$MOVEI	R1, rellotge
	ST	0(R0),R1

	$MOVEI	R1, impresora
	ST	14(R0),R1

	MOVI	R0,1
	OUT	Rcon_rel,R0
	OUT	Rcon_imp,R0

	EI

	MOVI	R0,0
bucle:	BZ	R0, bucle

	HALT





