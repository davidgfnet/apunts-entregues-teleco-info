#include <omnetpp.h>

double lt3_rng()
{
	return uniform(0,1); //Función estadística propia de Omnet
}

double lt3_exponencial(double media)
{
	return -media*log(1-uniform(0,1));
}

double lt3_geometrica(double vmin, double vmax, double media)
{
	// Incluir aquí el código necesario para generar una variable geométrica entre un valor mínimo, "vmin",
        //y un valor máximo, "vmax", con media "media"

	// GEOMETRICA SENSE MAX/MIN
//	int valor = log(1-uniform(0,1))/log(1.0f-1.0f/media);
//	return valor;

	int valor = log(1-uniform(0,1)*pow(1.0f-1.0f/media,vmin))/log(1.0f-1.0f/media);
	while (valor > (vmax-vmin)) {
		valor = log(1-uniform(0,1)*pow(1.0f-1.0f/media,vmin))/log(1.0f-1.0f/media);
	}
	return valor + vmin;


/*        int valor = lt3_exponencial(media);
	if (valor > (vmax-vmin)) valor = vmax-vmin;
	valor += vmin;
	return valor;*/

/*	int valor = lt3_exponencial(media/(vmax-vmin+1));
        while (valor > (vmax-vmin)) {
		valor = lt3_exponencial(media);
	}
	return valor + vmin;*/

/*	int valor = lt3_exponencial(media);
        while (valor > vmax or valor < vmin) {
		valor = lt3_exponencial(media);
	}
	return valor;*/
}


double lt3_normal(double media, double varianza, double metodo)
{
	const double e = 2.718281828f;
	const int n = 12;

	switch ((int)metodo) {
	case 1: {
		double sign = 1.0f;
		if (uniform(-1,1) < 0) sign = -1.0f;
		while (true) {
			double xi = lt3_exponencial(1);
			double ui = uniform(0,1);
			double c = 1.315487709f;  // sqrt(2*e/PI)
			double tx = pow(e,-xi)*c;
			double fx = (1.0f/sqrt(2*M_PI*varianza))*pow(e,-0.5f*((xi-media)*(xi-media)/varianza));

			if (fx/tx >= ui)
				return xi*sign;
		}
	}break;
	case 2: {
		double phi = uniform(0,2*M_PI);
		double r = sqrtf(-2*log(uniform(0,1)));

		double x = r*cos(phi) + media;
		return x;
	}break;
	case 3: {
		double suma = 0;
		for (int i = 0; i < n; i++) {
			suma += uniform(0,1);
		}
		suma -= n/2;
		return suma*sqrtf(varianza)+media;
	}break;
	}
}

double lt3_convolucion_exponencial(double media, double numExp)
{
	int nume = numExp;
	double resultat = 0;
	while (nume--) {
		resultat += lt3_exponencial(media);
	}
	return resultat;
}

double lt3_chi2(double media, double varianza, double k)
{
	int k2 = k;
	double resultat = 0;
	while (k2--) {
		double chi = lt3_normal(media,varianza,1);
		resultat += chi*chi;
	}
	return resultat;
}

Define_Function(lt3_rng, 0);
Define_Function(lt3_exponencial, 1);
Define_Function(lt3_geometrica, 3);
Define_Function(lt3_normal, 3);
Define_Function(lt3_convolucion_exponencial, 2);
Define_Function(lt3_chi2, 3);
