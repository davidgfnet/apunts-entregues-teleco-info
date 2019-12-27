#include <cconfig.h>
#include "cLT3rng.h"
#include <omnetpp.h>
#include <sstream>
#include <string>
#include <limits>
#include <time.h>
#include "cLT3rng.h"
#include "LT3Seleccion.h"
#include "LT3LCG.h"

using std::ostringstream;
using std::numeric_limits;
using std::string;
using std::cout;


Register_Class(LT3Seleccion);

LT3Seleccion::LT3Seleccion() {
	lcg1 = new LT3LCG();
	lcg2 = new LT3LCG();
	buffer = NULL;
}

LT3Seleccion::~LT3Seleccion() {
	if (lcg1) delete lcg1;
	if (lcg2) delete lcg2;
	if (buffer) delete buffer;
}

void LT3Seleccion::initialize(int runNumber, int id, int numRngs, int parsimProcId, int parsimNumPartitions, cConfiguration * cfg) {

	int i;

	lcg1->initialize(runNumber, id, 1, parsimProcId, parsimNumPartitions, cfg);
	lcg2->initialize(runNumber, id, 2, parsimProcId, parsimNumPartitions, cfg);
	this->bufferSize = (unsigned int) cfg->getAsInt2("General", "Seleccion", "bufferSize");
	this->buffer = new double[this->bufferSize];
	for (i = 0; i < this->bufferSize; i++) {
		this->buffer[i] = lcg1->doubleRand();
	}
	
	cout << "Selection random generator loaded with:" << endl;
	cout << "\tBuffer size: " << this->bufferSize << endl;

}


void LT3Seleccion::selfTest() {
	cout << "Using the Selection Random Generator" << endl;
}

double LT3Seleccion::doubleRand() {
	// Incluir el codigo para obtener el siguiente valor del generador congruencial
	// Podeis utilizar las siguientes variables ya creadas en el fichero Seleccion.h:
	// 	1) lcg1 es un puntero a un generador congruencial lineal 
	//		Mediante la llamada lcg1->doubleRand() se puede obtener un valor pseudoaleatorio de este generador.
	//	2) lcg2 es un puntero a un generador congruencial lineal
	//		Mediante la llamada lcg2->doubleRand() se puede obtener un valor pseudoaleatorio de este generador.
	//	3) buffer es un vector que contiene los valores a ser mezclados. Dichos valores han sido generados mediante el generador congruencial.
	//	4) bufferSize es una constante que contiene la longitud del vector
	double d;
	int pos;

	// Obtener el indice en el buffer con fibonacci
	pos = (int)floor(lcg2->doubleRand()*bufferSize) % bufferSize;

	// Guardar el valor de la posicion
	d = buffer[pos];

	// Regenerar el valor con LCG
	buffer[pos] = lcg1->doubleRand();
	
	return d;
}

