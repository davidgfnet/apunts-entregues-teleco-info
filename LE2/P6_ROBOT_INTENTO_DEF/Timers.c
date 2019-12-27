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
#include "ports.h"
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
void interrupt RSIRecepcio0 (void);

BYTE far *pbyReg;
BYTE dada;
BYTE cicle_treball = 0;

// Inicialització dels temporitzadors
// (actualment, només la base de temps)
void IniTimers(void) {
	BYTE far *pbyReg;	//punter a un registre
	WORD far *pwoReg;	//punter a un registre

	//substituir el vector d'interrupció de la base de temps
	disable();		//no permetre cap INT
	setvect(INTBASETEMPS, RSIBaseTemps);

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
	pbyReg[1] = 2;

	pbyReg = (BYTE far *)MK_FP(RSEG, TMC0);
	*pbyReg = 0x80 | 0x40;


	setvect(INTCOUNTER0, RSITimer0);

	pbyReg = (BYTE far *)MK_FP(RSEG, TMIC0);
	*pbyReg &= 0xBF;	//activar interrupcions timer0


	// Iniciarel timer 1
	pbyReg = (BYTE far *)MK_FP(RSEG, MD1);
	pbyReg[0] = 0;
	pbyReg[1] = 128;

	pbyReg = (BYTE far *)MK_FP(RSEG, TMC1);
	*pbyReg = 0x80 | 0x40;

	setvect(INTCOUNTER2, RSITimer1);

	pbyReg = (BYTE far *)MK_FP(RSEG, TMIC2);
	*pbyReg &= 0xBF;	//activar interrupcions timer1

	enable();
}

void InicialitzaSerie() {
	BYTE far *pbyReg;

	disable();

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

  	pbyReg = (BYTE far *)MK_FP(RSEG, BRG0);
	*pbyReg = 15;  // 512bauds

  	pbyReg = (BYTE far *)MK_FP(RSEG, SCC0);
	*pbyReg = 0x08;  // 512bauds


	setvect(INTSRX0, RSIRecepcio0);
	setvect(INTSERR0, RSIRecepcio0);
  	setvect(INTSTX0, RSIRecepcio0);
	enable();
}

extern BYTE reset;
void interrupt RSIRecepcio0 (void) {
	disable();

	if (reproduir == 0) {  

		// Tractar recepció de dades! La dada esta a RxB0
		pbyReg = (BYTE far*)MK_FP(RSEG,  RxB0);   // Dada!
		dada = *pbyReg;
		if ( (dada & 0xF0) == 0xF0) {  // Els 4 primers bits d'stop son correctes??
			dada = dada & 0x0F;
			switch (dada) {
			case ABRIR_PINZA:
				moviment_4 = -1;
				parar_todo; pinza_abrir; break;
			case CERRAR_PINZA:
				moviment_4 = 1;
				parar_todo; pinza_cerrar; break;
			case DELANTE:
				moviment_2 = 1;
				parar_todo; movh_delante; break;
			case ATRAS:
				moviment_2 = -1;
				parar_todo; movh_atras; break;
			case ARRIBA:
				moviment_3 = -1;
				parar_todo; movv_arriba; break;
			case ABAJO:
				moviment_3 = 1;
				parar_todo; movv_abajo; break;
			case ANTIHORARIO:
				moviment_1 = -1;
				parar_todo; rot_antihorario; break;
			case HORARIO:
				moviment_1 = 1;
				parar_todo; rot_horario; break;
			case INICIO:
				reset = 1; parar_todo; break;
			case REPRODUCIR:
				reproduir = 1;
				parar_todo; break;
			case ALMACENAR:
				if (proxima_posicio_gravar >= MAX_ALMACENAR) break;  // No n'hi caben més!
				vector_posicions[proxima_posicio_gravar] = posicio_actual;   // Guardar la posició
				proxima_posicio_gravar++;
				parar_todo; break;
			case BORRAR:
				proxima_posicio_gravar = 0;  // simple ;)
				parar_todo; break;
			default:
				goto CODI_NO_VALID;
				break;
			}
			// Codi valid, anotar que el robot ha de seguir girant els proxims 40ms;
			n_codivalid = 0;
		}
	}
CODI_NO_VALID:
	enable();
	FINT;
}
// Servei d'interrupció de la base de temps
void interrupt RSIBaseTemps(void) {
	enable();	//permetre altres INT.
	FINT;
}

extern posicio posicio_actual;
extern BYTE moviment;

void interrupt RSITimer1(void) {
	disable();	//permetre altres INT.

	if (reproduir == 1) {  // Modular la sortida amb tren de polsos de cicle de treball 25%
		if (cicle_treball == 0) {
			SetP2(paraula_moviment);   // Movem 25%
		}else{
			parar_todo;                // Parem 75%
		}
		cicle_treball = (cicle_treball+1) % 4;  // de 0 a 3
	}
	enable();
	FINT;
}

void interrupt RSITimer0(void) {
	disable();	//permetre altres INT.

	/// Comptapassos mostrejat a 20ms aprox
	dada = GetPT();
	// Flanc baxada Motor1 
	if ( ((dada & BIT1) == 0) && cont_rot == 1) { cont_rot=0; posicio_actual.rotacio+=moviment_1; }
	if ( ((dada & BIT1) != 0) && cont_rot == 0) { cont_rot=1; posicio_actual.rotacio+=moviment_1; }

	if ( ((dada & BIT2) == 0) && cont_posh == 1) { cont_posh=0; posicio_actual.pos_horit+=moviment_2; }
	if ( ((dada & BIT2) != 0) && cont_posh == 0) { cont_posh=1; posicio_actual.pos_horit+=moviment_2; }

	if ( ((dada & BIT3) == 0) && cont_posv == 1) { cont_posv=0; posicio_actual.pos_vert+=moviment_3; }
	if ( ((dada & BIT3) != 0) && cont_posv == 0) { cont_posv=1; posicio_actual.pos_vert+=moviment_3; }

	if ( ((dada & BIT4) == 0) && cont_pinca == 1) { cont_pinca=0; posicio_actual.pos_pinca+=moviment_4; }
	if ( ((dada & BIT4) != 0) && cont_pinca == 0) { cont_pinca=1; posicio_actual.pos_pinca+=moviment_4; }

	if (reproduir == 0) {  // Només si estem en mode normal		// Aquesta rutina s'encarrega de parar el motor si no s'ha apretat cap tecla!
		if (n_codivalid >= 2) {
			parar_todo;  // to's quietos
		}else{
			n_codivalid++;
		}
	}

	enable();   
	FINT;
}

