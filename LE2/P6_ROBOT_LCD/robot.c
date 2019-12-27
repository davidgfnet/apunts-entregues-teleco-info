/////////////////////////////////
// LAB II
// Robot.axe: Projecte de configuraci�.
// v1.0 - (c)2001 DEE-UPC
// Robot.c:Programa principal del projecte  
/////////////////////////////////

#include <embedded.h>
#include "typedefs.h"
#include "register.h"
#include "timers.h"
#include "ports.h"
#include "mis_includes.h"

BYTE estat_P2 = 0x00;
BYTE reset = 1;
BYTE no_show = 0;
extern BYTE cicle_treball[4];
extern int contador_lcd;

BYTE reproduir = 0;  // SI es 0, mode normal, 1 mode reproduccio!

struct posicio posicio_actual;            // S'actualitza sola indicant la posicio del robot! Cal posarla a 0 al fer un reset!
struct posicio vector_posicions[MAX_ALMACENAR];      // Llista de posicions a guardar!
BYTE proxima_posicio_gravar = 0;   // Indica la proxima posici� que es gravara al pulsar gravar
				   // Per a borrar les dades nom�s cal posarla a 0.
				   // Si �s 0 tamb� sabem que no hi ha res gravat.
BYTE paraula_moviment;		   // Indica l'estat dels motors a cada instant al reproduir
BYTE cont_pinca = 0, cont_posh = 0, cont_posv = 0, cont_rot = 0; // TODO: Caldria inicialitzarlos despres de reset, potser valen 1 no? Depen del motor
BYTE moviment_1 = 0, moviment_2 = 0, moviment_3 = 0, moviment_4 = 0;
// Ser� 1 si avancem (Tancar pin�a, rot horari, endevant i avall) o -1 lo altre

BYTE calc_paraula_estat (BYTE num_motor, BYTE codi_estat, BYTE paraula) {
	BYTE mascara = (0x3 << 2*(num_motor-1));
	paraula &= ~(mascara);  // Netejem l'estat! El posem a 00
	// Enmascarem el codi per si de cas for incorrecte!
	paraula |= ( (codi_estat & 0x3) << 2*(num_motor-1) );
	return paraula;
}

// Motor �s un enter de 1 a 4!
void motor_estat (BYTE num_motor, BYTE codi_estat) {
	estat_P2=calc_paraula_estat(num_motor,codi_estat,estat_P2);
	SetP2(estat_P2);
}

// Torna quan el robot es troba a l'origen
void robot_inici() {
	BYTE status;
	pinza_abrir; rot_antihorario; movh_atras; movv_arriba;
	status = GetPT();
	// Esperem mentre no estigui a l'origen
	while ( (status & 0x01) != 0 ) {status = GetPT();}
	parar_todo;

	posicio_actual.pos_pinca = 0;
	posicio_actual.pos_horit = 0;
	posicio_actual.pos_vert = 0;
	posicio_actual.rotacio = 0;
}

void main() {
	BYTE i,temp;
	// Important iniciar els ports de I/O correctament
	IniPorts();
	// Inicialitza el LCD
	init_lcd();
	// Inicialitzem el port serie
	InicialitzaSerie();
	// Parem el robot
	parar_todo;
	// Activem els timers
	IniTimers();
	enable(); // Permetem interrupcions!

	while (1) {

	// Escribim els valors actuals si no_show==0
   	if (no_show == 0) escriu_valors(&posicio_actual);
	
	// Es vol fer un reset!
   	if (reset == 1) {
	      	escriu_frase("Robot: reset");
		disable();  // Parem interrupcions per a fer el reset, important!
		robot_inici();
		reset = 0;
		enable();   // Tornem al mode habitual
	}

	if (reproduir == 1) {  // Mode reproducci�!
	       	escriu_frase("Robot: reproduir");
		if (proxima_posicio_gravar != 0) {  // Comprovar que hi hagi alguna cosa a la llista de reproduccions!!!
			parar_todo;  // Parem, resetegem i comencem a reproduir
			disable(); robot_inici(); enable();
	           	posicio_actual.pos_pinca = 0;
	         	posicio_actual.pos_horit = 0;
	         	posicio_actual.pos_vert = 0;
	         	posicio_actual.rotacio = 0;

			for (i = 0; i < proxima_posicio_gravar; i++) {
				// Anem escribint el moviment que estem fent
	    	        	escriu_frase_integer("Moviment: ",i+1);
				temp = 0x00;  // Variable que indica el moviment
				while (!(temp == 0xFF)) {
					// Ens quedem recalculant la paraula d'estat mentre no arribem  la seguent posicio
					temp = 0xFF;
					// Calcular com han d'estar els motors, i revisar si s'ha assolit la posici�!
					if (vector_posicions[i].pos_pinca > posicio_actual.pos_pinca) {  // Tancar la pin�a
						moviment_4 = 1;
						temp=calc_paraula_estat(4,0x1,temp);
					}else if (vector_posicions[i].pos_pinca < posicio_actual.pos_pinca) {
						moviment_4 = -1;
						temp=calc_paraula_estat(4,0x2,temp);
					}

					if (vector_posicions[i].rotacio > posicio_actual.rotacio) {  // Moviment horari
						moviment_1 = 1;
						temp=calc_paraula_estat(1,0x1,temp);
					}else if (vector_posicions[i].rotacio < posicio_actual.rotacio) {
						moviment_1 = -1;
						temp=calc_paraula_estat(1,0x2,temp);
					}

					if (vector_posicions[i].pos_horit > posicio_actual.pos_horit) {  // Endevant
						moviment_2 = 1;
						temp=calc_paraula_estat(2,0x1,temp);
					}else if (vector_posicions[i].pos_horit < posicio_actual.pos_horit) {
						moviment_2 = -1;
						temp=calc_paraula_estat(2,0x2,temp);
					}

					if (vector_posicions[i].pos_vert > posicio_actual.pos_vert) {  // Avall
						moviment_3 = 1;
						temp=calc_paraula_estat(3,0x1,temp);
					}else if (vector_posicions[i].pos_vert < posicio_actual.pos_vert) {
						moviment_3 = -1;
						temp=calc_paraula_estat(3,0x2,temp);
					}

					// Mirem a quina velocitat hem d'anar
					if (abs(vector_posicions[i].rotacio - posicio_actual.rotacio) < MARGE_LENT) cicle_treball[0] = 4;
					else cicle_treball[0] = 1;
					if (abs(vector_posicions[i].pos_horit - posicio_actual.pos_horit) < MARGE_LENT) cicle_treball[1] = 4;
					else cicle_treball[1] = 1;
					if (abs(vector_posicions[i].pos_vert - posicio_actual.pos_vert) < MARGE_LENT) cicle_treball[2] = 4;
					else cicle_treball[2] = 1;
					if (abs(vector_posicions[i].pos_pinca - posicio_actual.pos_pinca) < MARGE_LENT) cicle_treball[3] = 4;
					else cicle_treball[3] = 1;

					paraula_moviment = temp;
				}
			}
		}else{
			// Cas de reproducci� per� no hem guardat res
	  		contador_lcd=0;
			no_show = 1;
			escriu_frase("Res a reproduir!");
		}
	reproduir = 0;
	}

	}  // while (1)
 
}


