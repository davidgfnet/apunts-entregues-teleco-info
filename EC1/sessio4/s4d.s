; Apartat 4.D
.include "macros.s"
.include "crt0.s"

; Afegeix aqui les variables globals addicionals que necessitis
	.data
w:  .word 0xFFF9


; Afegeix aqui el codi del programa
	.text
		
main:
	$MOVEI	R1, w
	LD	R1, 0(R1)
	$CALL	R6, mostra

	$MOVEI	R4, w
	LD	R5, 0(R4)

espera:
	IN	R0, Rest_tec
	BZ	R0, espera

	IN	R0, Rdat_tec
	$MOVEI	R1, tteclat
	ADD	R0, R0, R1
	LDB	R1, 0(R0)

	$MOVEI	R2, 'A
	CMPEQ	R0, R1, R2
	BNZ	R0, es_a

	$MOVEI	R2, 'B
	CMPEQ	R0, R1, R2
	BNZ	R0, es_b

	$MOVEI	R2, 'C
	CMPEQ	R0, R1, R2
	BNZ	R0, es_c

	$MOVEI	R2, 'D
	CMPEQ	R0, R1, R2
	BNZ	R0, es_d

	$MOVEI	R2, '0
	$CMPGE	R0, R1, R2
	$MOVEI	R2, '9
	$CMPLE	R3, R1, R2
	AND	R0, R0, R3
	BNZ	R0, es_num

	XOR	R0,R0,R0
	BZ	R0, endif  ; cap tecla valida

es_a:	
	MOVI	R0, 1
	SHL	R5, R5, R0
	ST	0(R4),R5
	BNZ	R0, endif

es_b:	
	MOVI	R0, -1
	SHL	R5, R5, R0
	ST	0(R4),R5
	BNZ	R0, endif

es_c:
	MOVI	R0, 1
	SHA	R5, R5, R0
	ST	0(R4),R5
	BNZ	R0, endif

es_d:
	MOVI	R0, 2
	DIV	R5, R5, R0
	ST	0(R4),R5
	BNZ	R0, endif

es_num:
	MOVI	R0, 1
	$MOVEI	R3, '0
	SUB	R1, R1, R3
	SHL	R0, R0, R1
	ADDI	R0,R0,-1
	XOR	R5,R5,R0
	ST	0(R4),R5

endif:
	

	XOR	R0,R0,R0
	BZ	R0, main

	HALT
    



mostra:
	MOVI	R0,0
	OUT	Rfil_pant, R0
	$MOVEI	R3, 0x8000

bucle:
	AND	R2,R1,R3
	$MOVEI	R5, '0
	BZ	R2, zero
	$MOVEI	R5, '1
zero:	OUT	Rcol_pant, R0
	OUT	Rdat_pant, R5
	$MOVEI	R4, -1
	OUT	Rcon_pant, R4
	SHL	R3,R3,R4
	ADDI	R0,R0,1
	BNZ	R3, bucle
	JMP	R6




    
