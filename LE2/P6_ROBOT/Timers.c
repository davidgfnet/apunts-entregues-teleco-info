/////////////////////////////////
// CISE4
// Leds_1.axe: Projecte de configuració.
// v1.0 - (c)2001 DEE-UPC
// Timers.c: Programa de config dels temporitzadors
/////////////////////////////////

#include <embedded.h>

#include "typedefs.h"
#include "int.h"
#include "register.h"
#include "timers.h"	//funcions de control dels temporitzadors
#include "mis_includes.h"

// Variables globals
int n_codivalid = 0;
int iTick;		//control del pas per la RSI de la base de temps
int contador = 0;
int encendido = 0;
BYTE posicion = 1;

void interrupt RSITimer0(void);
void interrupt RSITimer1(void);

BYTE far *pbyReg;

//// CANVIS
BYTE cicle_treball = 0;

// Inicialització dels temporitzadors
// (actualment, només la base de temps)
void IniTimers(void) {
	BYTE far *pbyReg;	//punter a un registre
	WORD far *pwoReg;	//punter a un registre

	//substituir el vector d'interrupció de la base de temps
	disable();		//no permetre cap INT
	setvect(INTBASETEMPS, RSIBaseTemps);
	enable();

	//crear el punter al registre de control del processador PRC
	pbyReg = (BYTE far *)MK_FP(RSEG, PRC);

	//modificar el registre PRC per a una int cada 2.05 ms
	*pbyReg = 0x04;	//RAM interna deshabilitada
						//Fclk de 4 MHz

	//apuntar al registre TBIC
	pbyReg = (BYTE far *)MK_FP(RSEG, TBIC);
	*pbyReg &= 0xBF;	//activar interrupcions BT
	//   *pbyReg |= ~(0xBF);	//activar interrupcions BT

	// Iniciarel timer 0
	pbyReg = (BYTE far *)MK_FP(RSEG, MD0);
	pbyReg[0] = 0;
	pbyReg[1] = 13;

	pbyReg = (BYTE far *)MK_FP(RSEG, TMC0);
	*pbyReg = 0x80 | 0x40;


	disable();
	setvect(INTCOUNTER0, RSITimer0);
	enable();

	pbyReg = (BYTE far *)MK_FP(RSEG, TMIC0);
	*pbyReg &= 0xBF;	//activar interrupcions timer0


//// CANVIS /////////
	// Iniciarel timer 1
	pbyReg = (BYTE far *)MK_FP(RSEG, MD1);
	pbyReg[0] = 0;
	pbyReg[1] = 3;  // cada 24.5ms. Volem cicle de treball 25%
// T = 3*256/(4000000/128)

	pbyReg = (BYTE far *)MK_FP(RSEG, TMC1);
	*pbyReg = 0x80 | 0x40;

	disable();
	setvect(INTCOUNTER2, RSITimer1);
	enable();

	pbyReg = (BYTE far *)MK_FP(RSEG, TMIC2);
	*pbyReg &= 0xBF;	//activar interrupcions timer1
//// FI CANVIS /////////
}

void InicialitzaSerie() {
	BYTE far *pbyReg;

	pbyReg = (BYTE far *)MK_FP(RSEG, SCM0);   // Registre de descripció del senyal
	*pbyReg = BIT3 | BIT6 | BIT0;   // 8 bits de dades + recepció enabled  (no paritat , 1 bit stop)
					// MOLT IMPORTANT el BIT0 per activar mode ASINCRON

	pbyReg = (BYTE far *)MK_FP(RSEG, SCE0);   // Registre de control de errors
	*pbyReg = 0;  // Tots els errors capats + NO transmissió

	pbyReg = (BYTE far *)MK_FP(RSEG, SEIC0);   // Registre de control de d'interrupció d'errors
	*pbyReg = 0;  // No volem petició d'error

	pbyReg = (BYTE far *)MK_FP(RSEG, SRIC0);   // Registre de control de d'interrupció de transmissió completada
	*pbyReg = 0;  // No volem petició d'error

	pbyReg = (BYTE far *)MK_FP(RSEG, SRIC0);   // Registre de control de d'interrupció de recepció completada. Este SI!
	*pbyReg = BIT7;  // Volem petició

	disable();
	setvect(INTSRX0, RSIRecepcio0);
	enable();
}

void interrupt RSIRecepcio0 (void) {
	disable();
	// Tractar recepció de dades! La dada esta a RxB0
	BYTE far *pbyReg;
	pbyReg = (BYTE far *)MK_FP(RSEG,  RxB0);   // Dada!
	BYTE dada = *pbyReg;
	if ( (dada & 0x0F) == 0x0F) {  // Els 4 primers bits d'stop son correctes??
		dada = dada >> 4;
		switch (dada) {
		case ABRIR_PINZA:
			pinza_abrir; break;
		case CERRAR_PINZA:
			pinza_cerrar; break;
		case DELANTE:
			movh_delante; break;
		case ATRAS:
			movh_atras; break;
		case ARRIBA:
			movv_arriba; break;
		case ABAJO:
			movv_abajo; break;
		case ANTIHORARIO:
			rot_antihorario; break;
		case HORARIO:
			rot_horario; break;
		default:
			goto CODI_NO_VALID;
			break;
		}
		// Codi valid, anotar que el robot ha de seguir girant els proxims 40ms;
		n_codivalid = 0;
	}
CODI_NO_VALID:
	FINT;
}
// Servei d'interrupció de la base de temps
void interrupt RSIBaseTemps(void) {
	enable();	//permetre altres INT.
	FINT;
}


void interrupt RSITimer1(void) {
	enable();	//permetre altres INT.

///// CANVIS //////
	if (reproduir == 1) {  // Modular la sortida amb tren de polsos de cicle de treball 25%
		if (cicle_treball == 0) {
			SetP2(paraula_moviment);   // Movem 25%
		}else{
			parar_todo;                // Parem 75%
		}
		cicle_treball = (cicle_treball+1) % 4;  // de 0 a 3
	}
/// FI CANVIS

	FINT;
}

void interrupt RSITimer0(void) {
	enable();	//permetre altres INT.
	// Aquesta rutina s'encarrega de parar el motor si no s'ha apretat cap tecla!
	if (n_codivalid >= 2) {
		parar_todo;  // to's quietos
	}else{
		n_codivalid++;
	}
	FINT;
}

