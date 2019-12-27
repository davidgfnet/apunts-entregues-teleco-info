#include <cmessage.h>
#include <string.h>
#include <omnetpp.h>


class StartModule : public cSimpleModule
{
public:
    Module_Class_Members(StartModule, cSimpleModule, 0);

    // The following redefined virtual function holds the module
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

// The module class needs to be registered with OMNeT++
Define_Module(StartModule);

void StartModule::initialize()
{
    cMessage * msg;

    // Enviando el mensaje inicial
    msg = new cMessage("Start simulation");
    scheduleAt(simTime(), msg);
}

void StartModule::handleMessage(cMessage *msg)
{
	send(msg, "gout");
}



