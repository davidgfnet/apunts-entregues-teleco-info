#include "dsk6713_aic23.h"		   //fichero de soporte codec-DSK
#define IDLE  asm("	idle")
Uint32 fs=DSK6713_AIC23_FREQ_32KHZ; //ajuste de la frecuencia de muestreo
int output_data;
int input_data;
int signo = 1;

interrupt void c_int11()         //rutina de servicio de interrupcion
{  	
	input_data = input_left_sample();  // señan del canal izquierdo de line in
 	output_sample(output_data);
	return;
}

void main()
{
  comm_intr();                   //inicio DSK, codec, McBSP usando interrupciones
  while(1)               	  	 //bucle infinito
  {
	IDLE;
	output_data = signo*input_data;
	signo = (-1)*signo;
  }	 
}

