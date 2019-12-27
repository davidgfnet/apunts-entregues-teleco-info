/////////////////////////////////
// CISE4
// Leds_1.axe: Projecte de configuració.
// v1.0 - (c)2001 DEE-UPC
// Ports.c: Programa de config i control dels ports
/////////////////////////////////

#include <embedded.h>

#include "register.h"
#include "typedefs.h"
#include "ports.h"	//funcions de control dels ports
#include "mis_includes.h"

// Inicialització dels ports
// (actualment, només P2 i PT)
void IniPorts(void) {
	BYTE far *pbyReg;	//punter a un registre
	//crear el punter als registres de control
	pbyReg = (BYTE far *)MK_FP(RSEG, PMC2);
	*pbyReg = 0x00;	//PMC2 = '00' -> mode port I/O
	--pbyReg;		//apuntar a PM2
	*pbyReg = 0x00;	//PM2 = '00' -> port 2 de sortida
	--pbyReg;		//apuntar a P2
	*pbyReg = 0x00;	//P2 = '00' -> port 2 valor inicial

	//config PT
	pbyReg = (BYTE far *)MK_FP(RSEG, PMT);
	*pbyReg = 0x08;	//llindar entrades PT a 1.25V
}

// Treure valor per P2
void SetP2(BYTE byVal) {
	BYTE far *pbyP2;	//punter al port

	//crear el punter al registre P2
	pbyP2 = (BYTE far *)MK_FP(RSEG, P2);
	*pbyP2 = byVal;	//P2 = byVal
}

// Llegeix PT
BYTE GetPT(void) {
	BYTE far *pbyPT;	//punter al port

	//crear el punter al registre PT
	pbyPT = (BYTE far *)MK_FP(RSEG, PT);
	return(*pbyPT);	//valor PT
}
