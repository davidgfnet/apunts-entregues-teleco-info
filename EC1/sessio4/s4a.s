; Apartat 4.A
.include "macros.s"
.include "crt0.s"

; Afegeix aqui les variables globals addicionals que necessitis
	.data



; Afegeix aqui el codi del programa
	.text
main:

	$MOVEI	R0, 3
	OUT	Rfil_pant, R0
	$MOVEI	R0, 7
	OUT	Rcol_pant, R0
	$MOVEI	R0, 'A + 256
	OUT	Rdat_pant, R0
	$MOVEI	R0, 0xFFFF
	OUT	Rcon_pant, R0

	$MOVEI	R0, 8
	OUT	Rcol_pant, R0
	$MOVEI	R0, 'B
	OUT	Rdat_pant, R0
	$MOVEI	R0, 0xFFFF
	OUT	Rcon_pant, R0
	
	HALT
