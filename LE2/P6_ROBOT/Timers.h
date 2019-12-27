/////////////////////////////////
// CISE4
// Leds_1.axe: Projecte de configuració.
// v1.0 - (c)2001 DEE-UPC
// Timers.h: Capçalera de Timers.c
/////////////////////////////////

#if !defined(__TIMERS_H)
#define	__TIMERS_H

#define APROX10S	4900	//ticks per a 10 seg.

//definició de les funcions del mòdul Timers

void IniTimers(void);			//config timers
void Retard(int);			//retard genèric en ticks
void interrupt RSIBaseTemps(void);	//RSI de la base de temps
void InicialitzaSerie();		// config del serie

#endif

