#include <cmessage.h>
#include <sstream>
#include <string>
#include <omnetpp.h>
#include <chist.h>

using std::ostringstream;
using std::string;

class GenerateRandomNumbers : public cSimpleModule {

private:
	static const unsigned int STEP_SIZE;
	unsigned long numOfSteps;
	unsigned long numOfRandomNumbers;
	unsigned long remainingSamples;
	unsigned int numOfBars;
	cDoubleHistogram * rngHistogram;	// Histogram for the random samples
	cOutVector rngSamples;	// Raw random samples

public:
	Module_Class_Members(GenerateRandomNumbers, cSimpleModule, 0);

	virtual ~GenerateRandomNumbers();

	// The following redefined virtual function holds the module.
	virtual void initialize();
	virtual void handleMessage(cMessage *msg);
	virtual void finish();
};

// The module class needs to be registered with OMNeT++
Define_Module(GenerateRandomNumbers);

const unsigned int GenerateRandomNumbers::STEP_SIZE=500;

GenerateRandomNumbers::~GenerateRandomNumbers() {

	delete rngHistogram;
}

void GenerateRandomNumbers::initialize() {

	// Getting the amount of random numbers to generate
	this->numOfRandomNumbers = (unsigned long) par("number_of_random_numbers");
	this->remainingSamples = this->numOfRandomNumbers;
	this->numOfSteps = 0;

	// Getting the number of bars in the histogram
	this->numOfBars = (unsigned int) par("num_of_bars");

	// Init statistics
	rngHistogram = new cDoubleHistogram("Random samples", this->numOfBars);
	rngHistogram->setRangeAutoUpper(0, 100, 1.5);
	rngSamples.setName("Random samples");
}

void GenerateRandomNumbers::handleMessage(cMessage *msg) {

	double number;
	ostringstream sstr;
	unsigned long i;
	unsigned long limit;
	
	// Setting the number of samples in the step
	limit = this->remainingSamples < STEP_SIZE? this->remainingSamples : STEP_SIZE;
	
	// Saving samples in a step
	for (i=0; i < limit; ++i) {
		number = (double) par("random_variable");
		rngHistogram->collect(number);
		rngSamples.record(number);
	}

	// Updating the remainin samples
	this->remainingSamples -= limit;

	if (this->remainingSamples > 0) {
		sstr.str("");
		sstr << (this->numOfRandomNumbers - this->remainingSamples) << " samples";
		bubble(sstr.str().c_str());
		
		scheduleAt(simTime(), msg);
	} else {

		// Forwarding the message to the end module
		send(msg, "gout");
	}
}

void GenerateRandomNumbers::finish() {

	ev << endl;
	ev << "Statistic information" << endl;
	ev << "--------- -----------" << endl << endl;
	ev << "Average: " << rngHistogram->mean() << endl;
	ev << "Std. deviation: " << rngHistogram->stddev() << endl;
	ev << "Minimum: " << rngHistogram->min() << endl;
	ev << "Maximum: " << rngHistogram->max() << endl;

	rngHistogram->recordScalar("Random samples");
}



