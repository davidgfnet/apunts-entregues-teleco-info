/*

		    Práctica 1
	Programación y Estructuras de Datos

	Jose Cordero Rama 	(XXXXXXXX - X)
	David Guillen Fandos	(47756680 - D)

*/

#include <iostream>
#include <string>

using namespace std;


class nodo2 {
public:
	int x2;
	nodo2* sig2;
};


class nodo1 {
	friend class nodo2;
public:
	string x1;
	nodo2 * cabezalc;
	nodo1 * sig1;

	void insertar (string V1, int V2);
	nodo2 * suprimir (string V1, int m);
	bool estan (string V1, int V2);
};

class ListaPares {

}



