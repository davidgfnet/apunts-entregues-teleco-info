
function smith

freq=1:10000:2e9;
z0=50;
r=25;
c=10e-12;
l=10e-9;
w=2*3.1415*freq;

% R-C paralel
zin=1./((1./r)+(j*w*c));
pin=(zin-z0)./(zin+z0);
p=smithchart(pin)
set (p,'LineWidth',3);
hold on;

% R-L paralel
zin=1./((1./r)+1./(j*w*l));
pin=(zin-z0)./(zin+z0);
p=smithchart(pin)
set (p,'LineWidth',3);
hold on;

% L-C paralel
zin=1./((1./(j*w*l))+(j*w*c));
pin=(zin-z0)./(zin+z0);
p=smithchart(pin)
set (p,'LineWidth',3);
hold on;

% R-C serie
zin=r+1./(j*w*c);
pin=(zin-z0)./(zin+z0);
p=smithchart(pin)
set (p,'LineWidth',3);
hold on;

% L-R serie
zin=r+j*w*l;
pin=(zin-z0)./(zin+z0);
p=smithchart(pin)
set (p,'LineWidth',3);
hold on;

% L-C serie
zin=1./(j*w*c)+j*w*l;
pin=(zin-z0)./(zin+z0);
p=smithchart(pin)
set (p,'LineWidth',3);
hold on;

end