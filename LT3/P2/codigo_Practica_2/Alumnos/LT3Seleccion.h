#ifndef __LT3SELECCION_H
#define __LT3SELECCION_H

class LT3LCG;
class LT3Fibonacci;

class LT3Seleccion : public cLT3rng {
private:
	LT3LCG * lcg1;
	LT3LCG * lcg2;
	double * buffer;	
	unsigned int bufferSize;
	
public:
	LT3Seleccion();
	virtual ~LT3Seleccion();
	virtual void initialize(int runNumber, int id, int numRngs, int parsimProcId, int parsimNumPartitions, cConfiguration *cfg);
	virtual void selfTest();
	virtual double doubleRand();
};

#endif
