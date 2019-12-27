/***************************************************
		PRED - Práctica 1
***************************************************/

#include "practica.h"
#include <iostream>
#include <string>

// { Pre: - }
void nodo1::insertar (string V1, int V2) {
	nodo1 * p = this;
	nodo2 * p2 = NULL;
	while (p != NULL) {
		if (p->x1 == V1) {  // Lo hemos encontrado
			p2 = p->cabezalc;
			break;
		}
		p = p->sig1;
	}
	if (p2 == NULL) {  // No existe tal nodo, lo creamos. last contiene un puntero al ultimo elemento
		p = new nodo1;
		p->x1 = V1;
		p->sig1 = this->sig1;    // primer_nodo -> nuevo_nodo -> siguientes
		p->cabezalc = NULL;
		this->sig1 = p;
		p2 = NULL;
	}

	if (p2 == NULL) {  // La lista circular es vacía
		p2 = new nodo2;
		p2->x2 = V2;
		p2->sig2 = p2;
		p->cabezalc = p2;
	}else{ // No es vacía
		nodo2 * p3 = new nodo2;
		p3->x2 = V2;
		p3->sig2 = p2->sig2;  // P2 -> P3 -> P2_siguiente
		p2->sig2 = p3;
		p->cabezalc = p3;
	}
}
// { Post: V2 ha sido añadido al nodo1 que tiene valor V1 o ha sido creado en caso de no existir,
//   la cabeza de dicho nodo apunta a ese nuevo nodo2 añadido }

// { Pre: n es un nodo2 y m es el desplazamiento de borrado}
nodo2 * suprimir_internal (nodo2 * n, int m) {
	// Si la lista sólo contiene un elemento
	if (n->sig2 == n) return n;

	nodo2 * borrar = n;
	nodo2 * anterior = n;
	for (int i = 1; i < m; i++) borrar = borrar->sig2;	// borrar es el elemento a quitar
	// buscamos su elemento anterior
	while (anterior->sig2 != n) anterior = anterior->sig2;
	
	// eliminamos el elemento
	anterior->sig2 = borrar->sig2;

	borrar->sig2 = suprimir_internal (n,m);
	// Borrar es la cabeza de una lista simplemente enlazada 
	// y cuyo ultimo elemento tiene como siguiente él mismo
	nodo2 * temp = borrar;
	while (temp->sig2 != temp) temp = temp->sig2;
	temp->sig2 = borrar;  // Cerramos la lista
	
	return borrar;
}
// { Post: la función devuelve una lista de nodos borrados en el orden de borrado }


// { Pre: m es el desplazamiento de borrado}
nodo2 * nodo1::suprimir (string V1, int m) {
	nodo1 * temp = this;
	while (temp != NULL) {
		if (temp->x1 == V1) break;
		temp = temp->sig1;
	}
	if (temp == NULL) return NULL;  // No encontrado

	return suprimir_internal (temp->cabezalc , m);
}
// { Post: la función devuelve una lista de nodos borrados en el orden de borrado
//   que pertenecen a la lista circular que cuelga de aquella lista general cuyo valor es V1 (si la hay) }

bool nodo1::estan (string V1, int V2) {
	nodo1 * n1 = this;
	while (n1 != NULL) {
		if (n1->x1 == V1) {
			// Buscar ahora en la lista circular
			if (n1->cabezalc == NULL) return false;
			nodo2 * n2 = n1->cabezalc;
			while (n2->sig2 != n1->cabezalc) {  // Mientras no volvamos al principio
				if (n2->x2 == V2) return true;
				n2 = n2->sig2;
			}

			return false;
		}
		n1 = n1->sig1;
	}
	return false;
}


