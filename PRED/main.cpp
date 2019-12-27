
#include <iostream>
#include <string>
#include "ListaPares.cpp"   // Esto no debe hacerse NUNCA! en este caso es para evitar modificar ListaPares.cpp

using namespace std;

void Imprimir (ListaPares &l) {
	cout << " * Imprimir lista ************* " << endl;
	nodo1 * temp1 = l.primero;
	while (temp1 != NULL) {
		nodo2 * temp2 = temp1->cabezalc;
		cout << temp1->x1 << endl;
		if (temp2 != NULL) {
			do {
				cout << temp2->x2 << " ";
				temp2 = temp2->sig2;
			} while (temp2 != temp1->cabezalc);
			cout << endl;
		}
		temp1 = temp1->sig1;
	}
	cout << " ******************************" << endl;
}

void ImprimirMenor (ListaPares  &l, string V1) {
	cout << " MENOR = " << l.menor(V1) << endl;
}

void ImprimirEstan (ListaPares &l, string V1, int V2) {
	cout << " ESTAN = " << int(l.estan(V1,V2)) << endl;
}

void ImprimirEliminar (ListaPares &l , string V1, int m) {
	nodo2 * lista = l.suprimir (V1, m);
	nodo2 * i = lista;
	
	if (lista == NULL) return;

	while (lista != NULL) {
		cout << lista->x2 << endl;
		lista = lista->sig2;
	} 
}

int main () {
	ListaPares lista;
	lista.primero = NULL;
	lista.insertar ("HOLA", 30);
	ImprimirMenor( lista, "HOLA");
	lista.insertar ("HOLA", 20);
	lista.insertar ("HOLA", 10);
	ImprimirMenor( lista, "HOLA");
	lista.insertar ("HOLA", 2);
	lista.insertar ("HOLA", 1);
	ImprimirMenor( lista, "HOLA");
	lista.insertar ("HOLA", 100);
	lista.insertar ("HOLA", 5);
	ImprimirMenor( lista, "HOLA");
	lista.insertar ("HOLA", 1000);
	lista.insertar ("HOLA", 101);
	ImprimirMenor( lista, "HOLA");
	lista.insertar ("HOLA", 300);
	lista.insertar ("HOLA", 300);
	lista.insertar ("HOLA", 100);
	lista.insertar ("HOLA", 2);
	ImprimirMenor( lista, "HOLA");




	Imprimir( lista );
	ImprimirMenor( lista, "HOLA");

	ImprimirEstan( lista, "HOLA", 103);
	ImprimirEstan( lista, "HOLA", 101);


	lista.insertar ("EXEMPLE",1);
	lista.insertar ("EXEMPLE",2);
	lista.insertar ("EXEMPLE",4);
	lista.insertar ("EXEMPLE",3);  // apunta a 3 e???

	Imprimir (lista);

	ImprimirEliminar (lista, "EXEMPLE", 2);

	lista.insertar ("JOSE",1);
//	lista.insertar ("JOSE",2);
	lista.insertar ("JOSE",3);
	lista.insertar ("JOSE",5);
	lista.insertar ("JOSE",6);
	lista.insertar ("JOSE",8);
	lista.insertar ("JOSE",4);
	lista.insertar ("JOSE",7);
	lista.insertar ("JOSE",100);
	lista.insertar ("JOSE",10);

	ImprimirEstan (lista ,"JOSE",2);
	ImprimirEstan (lista ,"JOSE",50);

	lista.insertar ("JOSE2",1);
	lista.insertar ("JOSE2",-1);
	lista.insertar ("JOSE2",9);
	lista.insertar ("JOSE2",4);
	lista.insertar ("JOSE2",4);
	lista.insertar ("JOSE2",4);	
	lista.insertar ("JOSE2",5);
	lista.insertar ("JOSE2",6);
	cout << "separador" << endl;
	ImprimirEstan (lista ,"JOSE2",5);

	ImprimirEliminar (lista, "NOESTA", 2);

}




