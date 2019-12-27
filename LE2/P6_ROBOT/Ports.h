/////////////////////////////////
// CISE4
// Leds_1.axe: Projecte de configuració.
// v1.0 - (c)2001 DEE-UPC
// Ports.h: Capçalera de Ports.c
/////////////////////////////////

#if !defined(__PORTS_H)
#define	__PORTS_H

//definició de les funcions del mòdul Ports

void IniPorts(void);		//config ports
void SetP2(BYTE);		//escriure al P2
BYTE GetPT(void);		//llegir del PT

#endif

