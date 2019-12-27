
function estadistica( v )

    fprintf('Mitjana: %d\n',mean(v))
    fprintf('Mediana: %d\n',median(v))
    fprintf('Variança: %d\n',var(v));
    fprintf('Període: %d\n',seqperiod(v));

    figure('Name','Correlació');
    plot(xcorr(v))

    figure('Name','Histograma');
    hist(v,100)

    figure('Name','Dispersió 2D');
    plot(v(1:length(v)-1),v(2:length(v)),'.')

    figure('Name','Dispersió 3D');
    plot3(v(1:length(v)-2),v(2:length(v)-1),v(3:length(v)),'.')

end