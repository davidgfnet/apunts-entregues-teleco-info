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

// Inicialització dels ports P0,P1,P2,PT
void IniPorts(void) {
	BYTE far *pbyReg;	//punter a un registre
	// Port P2
	pbyReg = (BYTE far *)MK_FP(RSEG, PMC2);
	*pbyReg = 0x00;	//PMC2 = '00' -> mode port I/O
	--pbyReg;		//apuntar a PM2
	*pbyReg = 0x00;	//PM2 = '00' -> port 2 de sortida
	--pbyReg;		//apuntar a P2
	*pbyReg = 0x00;	//P2 = '00' -> port 2 valor inicial

	// Port 1
	pbyReg = (BYTE far *)MK_FP(RSEG, PMC1);
	*pbyReg = 0x00;
	--pbyReg;
	*pbyReg = 0x00;
	--pbyReg;
	*pbyReg = 0x00;

	// Port 0
	pbyReg = (BYTE far *)MK_FP(RSEG, PMC0);
	*pbyReg = 0x00;
	--pbyReg;
	*pbyReg = 0x00;
	--pbyReg;
	*pbyReg = 0x00;

	//config PT
	pbyReg = (BYTE far *)MK_FP(RSEG, PMT);
	*pbyReg = 0x08;	//llindar entrades PT a 1.25V
}

void SetP2(BYTE byVal) {
	BYTE far *pbyP2;
	pbyP2 = (BYTE far *)MK_FP(RSEG, P2);
	*pbyP2 = byVal;
}

void SetP1(BYTE byVal) {
	BYTE far *pbyP1;	pbyP1 = (BYTE far *)MK_FP(RSEG, P1);
	*pbyP1 = byVal;
}

void SetP0(BYTE byVal) {
	BYTE far *pbyP0;
	pbyP0 = (BYTE far *)MK_FP(RSEG, P0);
	*pbyP0 = byVal;
}

BYTE GetPT(void) {
	BYTE far *pbyPT;
	pbyPT = (BYTE far *)MK_FP(RSEG, PT);
	return(*pbyPT);
}
