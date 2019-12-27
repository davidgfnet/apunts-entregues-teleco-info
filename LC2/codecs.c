//========================================================================
//         CODEC.C: Codificadores para transmision en banda base
//========================================================================
#include "codec.h"

// rz es el nombre de mostres que cal portar a zero en emetre un 1
void cod_rz (USER *pUsr, int *out, int rz) {
	int i,j;
	for (i = 0; i < pUsr->nbits; i++) {
		if (pUsr->bits[i] == 0) {
			for (j = 0; j < pUsr->lSymb; j++)    *out++ = 0;
		}else{
			for (j = 0; j < pUsr->lSymb-rz; j++) *out++ = pUsr->V;
			for (j = 0; j < rz; j++)             *out++ = 0;
		}
	}
}

// Cod. polar, 0 es -V i 1 es +V
void cod_polar (USER *pUsr, int *out) {
	int i,j;
	for (i = 0; i < pUsr->nbits; i++)
		for (j = 0; j < pUsr->lSymb; j++) *out++ = ((pUsr->bits[i]<<1)-1)*pUsr->V;
}

// Cod. bipolar, 0 es 0V i 1 es +/-V (alternant)
void cod_bipolar (USER *pUsr, int *out) {
	int i,j;
	for (i = 0; i < pUsr->nbits; i++) {
		if (pUsr->bits[i] == 0) {
			for (j = 0; j < pUsr->lSymb; j++) *out++ = 0;
		}else{
			for (j = 0; j < pUsr->lSymb; j++) *out++ = pUsr->sgnOne*pUsr->V;
			pUsr->sgnOne = -pUsr->sgnOne;
		}
	}
}

// Cod AMI, 0 es 0V i 1 es +/-V mig periode i 0 la resta del periode
void cod_ami (USER *pUsr, int *out) {
	int i,j;
	int down = pUsr->lSymb>>1;
	int up = pUsr->lSymb-down;
	for (i = 0; i < pUsr->nbits; i++) {
		if (pUsr->bits[i] == 0) {
			for (j = 0; j < pUsr->lSymb; j++) *out++ = 0;
		}else{
			for (j = 0; j < up; j++) *out++ = pUsr->sgnOne*pUsr->V;
			pUsr->sgnOne = -pUsr->sgnOne;
			for (j = 0; j < down; j++) *out++ = 0;
		}
	}
}

// CMI, el zero es codificat com manchester (invertit) i el 1 com a bipolar
void cod_cmi (USER *pUsr, int *out) {
	int i,j;
	int down = pUsr->lSymb>>1;
	int up = pUsr->lSymb-down;
	for (i = 0; i < pUsr->nbits; i++) {
		if (pUsr->bits[i] == 0) {
			for (j = 0; j < down; j++) *out++ = -pUsr->V;
			for (j = 0; j < up; j++)   *out++ =  pUsr->V;
		}else{
			for (j = 0; j < pUsr->lSymb; j++) *out++ = pUsr->sgnOne*pUsr->V;
			pUsr->sgnOne = -pUsr->sgnOne;
		}
	}	
}

// Manchester, per al 0 tenim +V|-V i per al 1 tenim -V|+V
void cod_manchester (USER *pUsr, int *out) {
	int i,j;
	int down = pUsr->lSymb>>1;
	int up = pUsr->lSymb-down;
	for (i = 0; i < pUsr->nbits; i++) {
		for (j = 0; j < down; j++) *out++ = (1-(pUsr->bits[i]<<1))*pUsr->V;
		for (j = 0; j < up; j++)   *out++ = ((pUsr->bits[i]<<1)-1)*pUsr->V;
	}
}

// Codifica el bitstream de forma diferencial
void cod_dif (USER *pUsr) {
	int i;
	for (i = 0; i < pUsr->nbits; i++) {
		int lastb = pUsr->state.lastBit;
		pUsr->state.lastBit = pUsr->bits[i];
		if (pUsr->bits[i] == lastb) {
			pUsr->bits[i] = 0;
		}else{
			pUsr->bits[i] = 1;
		}
	}
}

/********************************************************
  PRE:  en pUsr->bits[-3], pUsr->bits[-2], pUsr->bits[-1],
        están almacenados los 3 simbolos {+1,0,-1} previos
  POST: los bits en pUsr->bits son cambiados a simbolos {+1,0,-1}
        El usuario deberia copiarlos si los quiere preservar

 LINK: http://en.wikipedia.org/wiki/Modified_AMI_code

  sgnOne es la polaritat de l'ultim 1

  Dues etapes, en la primera es modifica el vector de bits
  i quests passem a ser simbols (-1,0,1). La segona etapa
  codifica les mostres i les envia al buffer
********************************************************/
void cod_hdb3 (USER *pUsr, int *out) {
	int i,j;
	for (i = 0; i < pUsr->nbits; i++) {
		if (pUsr->bits[i] == 0) {
			pUsr->state.zeroes++;
			if (pUsr->state.zeroes == 4) {
				// Modifiquem els 3 ultims simbols!
				if (pUsr->state.dc != 0) { // Component DC! omplir amb B00V
					// Tirem enrere 3 simbols i l'omplim amb una B alternant
					pUsr->sgnOne = -pUsr->sgnOne;
					pUsr->bits[i-3] = pUsr->sgnOne;
					pUsr->bits[i]   = pUsr->sgnOne;
					pUsr->state.dc += (2*pUsr->sgnOne); // Update DC
				}else{ // No hi ha DC, omplir amb 000V on V és repetir l'últim 1
					pUsr->bits[i]   = pUsr->sgnOne;
					pUsr->state.dc += pUsr->sgnOne;
				}
				pUsr->state.zeroes = 0;
			}else{
				pUsr->bits[i] = 0;
			}
		}else{
			pUsr->sgnOne = -pUsr->sgnOne; // Alternar la polaritat respecte l'ultim 1
			pUsr->state.dc += pUsr->sgnOne; // Actualitzar la DC
			pUsr->bits[i] = pUsr->sgnOne;
			pUsr->state.zeroes = 0;
		}
	}

	// Etapa 2, enviar els bits -3,-2 ... nbits-3
	for (i = -3; i < pUsr->nbits-3; i++)
		for (j = 0; j < pUsr->lSymb; j++)
			*out++ = pUsr->bits[i]*pUsr->V;

	// Final, guardem els 3 bits ultims (no enviats) al inici del vector (-3..-1) per a enviar-los a la propera
	for (i = 0; i < 3; i++)
		pUsr->bits[i-3] = pUsr->bits[i-3+pUsr->nbits]
}


