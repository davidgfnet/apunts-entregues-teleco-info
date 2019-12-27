#include <cconfig.h>
#include <omnetpp.h>
#include <sstream>
#include <string>
#include <limits>
#include <time.h>
#include "LT3LCG.h"

using std::ostringstream;
using std::numeric_limits;
using std::string;
using std::cout;

Register_Class(LT3LCG);

void LT3LCG::initialize(int runNumber, int id, int numRngs, int parsimProcId, int parsimNumPartitions, cConfiguration * cfg) {

	ostringstream sstr;
	string runstr;
	string lcgstr;
  	string seedstr;

	sstr.str("");
	sstr << "Run " << runNumber;
	runstr = sstr.str();
	sstr.str("");
	sstr << "LCG " << numRngs;
	lcgstr = sstr.str();
	sstr.str("");
	sstr << "seed-" << numRngs << "-lcg";
 	seedstr = sstr.str();
	
	// Getting algorithm values
	this->seed = (double) cfg->getAsInt2("General", runstr.c_str(), seedstr.c_str());
	this->a = (double) cfg->getAsInt2("General", lcgstr.c_str(), "multiplier");
	this->b = (double) cfg->getAsInt2("General", lcgstr.c_str(), "additive");
	this->m = (double) cfg->getAsInt2("General", lcgstr.c_str(), "module");
	
	// Setting init values
	this->numberOfSamplesGenerated = 0;
	this->currentX = this->seed;

	cout << "LCG random generator loaded with:" << endl;
	cout << "\ta: " << this->a << endl;
	cout << "\tb: " << this->b << endl;
	cout << "\tmodule: " << this->m << endl;
	cout << "\tseed: " << this->seed << endl;
}


void LT3LCG::selfTest() {
	cout << "Using the Linear Congruential Random Generator" << endl;
}

double LT3LCG::doubleRand() {
	// Incluir el codigo para obtener el siguiente valor del generador congruencial
	// Podeis utilizar las siguientes variables ya creadas en el fichero LT3LCG.h:
	// 	a: Es el factor multiplicativo del generador
	//	b: Es el factor aditivo del generador
	//	m: Es el modulo del generador
	//	currentX: Es el valor del ultimo valor producido por el generador.
	// Recordad que se debe actualizar el valor de currentX antes de devolver el nuevo valor del generador
	currentX = a * currentX + b;
	currentX = fmod (currentX,m);
	return currentX / m;	
}


