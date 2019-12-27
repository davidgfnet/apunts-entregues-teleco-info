; Apartat 4.B
.include "macros.s"
.include "crt0.s"

; Afegeix aqui les variables globals addicionals que necessitis
	.data



; Afegeix aqui el codi del programa
	.text
main:
	IN	R0, Rest_tec
	BZ	R0, main

	; S'ha pitjat una tecla:

	$MOVEI	R0, 3
	OUT	Rfil_pant, R0
	$MOVEI	R0, 7
	OUT	Rcol_pant, R0

	IN	R0, Rdat_tec
	$MOVEI	R1, tteclat
	ADD	R0, R0, R1
	LDB	R0, 0(R0)
	OUT	Rdat_pant, R0
	$MOVEI	R0, 0xFFFF
	OUT	Rcon_pant, R0

	HALT
