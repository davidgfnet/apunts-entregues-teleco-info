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

/// CANVIS
BYTE reproduir = 0;  // SI es 0, mode normal, 1 mode reproduccio!

// Identifica una posició!
struct posicio {
	BYTE pos_pinca;
	BYTE pos_horit;
	BYTE pos_vert;
	BYTE rotacio;
};
posicio posicio_actual;            // S'actualitza sola indicant la posicio del robot! Cal posarla a 0 al fer un reset!
posicio vector_posicions[32];      // Llista de posicions a guardar!
BYTE proxima_posicio_gravar = 0;   // Indica la proxima posició que es gravara al pulsar gravar
				   // Per a borrar les dades només cal posarla a 0.
				   // Si és 0 també sabem que no hi ha res gravat.
BYTE paraula_moviment;		   // Indica l'estat dels motors a cada instant al reproduir

BYTE calc_paraula_estat (BYTE num_motor, BYTE codi_estat, BYTE paraula) {
	BYTE mascara = (0x3 << 2*(num_motor-1));
	paraula &= ~(mascara);  // Netejem l'estat! El posem a 00
	paraula |= ( (codi_estat & 0x3) << 2*(num_motor-1) );  // Enmascarem el codi per si de cas for incorrecte!
	return paraula;
}
/////


// Motor va de 1 a 4!
void motor_estat (BYTE num_motor, BYTE codi_estat) {
//	BYTE mascara = (0x3 << 2*(num_motor-1));
//	estat_P2 &= ~(mascara);  // Netejem l'estat! El posem a 00
//	estat_P2 |= ( (codi_estat & 0x3) << 2*(num_motor-1) );  // Enmascarem el codi per si de cas for incorrecte!
	estat_P2 = calc_paraula_estat(num_motor,codi_estat,estat_P2);

	SetP2(estat_P2);  // Escribim el port
}

// Torna quan el robot es troba a l'origen
void robot_inici() {
	pinza_abrir; rot_antihorario; movh_atras; movv_arriba;
	BYTE status = GetPT();
	while ( (status & 0x01) != 0 ) {}  // Esperem mentre no estigui a l'origen
	parar_todo;
// CANVISS
	posicio_actual.pos_pinca = 0;
	posicio_actual.pos_horit = 0;
	posicio_actual.pos_vert = 0;
	posicio_actual.rotacio = 0;
}

void main() {
	IniPorts();    // Important iniciar els ports de I/O correctament

	robot_inici();  ////// Comentar si veiem que la cosa no funciona, potser es queda aquí per sempre

	InicialitzaSerie();  // Port serie!
	IniTimers();   // Inicial el timer
	enable();      // Permetem interrupcions!

// MODIFICACIONS SENSE RESET, afegir
	while (1) {
		if (reproduir == 1) {  // mode reproducció!!!
			if (proxima_posicio_gravar != 0) {  // Comprovar que hi hagi alguna cosa a la llista de reproduccions!!! 
				parar_todo;  // Tots quiets!
				BYTE i;
				for (i = 0; i < proxima_posicio_gravar; i++) {
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
						}else if (vector_posicions[i].pos_pinca < posicio_actual.pos_pinca) {
							paraula_moviment = calc_paraula_estat(1,0x2,paraula_moviment);
						}

						if (vector_posicions[i].pos_pinca > posicio_actual.pos_pinca) {  // Tancar la pinça
							paraula_moviment = calc_paraula_estat(4,0x1,paraula_moviment);
						}else if (vector_posicions[i].pos_pinca < posicio_actual.pos_pinca) {
							paraula_moviment = calc_paraula_estat(4,0x2,paraula_moviment);
						}

						if (vector_posicions[i].pos_pinca > posicio_actual.pos_pinca) {  // Tancar la pinça
							paraula_moviment = calc_paraula_estat(4,0x1,paraula_moviment);
						}else if (vector_posicions[i].pos_pinca < posicio_actual.pos_pinca) {
							paraula_moviment = calc_paraula_estat(4,0x2,paraula_moviment);
						}
					}
				}
			}
			reproduir = 0;
		}
	}
}


