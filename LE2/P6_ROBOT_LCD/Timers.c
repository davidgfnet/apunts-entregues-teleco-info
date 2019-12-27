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
int contador = 0;
int encendido = 0;
int contador_lcd = 0;
BYTE posicion = 1;
extern BYTE no_show;

void interrupt RSITimer0(void);
void interrupt RSITimer1(void);
void interrupt RSIRecepcio0 (void);

BYTE far *pbyReg;
BYTE cicle_treball[4];
BYTE cont_treball[4];

extern BYTE moviment;
extern BYTE reset;
extern BYTE reproduir;
extern struct posicio posicio_actual;
extern struct posicio vector_posicions[32];
extern BYTE proxima_posicio_gravar;
extern BYTE paraula_moviment;
extern BYTE cont_pinca, cont_posh , cont_posv , cont_rot ;
extern BYTE moviment_1, moviment_2, moviment_3, moviment_4;
BYTE almacenado = 0;


// Inicialització dels temporitzadors
void IniTimers(void) {
	BYTE far *pbyReg;	//punter a un registre
	WORD far *pwoReg;	//punter a un registre

	disable();		// no permetre cap interrupció

	setvect(INTBASETEMPS, RSIBaseTemps);
	pbyReg = (BYTE far *)MK_FP(RSEG, PRC);
	*pbyReg = 0x04;		//Fclk de 4 MHz
	pbyReg = (BYTE far *)MK_FP(RSEG, TBIC);
	*pbyReg &= 0xBF;	//activar interrupcions BT

	// Iniciarel timer 0
	pwoReg = (WORD far *)MK_FP(RSEG, MD1);
	*pwoReg = 512;

	pbyReg = (BYTE far *)MK_FP(RSEG, TMC0);
	*pbyReg = 0x80 | 0x40;

	setvect(INTCOUNTER0, RSITimer0);

	pbyReg = (BYTE far *)MK_FP(RSEG, TMIC0);
	*pbyReg &= 0xBF;	//activar interrupcions timer0

	// Iniciarel timer 1
	pwoReg = (WORD far *)MK_FP(RSEG, MD1);
	*pwoReg = 128;

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
	*pbyReg = BIT3 | BIT6 | BIT0;
	// 8 bits de dades + recepció enabled  (no paritat , 1 bit stop)
	// MOLT IMPORTANT el BIT0 per activar mode ASINCRON

	pbyReg = (BYTE far *)MK_FP(RSEG, SCE0);   // Registre de control de errors
	*pbyReg = 0;  // Tots els errors capats + NO transmissió

	// Registre de control de d'interrupció d'errors
	pbyReg = (BYTE far *)MK_FP(RSEG, SEIC0);
	*pbyReg = 0;  // No volem petició d'error

	// Registre de control de d'interrupció de transmissió completada
	pbyReg = (BYTE far *)MK_FP(RSEG, SRIC0);
	*pbyReg = 0;  // No volem petició d'error

	// Registre de control de d'interrupció de recepció completada.
	pbyReg = (BYTE far *)MK_FP(RSEG, SRIC0);
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

BYTE decide_signo(BYTE valor, BYTE medio) {
 	if(valor > medio) return -1;
	return 1;
}

void interrupt RSIRecepcio0 (void) {
	BYTE j,dada;
	disable();

	if (reproduir == 0) {

		// Tractar recepció de dades! La dada esta a RxB0
		pbyReg = (BYTE far*)MK_FP(RSEG,  RxB0);   // Dada!
		dada = *pbyReg;
		if ( (dada & 0xF0) == 0xF0) {  // Els 4 primers bits d'stop son correctes??
			dada = dada & 0x0F;
			moviment_1 = 0; moviment_2 = 0; moviment_3 = 0; moviment_4 = 0;
			switch (dada) {
			case ABRIR_PINZA:
				moviment_4 = -1; almacenado=0;
				parar_todo; pinza_abrir; break;
			case CERRAR_PINZA:
				moviment_4 = 1; almacenado=0;
				parar_todo; pinza_cerrar; break;
			case DELANTE:
				moviment_2 = 1; almacenado=0;
				parar_todo; movh_delante; break;
			case ATRAS:
				moviment_2 = -1; almacenado=0;
				parar_todo; movh_atras; break;
			case ARRIBA:
				moviment_3 = -1; almacenado=0;
				parar_todo; movv_arriba; break;
			case ABAJO:
				moviment_3 = 1; almacenado=0;
				parar_todo; movv_abajo; break;
			case ANTIHORARIO:
				moviment_1 = -1; almacenado=0;
				parar_todo; rot_antihorario; break;
			case HORARIO:
				moviment_1 = 1; almacenado=0;
				parar_todo; rot_horario; break;
			case INICIO:
				almacenado=0; reset = 1; parar_todo; break;
			case REPRODUCIR:
				almacenado=0; paraula_moviment=0xFF; reproduir = 1;
				parar_todo; break;
			case ALMACENAR:
			      	if (almacenado==1) break;
			        almacenado=1;
				if (proxima_posicio_gravar >= MAX_ALMACENAR) {
  					contador_lcd=0;
					no_show = 1;
					escriu_frase("Cua plena!");
					break;  // No n'hi caben més!
		         	}
				vector_posicions[proxima_posicio_gravar] = posicio_actual;   // Guardar la posició
				vector_posicions[proxima_posicio_gravar].rotacio += decide_signo(vector_posicions[proxima_posicio_gravar].rotacio,115)*MARGE_ERROR;
				vector_posicions[proxima_posicio_gravar].pos_pinca += decide_signo(vector_posicions[proxima_posicio_gravar].pos_pinca,15)*MARGE_ERROR;
				vector_posicions[proxima_posicio_gravar].pos_horit += decide_signo(vector_posicions[proxima_posicio_gravar].pos_horit,90)*MARGE_ERROR;
				vector_posicions[proxima_posicio_gravar].pos_vert += decide_signo(vector_posicions[proxima_posicio_gravar].pos_vert,55)*MARGE_ERROR;
				proxima_posicio_gravar++;
				contador_lcd=0;
				no_show = 1;
				escriu_frase("Moviment guardat");
				parar_todo; break;
			case BORRAR:
				almacenado=0;
				proxima_posicio_gravar = 0;
				contador_lcd=0;
				no_show = 1;
				escriu_frase("Tot borrat");
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
	disable();
	contador_lcd++;	if (contador_lcd > TEMPS_MISSATGE) no_show=0;	enable();
	FINT;
}

void interrupt RSITimer1(void) {
	BYTE temp2,j;
	disable();	//permetre altres INT.

	if (reproduir == 1) {  // Modular la sortida amb tren de polsos de cicle de treball 25%
		temp2 = paraula_moviment;
		for (j = 0; j < 4; j++) {
		   if (cont_treball[j] != 0) {
		      temp2 |= (0x3 << (2*j));
		   }
		}
		SetP2(temp2);
		for (j = 0; j < 4; j++) cont_treball[j] = (cont_treball[j]+1) % cicle_treball[j];
	}
	enable();
	FINT;
}

void interrupt RSITimer0(void) {
	BYTE dada;
	disable();

	/// Comptapassos mostrejat a la freq del timer
	dada = GetPT();

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

