/////////////////////////////////
// CISE4
// Leds_1.axe: Projecte de configuraci�.
// v1.0 - (c)2001 DEE-UPC
// Ports.h: Cap�alera de Ports.c
/////////////////////////////////

#if !defined(__PORTS_H)
#define	__PORTS_H

//definici� de les funcions del m�dul Ports

void IniPorts(void);		//config ports
void SetP2(BYTE);		//escriure al P2
BYTE GetPT(void);		//llegir del PT

#endif

