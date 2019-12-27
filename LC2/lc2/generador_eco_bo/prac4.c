#include "dsk6713_aic23.h"		   // Soporte codec-DSK
#include "block.h"
#include "process.h"

Uint32 fs=DSK6713_AIC23_FREQ_8KHZ; // Ajuste de la frecuencia de muestreo

float io1[N], io2[N];	    	// Reserva espacio para los buffers

float *io_block,*io_buffer;			// Puntero del bloque a procesar
int index=0;

interrupt void c_int11()         	// Rutina de servicio de interrupcion
{  	
 	if (index < N)
	{
 		output_sample((int)io_buffer[index]);
		io_buffer[index++]=(float)input_left_sample();
	}
	return;
}

void init_buffer_block(void)
{
    io_buffer = io1;
    io_block  = io2;
}

void wait_buffer_block(void)
{
    float *ptmp;			// Puntero auxiliar			

    while(index < N);		// Espera a que se llene el buffer	
    ptmp = io_buffer;		// Intercambia punteros: 		
    io_buffer = io_block;	// nuevo buffer de entrada/salida	
    io_block = ptmp;		// nuevo bloque de datos		
    index = 0;				// Inicializa index			
}

void main()
{
	inicialitzacio();		// Filtro generado con MATLAB

	init_buffer_block();
	comm_intr();                   	// inicio DSK, codec, McBSP usando interrupciones



	while(1)               	  	 	// bucle infinito
	{
		wait_buffer_block();		// Espera a que se llene el buffer
		calculaEco(io_block);
	}	 
}

