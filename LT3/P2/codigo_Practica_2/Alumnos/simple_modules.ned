
simple StartModule
    gates:
        out: gout;
endsimple
simple GenerateRandomNumbers
    parameters:
        number_of_random_numbers: numeric, //Number of random numbers to be generated
        num_of_bars: numeric, //Number of classes in the histogram
        random_variable: numeric; //Type of random variable to generate
    gates:
        in: gin;
        out: gout;
endsimple
simple Sink
    gates:
        in: gin;
endsimple

