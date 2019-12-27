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
	// Port P2
	pbyReg = (BYTE far *)MK_FP(RSEG, PMC2);
	*pbyReg = 0x00;	//PMC2 = '00' -> mode port I/O
	--pbyReg;		//apuntar a PM2
	*pbyReg = 0x00;	//PM2 = '00' -> port 2 de sortida
	--pbyReg;		//apuntar a P2
	*pbyReg = 0x00;	//P2 = '00' -> port 2 valor inicial

   // Port 1
	pbyReg = (BYTE far *)MK_FP(RSEG, PMC1);
	*pbyReg = 0x00;	//PMC1 = '00' -> mode port I/O
	--pbyReg;		//apuntar a PM1
	*pbyReg = 0x00;	//PM1 = '00' -> port 1 de sortida
	--pbyReg;		//apuntar a P1
	*pbyReg = 0x00;	//P1 = '00' -> port 1 valor inicial

   // Port 0
	pbyReg = (BYTE far *)MK_FP(RSEG, PMC0);
	*pbyReg = 0x00;	//PMC0 = '00' -> mode port I/O
	--pbyReg;		//apuntar a PM0
	*pbyReg = 0x00;	//PM0 = '00' -> port 0 de sortida
	--pbyReg;		//apuntar a P0
	*pbyReg = 0x00;	//P0 = '00' -> port 0 valor inicial

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

// Treure valor per P1
void SetP1(BYTE byVal) {
	BYTE far *pbyP1;	//punter al port
	pbyP1 = (BYTE far *)MK_FP(RSEG, P1);
   *pbyP1 &= ~(0x70);
	*pbyP1 |= byVal;
}


// Treure valor per P0
void SetP0(BYTE byVal) {
	BYTE far *pbyP0;	//punter al port

	//crear el punter al registre P2
	pbyP0 = (BYTE far *)MK_FP(RSEG, P0);
	*pbyP0 = byVal;	//P2 = byVal
}


// Llegeix PT
BYTE GetPT(void) {
	BYTE far *pbyPT;	//punter al port

	//crear el punter al registre PT
	pbyPT = (BYTE far *)MK_FP(RSEG, PT);
	return(*pbyPT);	//valor PT
}
