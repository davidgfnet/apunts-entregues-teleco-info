//-----------------------------------------
//
// Generated by nedtool, version 3.3
// date: Fri Oct 14 09:43:35 2011
//
//-----------------------------------------


#include <math.h>
#include "omnetpp.h"

// NEDC version check
#define NEDC_VERSION 0x0303
#if (NEDC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedc: 'make clean' should help.
#endif

// Disable warnings about unused variables. For MSVC and BC only:
// GCC has no way to turn on its -Wunused option in a source file :(
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#endif
#ifdef __BORLANDC__
#  pragma warn -waus
#  pragma warn -wuse
#endif

static cModuleType *_getModuleType(const char *modname)
{
    cModuleType *modtype = findModuleType(modname);
    if (!modtype)
        throw new cRuntimeError("Module type definition %s not found (Define_Module() missing from C++ code?)", modname);
    return modtype;
}

static void _checkModuleVectorSize(int vectorsize, const char *mod)
{
    if (vectorsize<0)
        throw new cRuntimeError("Negative module vector size %s[%d]", mod, vectorsize);
}

static void _readModuleParameters(cModule *mod)
{
    int n = mod->params();
    for (int k=0; k<n; k++)
        if (mod->par(k).isInput())
            mod->par(k).read();
}

static int _checkModuleIndex(int index, int vectorsize, const char *modname)
{
    if (index<0 || index>=vectorsize)
        throw new cRuntimeError("Submodule index %s[%d] out of range, sizeof(%s) is %d", modname, index, modname, vectorsize);
    return index;
}

static cGate *_checkGate(cModule *mod, const char *gatename)
{
    cGate *g = mod->gate(gatename);
    if (!g)
        throw new cRuntimeError("%s has no gate named %s",mod->fullPath().c_str(), gatename);
    return g;
}

static cGate *_checkGate(cModule *mod, const char *gatename, int gateindex)
{
    cGate *g = mod->gate(gatename, gateindex);
    if (!g)
        throw new cRuntimeError("%s has no gate %s[%d]",mod->fullPath().c_str(), gatename, gateindex);
    return g;
}

static cGate *_getFirstUnusedParentModGate(cModule *mod, const char *gatename)
{
    int baseId = mod->findGate(gatename);
    if (baseId<0)
        throw new cRuntimeError("%s has no %s[] gate",mod->fullPath().c_str(), gatename);
    int n = mod->gate(baseId)->size();
    for (int i=0; i<n; i++)
        if (!mod->gate(baseId+i)->isConnectedInside())
            return mod->gate(baseId+i);
    throw new cRuntimeError("%s[] gates are all connected, no gate left for `++' operator",mod->fullPath().c_str(), gatename);
}

static cGate *_getFirstUnusedSubmodGate(cModule *mod, const char *gatename)
{
    int baseId = mod->findGate(gatename);
    if (baseId<0)
        throw new cRuntimeError("%s has no %s[] gate",mod->fullPath().c_str(), gatename);
    int n = mod->gate(baseId)->size();
    for (int i=0; i<n; i++)
        if (!mod->gate(baseId+i)->isConnectedOutside())
            return mod->gate(baseId+i);
    int newBaseId = mod->setGateSize(gatename,n+1);
    return mod->gate(newBaseId+n);
}

static cFunctionType *_getFunction(const char *funcname, int argcount)
{
    cFunctionType *functype = findFunction(funcname,argcount);
    if (!functype)
        throw new cRuntimeError("Function %s with %d args not found", funcname, argcount);
    return functype;
}

static cChannel *_createChannel(const char *channeltypename)
{
    cChannelType *channeltype = findChannelType(channeltypename);
    if (!channeltype)
        throw new cRuntimeError("Channel type %s not found", channeltypename);
    cChannel *channel = channeltype->create("channel");
    return channel;
}

static cChannel *_createNonTypedBasicChannel(double delay, double error, double datarate)
{
    cBasicChannel *channel = new cBasicChannel("channel");
    if (delay!=0) channel->setDelay(delay);
    if (error!=0) channel->setError(error);
    if (datarate!=0) channel->setDatarate(datarate);
    return channel;
}

static cXMLElement *_getXMLDocument(const char *fname, const char *pathexpr=NULL)
{
    cXMLElement *node = ev.getXMLDocument(fname, pathexpr);
    if (!node)
        throw new cRuntimeError(!pathexpr ? "xmldoc(\"%s\"): element not found" : "xmldoc(\"%s\", \"%s\"): element not found",fname,pathexpr);
    return node;
}

ModuleInterface(RandomNumberSimulationModule)
EndInterface

Register_ModuleInterface(RandomNumberSimulationModule);

class RandomNumberSimulationModule : public cCompoundModule
{
  public:
    RandomNumberSimulationModule() : cCompoundModule() {}
  protected:
    virtual void doBuildInside();
};

Define_Module(RandomNumberSimulationModule);

void RandomNumberSimulationModule::doBuildInside()
{
    cModule *mod = this;

    // temporary variables:
    cPar tmpval;
    const char *modtypename;

    mod->setBackgroundDisplayString("b=364,225");

    // submodules:
    cModuleType *modtype = NULL;
    int submodindex;

    //
    // submodule 'startSim':
    //
    int startSim_size = 1;
    modtype = _getModuleType("StartModule");
    cModule *startSim_p = modtype->create("startSim", mod);
    {
        cContextSwitcher __ctx(startSim_p); // do the rest in this module's context

        _readModuleParameters(startSim_p);
        startSim_p->setDisplayString("p=48,112;i=block/departure");
    }

    //
    // submodule 'rngGenerator':
    //
    int rngGenerator_size = 1;
    modtype = _getModuleType("GenerateRandomNumbers");
    cModule *rngGenerator_p = modtype->create("rngGenerator", mod);
    {
        cContextSwitcher __ctx(rngGenerator_p); // do the rest in this module's context

        _readModuleParameters(rngGenerator_p);
        rngGenerator_p->setDisplayString("p=180,112;i=device/cpu");
    }

    //
    // submodule 'endSim':
    //
    int endSim_size = 1;
    modtype = _getModuleType("Sink");
    cModule *endSim_p = modtype->create("endSim", mod);
    {
        cContextSwitcher __ctx(endSim_p); // do the rest in this module's context

        _readModuleParameters(endSim_p);
        endSim_p->setDisplayString("p=312,116;i=block/arrival");
    }

    //
    // connections:
    //
    cGate *srcgate, *destgate;

    cChannel *channel;
    cPar *par;
    // connection
    srcgate = _checkGate(startSim_p, "gout");
    destgate = _checkGate(rngGenerator_p, "gin");
    srcgate->connectTo(destgate);

    // connection
    srcgate = _checkGate(rngGenerator_p, "gout");
    destgate = _checkGate(endSim_p, "gin");
    srcgate->connectTo(destgate);

    // check all gates are connected:
    mod->checkInternalConnections();


    //
    // this level is done -- recursively build submodules too
    //
    startSim_p->buildInside();
    rngGenerator_p->buildInside();
    endSim_p->buildInside();
}

class SimPract2 : public cNetworkType
{
  public:
    SimPract2(const char *name) : cNetworkType(name) {}
    SimPract2(const SimPract2& n) : cNetworkType(n.name()) {operator=(n);}
    virtual void setupNetwork();
};

Define_Network(SimPract2);

void SimPract2::setupNetwork()
{
    // temporary variables:
    cPar tmpval;
    const char *modtypename;

    cModuleType *modtype;

    modtype = _getModuleType("RandomNumberSimulationModule");
    cModule *SimPract2_p = modtype->create("SimPract2", NULL);

    cContextSwitcher __ctx(SimPract2_p); // do the rest in this module's context
    _readModuleParameters(SimPract2_p);
    // build submodules recursively (if it has any):
    SimPract2_p->buildInside();
}

