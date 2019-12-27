; Apartat 5.A
.include "macros.s"
.include "crt0.s"

; Afegeix aqui les variables globals addicionals que necessitis
	.data
clock:	.word	0


; Afegeix aqui el codi del programa
	.text
rellotge:
	$MOVEI	R0, clock
	LD	R1, 0(R0)
	ADDI	R1, R1, 1
	ST	0(R0),R1
	
	ADDI	R1, R1, -20
	ADDI	R1, R1, -30
	BNZ	R1, fi_rellotge

	MOVI	R0, 4
	OUT	Rfil_pant, R0
	MOVI	R0, 8
	OUT	Rcol_pant, R0
	$MOVEI	R0, 'A
	OUT	Rdat_pant, R0
	$MOVEI	R0, 0xFFFF
	OUT	Rcon_pant, R0

fi_rellotge:
	MOVI	R0,1
;	OUT	Rcon_rel, R0

	JMP R6

main:
	$MOVEI	R0, rellotge
	$MOVEI	R1, interrupts_vector
	ST	0(R1), R0


	MOVI	R0,1
	OUT	Rcon_rel, R0
	EI

bucle:	
	BNZ	R0, bucle

	HALT


