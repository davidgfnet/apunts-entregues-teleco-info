#include <crng.h>

#ifndef __CLT3RNG_H
#define __CLT3RNG_H

class cLT3rng : public cRNG {
private:
	unsigned long long numberOfSamplesGenerated;
	
public:
	virtual void selfTest();
	virtual unsigned long numbersDrawn();
	virtual unsigned long intRand();
	virtual unsigned long intRandMax();
	virtual unsigned long intRand(unsigned long n);
	virtual double doubleRandNonz();
	virtual double doubleRandIncl1();
	virtual double doubleRandNonzIncl1();
};

#endif


