#ifndef __LT3LCG_H
#define __LT3LCG_H

#include "cLT3rng.h"

class LT3LCG : public cLT3rng {
private:
	unsigned long long numberOfSamplesGenerated;
	double seed;
	double a;
	double b;
	double m;
	double currentX;	

public:
	virtual void initialize(int runNumber, int id, int numRngs, int parsimProcId, int parsimNumPartitions, cConfiguration *cfg);
	virtual void selfTest();
	virtual double doubleRand();
};

#endif
