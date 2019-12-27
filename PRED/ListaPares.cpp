/*

		    Pr�ctica 1
	Programaci�n y Estructuras de Datos

	Jose Alejandro Cordero Rama   (41001129 - H)
	David Guill�n Fandos	      (47756680 - D)

	En esta pr�ctica comprobamos m�ltiples veces si cabezalc == NULL, es decir
	si existe una lista V1 de la cual cuelga una lista circular vac�a.
	Con las funciones especificadas en el enunciado este caso NO se puede NUNCA, y por tanto
	no es necesario comprobarlo  (NUNCA puede producirse ya que mediante las operaciones 
        constructoras de la clase no puede formarse un nodo1 cuya lista circular sea nula).
	
	A�n as� se hace esta comprobaci�n en repetidas ocasiones pensando en una hipot�tica ampliaci�n 
        de la clase, en la cual existieran funciones que pudieran generar elementos de tipo lista V1 cuya
        lista circular fuese nula.

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
};


// Pre: inicio es un nodo NO NULO de una lista circular simplemente enlazada
nodo2 * maximo (nodo2 * inicio) {
	nodo2 * max = inicio;
	nodo2 * primero = inicio;

	inicio = inicio->sig2;

	while (max->x2 <= inicio->x2 and inicio != primero) {
		// Inv: max es un puntero al nodo maximo en las iteraciones anteriores
		max = inicio;
		inicio = inicio->sig2;
	}

	return max;
}
// Post: devuelve el �ltimo nodo2 con valor m�ximo de la lista

// Pre: n es un nodo de una lista circular que se quiere borrar con saltos de m pasos
// y ant es el nodo anterior a n
nodo2 * suprimir_internal (nodo2 * n, int m, nodo2 * ant) {
	if (n->sig2 == n) {  // Caso base, lista 1 s�lo elemento
		n->sig2 = NULL;
		return n;
	}

	// HI: n contiene una lista que no ha sido borrada todav�a
	// y la funci�n devuelve la lista en el orden de borrado.

	// Se borra el nodo en la posici�n m y se crea una sublista con 
	// los nodos no borrados. Por HI obtendremos una lista con los nodos
	// borrados, a la cual a�adiremos el nodo que hemos borrado.

	nodo2 * borrar = n;
	nodo2 * anterior = ant;
	for (int i = 1; i < m; i++) {
            borrar = borrar->sig2;		// borrar es el elemento a quitar
	    anterior = anterior->sig2;	        // ant sigue apuntando al elemento anterior a borrar
        }
        //Inv: no hemos llegado al m-�simo nodo

	anterior->sig2 = borrar->sig2; 	// eliminamos el elemento

	// por HI obtendremos la lista de borrado a la que le a�adimos el nodo que hemos borrado
	borrar->sig2 = suprimir_internal (anterior->sig2 ,m , anterior);
	
	return borrar;
}
// Post: Devuelve una lista con los nodos de n borrados con saltos de m pasos

class ListaPares
{
public:
	nodo1 * primero;

	// Pre: -
	void insertar (string V1, int V2) {
		nodo1 * p = primero;

		if (p == NULL) {   // Caso base, lista vac�a
			p = new nodo1;
			p->sig1 = NULL;
			p->cabezalc = NULL;
			p->x1 = V1;
			primero = p;
		}else{
			if (p->x1 > V1) {   // Se a�ade al principio dado que es menor a todos
				nodo1 * nuevo = new nodo1;
				nuevo->x1 = V1;
				nuevo->sig1 = p;
				nuevo->cabezalc = NULL;
				p = nuevo;
				primero = p;
			}else{  // Buscamos el nodo
				nodo1 * anterior = NULL;
				while (p != NULL) {
					// Inv:  Los elementos anteriores a p no contienen V1 y son todos menores a V1

					if (p->x1 == V1) break; // Ya existe en la lista, no hace falta insertarlo
					if (p->x1 > V1) break;	// No est�
					anterior = p;
					p = p->sig1;
				}
				if (p == NULL) {  // No hemos encontrado V1, lo a�adimos al final ya que es mayor al resto
					nodo1 * nuevo = new nodo1;
					anterior->sig1 = nuevo;
					nuevo->sig1 = NULL;
					nuevo->cabezalc = NULL;
					nuevo->x1 = V1;
					p = nuevo;
				}else if (p->x1 > V1) {
					nodo1 * nuevo = new nodo1;
					nuevo->x1 = V1;
					nuevo->cabezalc = NULL;
					nuevo->sig1 = p;
					anterior->sig1 = nuevo;
					p = nuevo;
				}
			}
		}
		// En este punto p apunta al nodo1 de la lista que vale V1

		if (p->cabezalc == NULL) {  // Caso base, lista vac�a. Hemos insertado V1 y de �l no cuelga ning�n nodo todav�a
			p->cabezalc = new nodo2;
			p->cabezalc->sig2 = p->cabezalc;
			p->cabezalc->x2 = V2;
		}else{  		// Lista2 no vac�a
			nodo2 * inicial = p->cabezalc;
			
			// Buscamos el �ltimo valor m�ximo y el m�nimo
			nodo2 * max = maximo(p->cabezalc);
			nodo2 * min = max->sig2;  // Si max es el �ltimo m�ximo, como la lista est� ordenada y es circular, obtenemos el m�nimo

			if (V2 >= max->x2 or V2 <= min->x2) {  // Lo a�adimos al final, puesto que es mayor o menor al resto
				p->cabezalc = max;
			}else{ // Buscamos en qu� posici�n deber�a ir
				nodo2 *anterior = p->cabezalc, *siguiente = p->cabezalc->sig2;
				while ( not (anterior->x2 <= V2 and siguiente->x2 >= V2) ) {
					anterior = anterior->sig2;
					siguiente = siguiente->sig2;
				}
				p->cabezalc = anterior;
			}

			// insertamos V1 despu�s de p->cabezalc
			nodo2 * nuevo = new nodo2;
			nuevo->sig2 = p->cabezalc->sig2;
			p->cabezalc->sig2 = nuevo;
			p->cabezalc = nuevo;
			nuevo->x2 = V2;
		}
	}
	// Post: Se ha a�adido un nodo2 de valor V2 en la lista que cuelga del nodo que vale V1 manteniendo el orden de las listas
	// y cabezalc apunta al nuevo nodo2 a�adido

	// Pre: -
	nodo2* suprimir (string V1, int m) {
		nodo1 * temp = primero;
		nodo1 * anterior = NULL;
		while (temp != NULL) {  // Buscamos a V1 y guardamos el anterior
			// Inv: todos los nodos anteriores a temp no contienen V1 y son menores a �ste
			if (temp->x1 == V1) break;
			if (temp->x1 > V1) return NULL;  // V1 no est� en la lista
			anterior = temp;
			temp = temp->sig1;
		}
		if (temp == NULL) return NULL;  // V1 no est� en la lista

		nodo2 * lista2 = temp->cabezalc;

		// Eliminar nodo1
		if (anterior == NULL) { // es el primero de la lista
			primero = primero->sig1;
			delete temp;
		}else{
			anterior->sig1 = temp->sig1;
			delete temp;
		}

		nodo2 * ant = lista2;
		while (ant->sig2 != lista2) ant = ant->sig2;
                //Inv: ant no apunta al elemento anterior al apuntado por lista2

		// Obtenemos la lista en el orden de borrado por la postcondici�n de "suprimir_internal"
		lista2 = suprimir_internal( lista2, m, ant);

		return lista2;
	}
	// Post: Ha sido eliminado de la lista general el nodo cuyo valor es V1. Devuelve
	// una lista de nodo2 que contiene los nodos de la lista circular del nodo eliminado 
	// en el orden de borrado

	// Pre: -
	bool estan (string V1, int V2) {
		nodo1 * temp1 = primero;
		while (temp1 != NULL) {
			// Inv: Los elementos ya recorridos no contienen V1 y son menores a �ste
			if (temp1->x1 > V1) return false;  // V1 no est�
			if (temp1->x1 == V1) {  // V1 est�
				nodo2 * temp2 = temp1->cabezalc;
				if (temp2 != NULL) {
					if (temp2->x2 == V2) return true;
					nodo2 * anterior = temp2;
					temp2 = temp2->sig2;
					if (temp2->x2 == V2) return true;  // Garantizamos la primera iteraci�n del invariante
					while (temp2 != temp1->cabezalc and not ( (anterior->x2 <= V2) and (V2 <= temp2->x2) ) ) {
						// Inv: cabezalc es el inicio de la lista y todav�a no hemos llegado al final de �sta.
						// V2 no est� en lo ya recorrido ni puede estar ya que no hemos encontrado ninguna posici�n v�lida
						// para �l ( cabezalc < V1 < temp2) 
						anterior = temp2;
						temp2 = temp2->sig2;
						if (temp2->x2 == V2) return true;
					}
				}
				return false;
			}
			temp1 = temp1->sig1;
		}
		return false;
	}
	// Post: Devuelve si existe una lista que vale V1 y de ella cuelga una que contiene V2 

	// Pre: -
	int menor(string V1) {
		if (primero == NULL) return 9999;  // Lista vac�a

		nodo1 * temp = primero;
		
		while (temp != NULL) {
			// Inv: Los elementos ya recorridos no contienen V1 y son menores a �ste
			if (temp->x1 == V1) break;
			if (temp->x1 > V1) return 9999;  // No est�
			temp = temp->sig1;
		}
		if (temp == NULL) return 9999;  // No est� y V1 es mayor a todos

		if (temp->cabezalc == NULL) return 9999;

		nodo2 * min = maximo (temp->cabezalc)->sig2;

		return min->x2;
	}
	// Post: Devuelve el menor elemento que cuelga de V1 o 9999 si V1 no se encuentra
	// en la lista

};



