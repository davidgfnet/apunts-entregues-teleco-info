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

// Pre: -
nodo1 * buscar (nodo1 * inicio, string V1) {
	while (inicio != NULL) {
		if (inicio->x1 == V1) return inicio;  // Lo encontramos
		if (inicio->sig1 != NULL) {  // No estamos al final todavía
			if (inicio->sig1->x1 > V1) return inicio;   // Devolvemos el anterior
		}else{
			return inicio;  // Devolvemos el último nodo ya que V1 es mayor a todos los de la lista
		}

		inicio = inicio->sig1;
	}
	return inicio;
}
// Post: Devuelve un puentro al nodo que vale V1, o si no está devuelve un puntero al que tiene un valor anterior en la lista

// Pre: -
nodo2 * maximo (nodo2 * inicio) {
	nodo2 * max = inicio;
	bool primero = true;
	while (max->x2 < inicio->x2 or primero) {
		primero = false;
		max = inicio;
		inicio = inicio->sig2;
	}
	return max;
}
// Post: devuelve el nodo2 con valor máximo de la lista

// Pre: -
nodo2 * suprimir_internal (nodo2 * n, int m) {
	// Si la lista sólo contiene un elemento
	if (n->sig2 == n) return n;

	cout << "CACA" << endl;

	nodo2 * borrar = n;
	nodo2 * anterior = n;
	for (int i = 1; i < m; i++) borrar = borrar->sig2;	// borrar es el elemento a quitar
	// buscamos su elemento anterior
	while (anterior->sig2 != borrar) anterior = anterior->sig2;
	
	// eliminamos el elemento
	anterior->sig2 = borrar->sig2;

	borrar->sig2 = suprimir_internal (anterior->sig2,m);
	
	return borrar;
}
// Post:

class ListaPares
{
public:
	nodo1 * primero;

	ListaPares() { primero = NULL; }
	~ListaPares()  {}

	// Pre: -
	void insertar (string V1, int V2) {
		nodo1 * p = buscar(primero, V1);

		if (p == NULL) {  // Caso base, lista vacía
			p = new nodo1;
			p->sig1 = NULL;
			p->cabezalc = NULL;
			p->x1 = V1;
			primero = p;
		}else{
			// p es el anterior o el siguiente donde deberíamos añadir
			if (p->x1 > V1) {   // añadir tras este
				nodo1 * nuevo = new nodo1;
				nuevo->x1 = V1;
				nuevo->sig1 = p->sig1;
				nuevo->cabezalc = NULL;
				p->sig1 = nuevo;
				p = nuevo;
			}else if (p->x1 < V1) {  // añadir al principio de todo
				nodo1 * nuevo = new nodo1;
				nuevo->x1 = V1;
				nuevo->cabezalc = NULL;
				nuevo->sig1 = p;
				p = nuevo;
			}
		}
		// En este punto p apunta al nodo1 de la lista que vale V1

		if (p->cabezalc == NULL) {  // Lista 2 vacía
			p->cabezalc = new nodo2;
			p->cabezalc->sig2 = p->cabezalc;  // La lista debe ser circular
			p->cabezalc->x2 = V2;
		}else{  // Lista2 no vacía
			nodo2 * inicial = p->cabezalc;
			
			// Buscamos el maximo
			nodo2 * max = maximo(p->cabezalc);
			nodo2 * min = max->sig2;  // Esto se cumple siempre!

			if (V2 > max->x2 or V2 < min->x2) {  // Lo añadimos al final, puesto que es mayor o menor al resto
				p->cabezalc = max;
			}else{ // Buscamos en qué posicion debería ir
				nodo2 *anterior = p->cabezalc, *siguiente = p->cabezalc->sig2;
				while ( not (anterior->x2 < V2 and siguiente->x2 > V2) ) {
					anterior = anterior->sig2;
					siguiente = siguiente->sig2;
				}
				p->cabezalc = anterior;
			}

			// p->cabezalc apunta al anterior de V2
			nodo2 * nuevo = new nodo2;
			nuevo->sig2 = p->cabezalc->sig2;
			p->cabezalc->sig2 = nuevo;
			p->cabezalc = nuevo;
			nuevo->x2 = V2;
		}
	}
	// Post: Se ha añadido un nodo2 de valor V2 en la lista que cuelga del nodo 

	// Pre: -
	nodo2* suprimir (string V1, int m) {
		nodo1 * temp = primero;
		nodo1 * anterior = NULL;
		while (temp != NULL) {
			if (temp->x1 == V1) break;
			anterior = temp;
			temp = temp->sig1;
		}
		if (temp == NULL) return NULL;

		nodo2 * lista2 = temp->cabezalc;

		// Eliminar nodo1
		if (anterior == NULL) { // es el primero de la lista
			primero = primero->sig1;
			delete temp;
		}else{
			anterior->sig1 = temp->sig1;
			delete temp;
		}

		lista2 = suprimir_internal( lista2 , m);

		// lista2 es la cabeza de una lista simplemente enlazada 
		// y cuyo ultimo elemento tiene como siguiente él mismo
		nodo2 * temporal = lista2;
		while (temporal->sig2 != temporal) temporal = temporal->sig2;
		temporal->sig2 = lista2;  // Cerramos la lista
		
		return lista2;

	}
	// Post: 

	// Pre: -
	bool estan (string V1, int V2) {
		nodo1 * temp1 = primero;
		while (temp1 != NULL) {
			if (temp1->x1 > V1) break;
			if (temp1->x1 == V1) {
				nodo2 * temp2 = temp1->cabezalc;
				if (temp2 != NULL) {
					do {
						if (temp2->x2 == V2) return true;
						temp2 = temp2->sig2;
					} while (temp2 != temp1->cabezalc);
				}
				temp1 = temp1->sig1;
				return false;
			}
		}
		return false;
	}
	// Post: Devuelve si existe una lista que vale V1 y de ella cuelga una que contiene V2 

	// Pre: -
	int menor(string V1) {
		nodo1 * temp = primero;
		
		while (temp != NULL) {
			if (temp->x1 == V1) break;
			temp = temp->sig1;
		}

		if (temp == NULL) return 9999;
		if (temp->cabezalc == NULL) return 9999;

		nodo2 * min = maximo (temp->cabezalc)->sig2;

		return min->x2;
	}
	// Post: Devuelve el menor elemento que cuelga de V1 o 9999 en su defecto

};


