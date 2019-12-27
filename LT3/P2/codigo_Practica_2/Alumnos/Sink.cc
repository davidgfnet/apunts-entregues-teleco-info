
#include <cmessage.h>
#include <omnetpp.h>


class Sink : public cSimpleModule
{
public:
    Module_Class_Members(Sink, cSimpleModule, 0);

    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

// Registramos la clase para su uso en OMNET
Define_Module(Sink);

void Sink::initialize()
{

}

void Sink::handleMessage(cMessage *msg)
{
	delete msg;
}


