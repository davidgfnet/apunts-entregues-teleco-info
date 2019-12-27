

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Fhash{
public:
	static int h (string c) {
		return c[0] % 23;
	}
};

class titular;

class Cuenta {
public:
	string banco;
	string id_cuenta;
	titular * L_titulares;
};

class Nodo {
public:
	Cuenta cuenta;
	Nodo *siguiente;	// Cuenta siguiente cuando buscamos por hash de cuenta
};

class titular {
public:
	string NIF;
	titular *siguiente;	// Siguiente titular de esa cuenta
	Cuenta *cuenta;		// Enlace a su cuenta
	titular *mismo_hash;	// Enlace a un objeto titular con el mismo hash (posiblemente con el mismo NIF)
};

class Bancario {
private:
	vector <Nodo*> TablaCuentas;
	vector <titular*> TablaTitulares;
	Fhash hasher;

public:
	Bancario () {
		for (int i = 0; i < 23; i++) TablaCuentas[i] = NULL;
		for (int i = 0; i < 23; i++) TablaTitulares[i] = NULL;
	}

	void incluir (string banco, string id_cuenta, string NIF) {
		// Buscamos la lista de cuentas, si existe ya la cuenta añadimos el titular
		int hash = hasher.h (banco + id_cuenta);
		Nodo * temp = TablaCuentas[hash];

		// Inv warro: Salimos cuando encontramos la cuenta o si no la encontramos
		while (temp != NULL) {
			if (temp->cuenta.banco == banco and temp->cuenta.id_cuenta == id_cuenta) break;
			temp = temp->siguiente;
		}

		if (temp == NULL) {	// No está! Añadimos la cuenta 
			Nodo * node = new Nodo;			// Crear un nodo
			node->cuenta.banco = banco;
			node->cuenta.id_cuenta = id_cuenta;
			node->cuenta.L_titulares = NULL;
			temp = node;
		}

		// Ahora añadimos el titular a la lista
		titular * tit = temp->cuenta.L_titulares;
		while (tit != NULL) {
			if (tit->NIF == NIF) {
				cout << "¡El titular ya existe en la cuenta!" << endl;
				return;
			}
			tit = tit->siguiente;
		}

		titular * temp2 = temp->cuenta.L_titulares;
		temp->cuenta.L_titulares = new titular;
		temp->cuenta.L_titulares->siguiente = temp2;
		temp->cuenta.L_titulares->NIF = NIF;
		temp->cuenta.L_titulares->cuenta = &temp->cuenta;
		temp->siguiente = TablaCuentas[hash];		// Enlazar con la tabla de hash de cuentas
		TablaCuentas[hash] = temp;
		
		int hash2 = hasher.h (NIF);
		temp->cuenta.L_titulares->mismo_hash = TablaTitulares[hash2];
		TablaTitulares[hash2] = temp->cuenta.L_titulares;		// Enlazar con la tabla de hash de titulares
	}

	void elimina_cuenta(string banco,string id_cuenta) {
		// Buscamos la lista de cuentas
		int hash = hasher.h (banco + id_cuenta);
		Nodo * temp = TablaCuentas[hash];
		Nodo * nodo_anterior = NULL;

		// Inv warro: Salimos cuando encontramos la cuenta o si no la encontramos
		while (temp != NULL) {
			if (temp->cuenta.banco == banco and temp->cuenta.id_cuenta == id_cuenta) break;
			nodo_anterior = temp;
			temp = temp->siguiente;
		}

		if (temp == NULL) {
			cout << "Error: cuenta inexistente" << endl;
			return;
		}

		// Debemos eliminar primero los titulares que cuelgan de la cuenta
		titular * tit = temp->cuenta.L_titulares;
		while (tit != NULL) {
			titular * siguiente = tit->siguiente;
			// Eliminamos el titular, no es trivial! Buscaremos por NIF y Cuenta y lo quitaremos de la lista
			int hash2 = hasher.h (tit->NIF);
			titular * actual = TablaTitulares[hash2];
			// si es el primero de la lista...
			if (actual->NIF == tit->NIF and actual->cuenta->banco == temp->cuenta.banco and 
					actual->cuenta->id_cuenta == temp->cuenta.id_cuenta) {

				TablaTitulares[hash2] = TablaTitulares[hash2]->mismo_hash;
				delete actual;
			}else{
				titular * anterior = actual;
				actual = actual->siguiente;

				// INV warro! Mientras no lo encontremos...
				while (not (actual->NIF == tit->NIF and actual->cuenta->banco == temp->cuenta.banco and 
						actual->cuenta->id_cuenta == temp->cuenta.id_cuenta) ) {

					actual = actual->siguiente;
					anterior = anterior->siguiente;
				}
				anterior->siguiente = actual->siguiente;
				delete actual;
			}
			tit = siguiente;
		}

		// Ahora eliminamos la cuenta
		if (temp == TablaCuentas[hash]) {  // Es el primer elemento de la lista
			TablaCuentas[hash] = TablaCuentas[hash]->siguiente;
			delete temp;
		}else{
			nodo_anterior->siguiente = temp->siguiente;
			delete temp;
		}
	}

	void consulta_titulares (string banco,string id_cuenta) {
		// Buscamos la lista de cuentas
		int hash = hasher.h (banco + id_cuenta);
		Nodo * temp = TablaCuentas[hash];

		// Inv warro: Salimos cuando encontramos la cuenta o si no la encontramos
		while (temp != NULL) {
			if (temp->cuenta.banco == banco and temp->cuenta.id_cuenta == id_cuenta) break;
			temp = temp->siguiente;
		}

		if (temp == NULL) {	// No está! 
			cout << "Error: cuenta inexistente" << endl;
			return;
		}

		titular * tit = temp->cuenta.L_titulares;
		while (tit != NULL) {
			cout << tit->NIF << endl;
			tit = tit->siguiente;
		}
	}

	void consulta_cuentas (string p) {
		// Calcular hash
		int hash = hasher.h (p);
		titular * temp = TablaTitulares[hash];
		
		while (temp != NULL) {
			if (temp->NIF == p) {
				cout << temp->cuenta->banco << " " << temp->cuenta->id_cuenta << endl;
			}
			temp = temp->mismo_hash;
		}
	}
};



