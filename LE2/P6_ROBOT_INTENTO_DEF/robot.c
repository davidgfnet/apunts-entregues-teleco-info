/////////////////////////////////
// LAB II
// Robot.axe: Projecte de configuració.
// v1.0 - (c)2001 DEE-UPC
// Robot.c:Programa principal del projecte  
/////////////////////////////////

#include <embedded.h>

#include "typedefs.h"
#include "register.h"
#include "timers.h"	//funcions de control dels temporitzadors
#include "ports.h"	//funcions de control dels ports

#include "mis_includes.h"
BYTE estat_P2 = 0x00;
BYTE status;
BYTE reset = 1;

BYTE reproduir = 0;  // SI es 0, mode normal, 1 mode reproduccio!

#define MAX_ALMACENAR 32
// Identifica una posició!
struct posicio {
	BYTE pos_pinca;
	BYTE pos_horit;
	BYTE pos_vert;
	BYTE rotacio;
};
posicio posicio_actual;            // S'actualitza sola indicant la posicio del robot! Cal posarla a 0 al fer un reset!
posicio vector_posicions[MAX_ALMACENAR];      // Llista de posicions a guardar!
BYTE proxima_posicio_gravar = 0;   // Indica la proxima posició que es gravara al pulsar gravar
				   // Per a borrar les dades només cal posarla a 0.
				   // Si és 0 també sabem que no hi ha res gravat.
BYTE paraula_moviment;		   // Indica l'estat dels motors a cada instant al reproduir
BYTE cont_pinca = 0, cont_posh = 0, cont_posv = 0, cont_rot = 0; // TODO: Caldria inicialitzarlos despres de reset, potser valen 1 no? Depen del motor
BYTE moviment_1 = 0, moviment_2 = 0, moviment_3 = 0, moviment_4 = 0;
// Serà 1 si avancem (Tancar pinça, rot horari, endevant i avall) o -1 lo altre


BYTE calc_paraula_estat (BYTE num_motor, BYTE codi_estat, BYTE paraula) {
	BYTE mascara = (0x3 << 2*(num_motor-1));
	paraula &= ~(mascara);  // Netejem l'estat! El posem a 00
	paraula |= ( (codi_estat & 0x3) << 2*(num_motor-1) );  // Enmascarem el codi per si de cas for incorrecte!
	return paraula;
}

// Motor va de 1 a 4!
void motor_estat (BYTE num_motor, BYTE codi_estat) {
	estat_P2 = calc_paraula_estat(num_motor,codi_estat,estat_P2);

	SetP2(estat_P2);  // Escribim el port
}

// Torna quan el robot es troba a l'origen
void robot_inici() {
	pinza_abrir; rot_antihorario; movh_atras; movv_arriba;
	status = GetPT();
	while ( (status & 0x01) != 0 ) {status = GetPT();}  // Esperem mentre no estigui a l'origen
	parar_todo;

	posicio_actual.pos_pinca = 0;
	posicio_actual.pos_horit = 0;
	posicio_actual.pos_vert = 0;
	posicio_actual.rotacio = 0;
}

void InicialitzaLCD() {
	//SetP1(0x40); 	
}

void main() {
	IniPorts();    // Important iniciar els ports de I/O correctament

   InicialitzaLCD();

	InicialitzaSerie();  // Port serie!
        parar_todo;
	IniTimers();   // Inicial el timer
	enable();      // Permetem interrupcions!

	while (1) {
	   	if (reset == 1) {
			disable();  //Parem interrupcions per a fer el reset
			robot_inici();  ////// Comentar si veiem que la cosa no funciona, potser es queda aquí per sempre
			reset = 0;
			enable();
		}
		if (reproduir == 1) {  // mode reproducció!!!
			if (proxima_posicio_gravar != 0) {  // Comprovar que hi hagi alguna cosa a la llista de reproduccions!!! 
				parar_todo;  // Tots quiets!
				BYTE i;
				for (i = 0; i < proxima_posicio_gravar; i++) {
					paraula_moviment = 0xFF;
					while (paraula_moviment == 0xFF) {  
					// Ens quedem recalculant la paraula d'estat mentre no arribem  la seguent posicio
						paraula_moviment = 0xFF;
						// Calcular com han d'estar els motors, i revisar si s'ha assolit la posició!
						if (vector_posicions[i].pos_pinca > posicio_actual.pos_pinca) {  // Tancar la pinça
							paraula_moviment = calc_paraula_estat(4,0x1,paraula_moviment);
						}else if (vector_posicions[i].pos_pinca < posicio_actual.pos_pinca) {
							paraula_moviment = calc_paraula_estat(4,0x2,paraula_moviment);
						}

						if (vector_posicions[i].rotacio > posicio_actual.rotacio) {  // Moviment horari
							paraula_moviment = calc_paraula_estat(1,0x1,paraula_moviment);
						}else if (vector_posicions[i].rotacio < posicio_actual.rotacio) {
							paraula_moviment = calc_paraula_estat(1,0x2,paraula_moviment);
						}

						if (vector_posicions[i].pos_horit > posicio_actual.pos_horit) {  // Endevant
							paraula_moviment = calc_paraula_estat(2,0x1,paraula_moviment);
						}else if (vector_posicions[i].pos_horit < posicio_actual.pos_horit) {
							paraula_moviment = calc_paraula_estat(2,0x2,paraula_moviment);
						}

						if (vector_posicions[i].pos_vert > posicio_actual.pos_vert) {  // Avall
							paraula_moviment = calc_paraula_estat(3,0x1,paraula_moviment);
						}else if (vector_posicions[i].pos_vert < posicio_actual.pos_vert) {
							paraula_moviment = calc_paraula_estat(3,0x2,paraula_moviment);
						}
					}
				}
			}
			reproduir = 0;
		}
	}
}


