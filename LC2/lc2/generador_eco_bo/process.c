#include <math.h>
#include <stdlib.h>
#include "block.h"

#define PI 3.141592654

float hFIR[L_FIR] = {0.25,0,0,0,0.25,0,0,0,0,0,0};
float guany = 0;
float retard[D] = {0};

void inicialitzacio() {
	int i;
	guany = 0;
	for (i = 0; i< L_FIR; i++)
		guany += hFIR[i]*hFIR[i];

	guany = sqrtf(1-guany);
}

void fir(float *x, float *y, float *h, int k, int n) {
	int i,j;
	for (i = 0; i < n; i++) {
		float accum = 0;
		for (j = 0; j < k; j++)
			accum += h[j]*x[i-j];
		y[i] = accum;
	}
}


void processFIR(float *block, float *h)
{
    int i;
    static float x[(L_FIR-1)+N] = {0};         // FIR Input buffer             

    for (i=0; i<N; i++) x[L_FIR-1+i] = block[i];
    fir(&x[L_FIR], block, h, L_FIR, N);
    for (i=0; i<(L_FIR-1); i++) x[i] = x[i+N];
}


void calculaEco(float * io_block) {
	int i, j = 0;
	processFIR(retard,hFIR);	    // Procesa bloque
	for (i = 0; i < N; i++)
		io_block[i] = io_block[i]*guany + retard[i];
	for (i = N; i < D; i++)
		retard[i-N] = retard[i];
	for (i = D-N; i < D; i++)
		retard[i] = io_block[j++];
}

