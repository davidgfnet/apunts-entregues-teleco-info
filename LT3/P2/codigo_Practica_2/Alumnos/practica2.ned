import
    "simple_modules";

module RandomNumberSimulationModule
    submodules:
        startSim: StartModule;
            display: "p=48,112;i=block/departure";
        rngGenerator: GenerateRandomNumbers;
            display: "p=180,112;i=device/cpu";
        endSim: Sink;
            display: "p=312,116;i=block/arrival";
    connections:
        startSim.gout --> rngGenerator.gin;
        rngGenerator.gout --> endSim.gin;
    display: "b=364,225";
endmodule

network SimPract2 : RandomNumberSimulationModule
endnetwork

