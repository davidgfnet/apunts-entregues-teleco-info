#include "cLT3rng.h"
#include <limits>

using std::numeric_limits;

void cLT3rng::selfTest() {
	// Nothing to do
}

unsigned long cLT3rng::numbersDrawn() {

	return this->numberOfSamplesGenerated;
}

unsigned long cLT3rng::intRand() {

	return static_cast<unsigned long>(this->doubleRand() * numeric_limits<unsigned long>::max());
}

unsigned long cLT3rng::intRandMax() {

	return static_cast<unsigned long>(numeric_limits<unsigned long>::max() -1);
}

unsigned long cLT3rng::intRand(unsigned long n) {

	return static_cast<unsigned long>(this->doubleRand() * n);
}

double cLT3rng::doubleRandNonz() {

	double num;
	
	while ((num = this->doubleRand()) == 0);
	
	return num;
}

double cLT3rng::doubleRandIncl1() {

	return this->doubleRand();
}

double cLT3rng::doubleRandNonzIncl1() {

	return this->doubleRand();
}


