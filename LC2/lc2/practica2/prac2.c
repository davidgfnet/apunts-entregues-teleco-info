//************************************************************************
//                                 PRAC2.C                                
//                                                                        
//                          Modulaciones banda base                        
//========================================================================
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "codec.h"
#include "dsk6713_aic23.h"   //Ficheros de soporte del DSK6713
#define SIMB_BUFF       100  // simbolos a generar por bloque 
#define AMPLITUD       	16384
#define MUESTRAS_SIMBOLO 12
#define LBUFF          SIMB_BUFF*MUESTRAS_SIMBOLO
typedef struct {
	 int *bits, nbits, index;
} SEQUENCE;

//  Se repiten los primeros ninput_bits de la secuencia input_bits 
#define ninput_bits 6 
int input_bits[] = {1,0,0,0,0,0};
int buffer1[LBUFF], buffer2[LBUFF];
int BITS[SIMB_BUFF + 3]; // +3 ya que el esquema hdb3 necesita 3 bits de memoria 
int *iobuffer = buffer1;
int *oblock = buffer2;
Uint32 fs=DSK6713_AIC23_FREQ_16KHZ; //ajuste de la frecuencia de muestreo
int sample=0;

void init_arrays() 
{
    int i;
    for (i=0;i<LBUFF;i++)
	buffer1[i] = buffer2[i] = 0;
    sample=0;
}
void init_user(USER *pUsr) 
{
    pUsr->lSymb = MUESTRAS_SIMBOLO;
    pUsr->V = AMPLITUD;
    pUsr->state.lastBit = 0;
    pUsr->state.sgnOne  = -1;
    pUsr->state.dc = 0;
    pUsr->state.zeroes  = 3;
    pUsr->nbits = SIMB_BUFF;
    pUsr->bits = &BITS[3];
    pUsr->bits[-3] = pUsr->bits[-2] = pUsr->bits[-1] = 0;
}

void wait_buffer (void) 
{
    int *pt;
    while (sample < LBUFF);
    pt = oblock;
    oblock = iobuffer;
    iobuffer = pt;
    sample = 0;
}

void read_bits(SEQUENCE *pSeq, int nbits, int *bits) 
{
    int i;
    for (i=0; i<nbits; i++) {
	     bits[i] = pSeq->bits[pSeq->index++];
	     if (pSeq->index == pSeq->nbits) 
		      pSeq->index = 0;
    }
}

interrupt void c_int11()
{
	if (sample<LBUFF)
    	output_sample(iobuffer[sample++]);
	return;
}

void main (void) 
{	
	 SEQUENCE seq = {input_bits, ninput_bits, 0};
	 USER usr;
	 init_arrays();
     init_user(&usr);               // Inicio de variable de estado 
	 comm_intr();					//inicio DSK, codec, McBSP usando interrupciones
	 while(1)
	 {	   
		  wait_buffer();
		  read_bits(&seq, usr.nbits, usr.bits);
		  //cod_rz(&usr, oblock, usr.lSymb-(usr.lSymb)/4);
		  //cod_polar (&usr, oblock);
		  //cod_bipolar (&usr, oblock);
		  cod_hdb3 (&usr, oblock);
	 }
}