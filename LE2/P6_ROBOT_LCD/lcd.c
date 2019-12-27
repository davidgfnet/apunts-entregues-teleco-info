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


BYTE valor_P1 = 0x00;
BYTE valor_P0 = 0x00;
DWORD wait_ = 0;
BYTE cont;

// De sobra! Més de 50ms segur!
#define ESPERA_40US for(wait_ = 0; wait_ < 20; wait_++){}
#define ESPERA_100US for(wait_ = 0; wait_ < 60; wait_++){}
// Uns 20-30 ms
#define ESPERA_15MS for(wait_ = 0; wait_ < 200; wait_++){}

void fi_inst_dada(void) {
    valor_P1 = BIT5;  // E=0; Read; RS =0
    SetP0(valor_P0);   // SImplement garantim que està en read, pero no escriure aleatoriament
               // Hem de posar a read després de fer un write si sabem que ja està escrit
               // (esto.. ha passat un any i mig vaya)
}

void escriu_inst_lcd(BYTE inst) {
    // RS = 0, R/W* = 0, E = 1
    valor_P1 = BIT6;
    valor_P0 = inst;
   
    SetP0(valor_P0);
    SetP1(valor_P1);

    ESPERA_40US    // Fem un pols amb E de uns 40US

    valor_P1 = 0;  // Netejem E però mantenim WRITE
    SetP1(valor_P1);
}

void escriu_dada_lcd(BYTE dada) {
    // RS = 1, R/W* = 0, E = 1
    valor_P1 = BIT6|BIT4;
    valor_P0 = dada;
   
    SetP0(valor_P0);
    SetP1(valor_P1);

    ESPERA_40US    // Fem un pols amb E de uns 40US

    valor_P1 = 0;  // Netejem E però mantenim WRITE
    SetP1(valor_P1);
}

// Diria que és massa lenta la inicialització, serà qüestió de "tunear" el bucle hasta que no rule xD
void init_lcd() {
    ESPERA_15MS   // Esperar a que arribi alimentació (dale al botón de on! xD)
    escriu_inst_lcd(BIT6|BIT5);   // Enviem tres vegades aquesta merdeta
    ESPERA_15MS
    fi_inst_dada();

    escriu_inst_lcd(BIT6|BIT5);
    ESPERA_100US
    fi_inst_dada();

    escriu_inst_lcd(BIT6|BIT5);
    ESPERA_100US
    fi_inst_dada();

    escriu_inst_lcd(BIT6|BIT5|BIT4|BIT3);  // Dos linies+ 8bits de dades + caracters grans
    ESPERA_40US
    fi_inst_dada();

    escriu_inst_lcd(BIT3);  // Apagar!
    ESPERA_40US
    fi_inst_dada();

    escriu_inst_lcd(BIT3|BIT2);  // Encen!
    ESPERA_40US
    fi_inst_dada();

    escriu_inst_lcd(BIT4|BIT2);  // Cursos es deplaça a la dreta!
    ESPERA_40US
    fi_inst_dada();

    escriu_inst_lcd(BIT1);  // Cursor a l'inici
    ESPERA_40US
    fi_inst_dada();
}


void escriu_frase(BYTE * frase) {
    BYTE maux;
    escriu_inst_lcd(BIT1);  // Cursor a l'inici
    ESPERA_40US
    fi_inst_dada();
    maux = 0;
    for (cont = 0; cont < 16; cont++) {
	if (frase[cont] == 0x00 || maux==1) {  // Fi de la frase
		escriu_dada_lcd(' ');
		maux = 1;
	}else{
		escriu_dada_lcd(frase[cont]);
	}
	ESPERA_40US
	fi_inst_dada();
    }
}

void itoa(BYTE * cad, BYTE num,BYTE digit) {
	BYTE cont=digit-1;
	do {
		cad[cont] = (num%10)+'0';
		num = num /10;
		cont--;
	} while (cont != 0xFF) ;
}

BYTE buffer[17];
void escriu_valors(struct posicio * pos) {
	buffer[0] = 'R';
 	buffer[0+4] = 'H';
 	buffer[0+8] = 'V';
  	buffer[0+12] = 'P';
	itoa(&buffer[1],pos->rotacio,3);
	itoa(&buffer[1+4],pos->pos_horit,3);
	itoa(&buffer[1+8],pos->pos_vert,3);
	itoa(&buffer[1+12],pos->pos_pinca,3);
	escriu_frase(buffer);
}

void escriu_frase_integer (BYTE * frase, BYTE enter) {
	cont=0;
	while (frase[cont] != 0) {
	buffer[cont] = frase[cont];
	cont++;
	}
	itoa(&buffer[cont],enter,16-cont);
	escriu_frase(buffer);
}

