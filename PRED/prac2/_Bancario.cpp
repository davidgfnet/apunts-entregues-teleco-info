/*
		    	Práctica 2
	Programación y Estructuras de Datos

	David Guillen Fandos	      (47756680 - D)
	Jose Alejandro Cordero Rama   (41001129 - H)

*/

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Fhash{
public:
	static int h (string c) {
		int suma = 0;
		for (unsigned int i = 0; i < c.size(); i++) suma += c[i];
		return suma % 23;
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
	Nodo *siguiente;	// Enlace a otra cuenta sinónima de cuenta según la función h
};

class titular {
public:
	string NIF;
	titular *siguiente;	// Enlace a otro titular de cuenta
	Cuenta *cuenta;		// Enlace a la cuenta de la que NIF es titular
	titular *mismo_hash;	// Enlace a un objeto titular sinónimo de NIF respecto a h (posiblemente con el mismo NIF)
};

class Bancario {
private:
	vector <Nodo*> TablaCuentas;   // si la la i-ésima posición no está vacía entonces
				                   // apunta a un nodo n tal que la imagen de n->cuenta según h es i
				                   // Desde TablaCuentas[i] y mediante el enlace "siguiente" de cada Nodo tenemos acceso
				                   // a todas las Cuentas sinónimas de n
	vector <titular*> TablaTitulares; // si la i-ésima posición no está vacía entonces
	 				                  // apunta a un titular t tal que la imagen de t->NIF según h es i
	 				                  // Desde TablaTitulares[i] y mediante el enlace "mismo_hash" de cada Titular tenemos
	 				                  //acceso a todos los titulares sinónimos de t
public:
	Bancario () {
		TablaCuentas = vector <Nodo*> (23);
		TablaTitulares = vector <titular*> (23);
		for (int i = 0; i < 23; i++) TablaCuentas[i] = NULL;
		for (int i = 0; i < 23; i++) TablaTitulares[i] = NULL;
	}

	// PRE: -
	void incluir (string banco, string id_cuenta, string NIF) {
		// Buscamos entre las cuentas con misma imagen de hash que la cuenta buscada
		int hash = Fhash::h (banco + id_cuenta);
		Nodo * temp = TablaCuentas[hash];

		// INV: temp apunta a un nodo con misma imagen de hash que la cuenta buscada. La cuenta buscada no ha sido
		// encontrada en la lista de cuentas anteriores a temp. 2 condiciones de salida: no apuntamos a un nodo con
		// la misma imagen de hash, de modo que habremos acabado de recorrer la lista y podremos afirmar que no hemos
		// encontrado la cuenta buscada o bien hemos encontrado la cuenta.
		while (temp != NULL) {
			if (temp->cuenta.banco == banco and temp->cuenta.id_cuenta == id_cuenta) break;
			temp = temp->siguiente;   // garantizamos la siguiente iteración
		}

		if (temp == NULL) {				// No está. Añadimos la cuenta
			Nodo * node = new Nodo;			// Crear un nodo
			node->cuenta.banco = banco;
			node->cuenta.id_cuenta = id_cuenta;
			node->cuenta.L_titulares = NULL;	// Sin ningún titular
			temp = node;
			temp->siguiente = TablaCuentas[hash];	// Enlazar con la tabla de hash de cuentas
			TablaCuentas[hash] = temp;
		}

		// Ahora añadimos el titular a la lista
		titular * tit = temp->cuenta.L_titulares;
		//INV: tit apunta a un titular de cuenta y diferente a los apuntados hasta el momento. Ninguno de los titulares 
		// apuntados hasta el momento es el que pretendemos añadir. Saldremos si hemos recorrido toda la lista o si encontramos
		// el titular que pretendemos añadir.
		while (tit != NULL) {
			if (tit->NIF == NIF) {
				cout << "El titular ya existe en la cuenta!" << endl;      //no añadimos nada, ya estaba anteriormente
				return;
			}
			tit = tit->siguiente;
		}

		titular * temp2 = temp->cuenta.L_titulares;
		temp->cuenta.L_titulares = new titular;
		temp->cuenta.L_titulares->siguiente = temp2;
		temp->cuenta.L_titulares->NIF = NIF;
		temp->cuenta.L_titulares->cuenta = &temp->cuenta;
		
		// añadimos el titular a la posición de TablaTitulares que le corresponde.
		int hash2 = Fhash::h (NIF);
		temp->cuenta.L_titulares->mismo_hash = TablaTitulares[hash2];
		TablaTitulares[hash2] = temp->cuenta.L_titulares;		// Enlazar con la tabla de hash de titulares
	}
	// POST: se ha añadido el titular a la cuenta. En caso de que ya existiera el titular se muestra un mensaje de error. Las dos
	// tablas de hash han sido actualizadas de forma que cumplan con la especificación.

/*	Justificación:
	La función es correcta y no se modifica la estructura al finalizar. En caso de no existir la cuenta se crea una y se enlaza con la tabla de hash 
	de manera que TablaCuentas[i] apunta a la nueva cuenta (donde i es el hash de cuenta). Las demás cuentas siguen siendo accesibles a través de
	TablaCuentas[i]->siguiente. Dado que la estructura anterior era válida, la nueva lo será, ya que es la misma más un elemento enlazado con la tabla
	y la anterior estructura.
	Añadimos un titular que es apuntado por cuenta->L_titulares. En caso de haber más titulares éstos pasaran a ser apuntados por 
	cuenta->L_titulares->siguiente. Tampoco hemos realizado ningún cambio en la estructura, todos los titulares son accesibles.
	Para poder acceder al titular vía NIF hacemos que TablaTitulares[i] apunte al titular (donde i es el hash del titular) y para poder seguir 
	accediendo a los demás titulares sinónimos enlazamos el primero con el campo mismo_hash.
*/

	// PRE: -
	void elimina_cuenta(string banco,string id_cuenta) {		
		// Buscamos la lista de cuentas
		int hash = Fhash::h (banco + id_cuenta);
		Nodo * temp = TablaCuentas[hash];
		Nodo * nodo_anterior = NULL;

	    if (temp!= NULL) {
		  if(temp->cuenta.banco != banco or temp->cuenta.id_cuenta != id_cuenta) {   //este if permite que se cumpla el INV la primera iteración
		    nodo_anterior = temp;                        
		    temp = temp->siguiente;
		    // INV: temp apunta a una cuenta sinónima de la cuenta que buscamos. Dicha cuenta no ha sido apuntada por temp 
		    // hasta el momento; anterior->siguiente apunta a temp. Salimos cuando temp apunta a la cuenta buscada o si 
		    // recorremos la lista entera sin encontrarla.
		    while (temp != NULL) {
		    	   if (temp->cuenta.banco == banco and temp->cuenta.id_cuenta == id_cuenta) break;
		    	   nodo_anterior = temp;
		 	   temp = temp->siguiente;
		    }
		  }
	    }

		// la cuenta no ha sido encontrada
		if (temp == NULL) {
			cout << "Error: cuenta inexistente" << endl;
			return;
		}
		// Procedemos a eliminar los titulares que cuelgan de la cuenta
		titular * tit = temp->cuenta.L_titulares;

		// INV: tit apunta a un titular de cuenta. Los titulares a los que tit ha apuntado anteriormente han sido borrados.
		// La única condición de salida es que totos los titulares de cuenta hayan sido borrados.
		while (tit != NULL) {
			titular * siguiente = tit->siguiente;
			// Eliminamos el titular. Buscaremos en la lista de sinónimos de tit->NIF.
			int hash2 = Fhash::h (tit->NIF);
			titular * actual = TablaTitulares[hash2];
			// si es el primero de la lista:
			if (actual->NIF == tit->NIF and actual->cuenta->banco == temp->cuenta.banco and
					actual->cuenta->id_cuenta == temp->cuenta.id_cuenta) {
		        
				TablaTitulares[hash2] = TablaTitulares[hash2]->mismo_hash;
				delete actual;
			}
			else{
				titular * anterior = actual;
				actual = actual->mismo_hash;

				// INV: actual apunta a un nodo sinónimo de tit->NIF. Anterior->siguiente apunta a actual. actual no ha apuntado
				// hasta el momento al titular que buscamos para borrarlo. La única condición de salida es que el titular
				// haya sido encontrado (no cabe la posibilidad de que el titular no esté).
				while (not (actual->NIF == tit->NIF and actual->cuenta->banco == temp->cuenta.banco and 
						actual->cuenta->id_cuenta == temp->cuenta.id_cuenta) ) {

					actual = actual->mismo_hash;
					anterior = anterior->mismo_hash;
				}
				anterior->mismo_hash = actual->mismo_hash;
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
	//POST: la cuenta ha sido eliminada, así como todos sus titulares. En caso de que la cuenta no existiera se ha mostrado un
	// mensaje de error.

/*	Justificación:
	La función es correcta y no se modifica la estructura al finalizar.
	Eliminamos la cuenta deseada y mantemos las demás accesibles. Para ello enlazamos la cuenta que apuntaba a la que vamos a borrar con la 
	siguiente de ésta. En caso de ser la primera, es decir, TablaCuentas[i] apunta a la cuenta (donde i es el hash de la cuenta), TablaCuentas[i]
	pasará a apuntar a la siguiente cuenta (TablaCuentas[i] = TablaCuentas[i]->siguiente).
	Eliminaremos todos los titulares de esa cuenta, pero sólo de esa, ya que puede ser que un titular tenga otras cuentas.
	Para ello por cada titular recorreremos toda su lista de simónimos (apuntada por TablaTitulares[i], donde i es el hash del titular)
	y borraremos el titular. Para hacerlo enlazaremos su sinónimo anterior con su sinónimo siguiente, manteniendo la estructura. En el caso de
	ser el primero de la lista entonces TablaTitulares[i] apuntará a TablaTitulares[i]->mismo_hash.
	Por ello garantizamos que la eliminación de una cuenta cumple la especificación, ya que la estructura sigue siendo la misma.
*/


	//PRE: -
	void consulta_titulares (string banco,string id_cuenta) {
		// Buscamos la lista que contiene la lista de cuentas cuya imagen según h es la misma que la cuenta que buscamos
		int hash = Fhash::h (banco + id_cuenta);
		Nodo * temp = TablaCuentas[hash];
	
		// INV: temp apunta en todo momento a una cuenta sinónima de (banco+id_cuenta). No hemos encontrado la cuenta buscada
		// en ninguna cuenta anterior a la que actualmente es apuntada por temp. Si salimos del bucle se dan dos casos posibles:
		// hemos encontrado la cuenta que buscábamos o dejamos de apuntar a una cuenta sinónima (se acaba la lista de cuentas
		// sinónimas, es decir, apuntamos a NULL)
		while (temp != NULL) {
			if (temp->cuenta.banco == banco and temp->cuenta.id_cuenta == id_cuenta) break;   //cuenta encontrada
			temp = temp->siguiente;                                    // garantizamos el invariante en la siguiente iteración
		}

		if (temp == NULL) {	              // Si no está
			cout << "Error: cuenta inexistente" << endl;
			return;
		}
		// en caso de que la hayamos encontrado
		titular * tit = temp->cuenta.L_titulares;               // garantizamos primera iteración
		//INV: tit apunta a un titular de cuenta. La única condición de salida es que hayamos recorrido la lista de titulares
		// de cuenta completamente   (necesario para cumplir la POST de consulta_titulares).
		while (tit != NULL) {
			cout << tit->NIF << endl;
			tit = tit->siguiente;       //garantizamos siguiente iteración
		}
	}
	//POST: han sido escritos todos los titulares de la cuenta descrita por 'banco' e 'id_cuenta' en caso de estar en la lista.
	// en caso contrario se imprime un mensaje de error.

/*	JUSTIFICACIÓN:
	La función incluir garantiza que en TablaCuentas enlazados mediante 'siguiente' 
	se encuentran todas las cuentas con la misma imagen que banco+cuenta según la función h.
	Dado que recorremos toda la lista si la cuenta buscada existe, estará en esa lista y la encontraremos, si no simplemente llegaremos al 
	final y mostraremos un error.
	Una vez tengamos la cuenta, como incluir nos garantiza que L_titulares apunta a la lista de titulares de esa cuenta, la recorreremos e 
	imprimiremos todos los titulares, como garantiza el invariante.
*/



	// PRE: -
	void consulta_cuentas (string p) {
		// Calculamos el índice de p en la tabla de hash de Titulares
		int hash = Fhash::h (p);
		// temp apunta al primer titular de la lista que cuelga de la 'hash-ésima' posición de TablaTitulares
		titular * temp = TablaTitulares[hash];
		
		// INV: temp apunta a un titular cuyo NIF es sinónimo de p según la función 'h'; hemos imprimido la información de las
		// cuentas de las que p es titular de la lista recorrido hasta el momento y aún no hemos recorrido 
		// toda la lista de titulares que son sinónimos de p segun h.
		while (temp != NULL) {
			if (temp->NIF == p) {
				cout << temp->cuenta->banco << " " << temp->cuenta->id_cuenta << endl;
			}    // si encontramos a p en la lista de titulares imprimimos la información 
				 // referente a su cuenta
			temp = temp->mismo_hash;  //garantizamos que se cumpla el INV en la próxima iteración
		}
	}
	// POST: han sido impresas todas las cuentas de las que p es titular. 

/*	JUSTIFICACIÓN:
	La función incluir garantiza que en TablaTitulares enlazados mediante 'mismo_hash' 
	se encuentran todos los titulares con la misma imagen que p según la función h. Como p es sinónimo de p
	según h y como recorremos la lista hasta que ésta acaba, podemos asegurar que hemos imprimido TODAS las cuentas
	de las que p es titular 
*/
	
};

/*
 
 especificacion:
 	Bancario
 tipos:
 	Bancario, Cuenta, Titular, Lista_Titulares, Lista_Cuentas
 
 operaciones:	
		
 	Crear: -> Bancario
 	Incluir: Bancario x Cuenta x Titular -> Bancario
 	Eliminar: Bancario x Cuenta -> Bancario
 	consulta_titulares: Bancario x Cuenta -> Lista_titulares
 	consulta_cuentas: Bancario x Titular -> Lista_cuentas
 
 axiomas:

	incluir( incluir ( B, C, T), C, T) = incluir (B, C, T)

 	Eliminar( incluir ( B, C, T), C) = Eliminar ( B, C)
	Eliminar( Crear (), C ) = Crear ()
	Eliminar( incluir ( B, C1, T1), C) = incluir ( eliminar ( B, C), C1, T1)	
	
	Consulta_titulares( Crear(), C ) = []
	Consulta_titulares( incluir( B, C, T), C) ) = [ Consulta_titulares( B, C ) | T ]
	Consulta_titulares( incluir( B, C1, T1), C) = Consulta_titulares ( B, C)
	
	consulta_cuentas( Crear(), T) = []
	consulta_cuentas( incluir ( B, C, T), T) ) = [ consulta_cuentas( B, T ) | C ]
	consulta_cuentas( incluir ( B, C1, T1), T) ) = consulta_cuentas( B, T )
 
 ---
 
 	Se ha elegido una implementación de la estructura mediante dos tablas de hash con encadenamiento. De éste modo conseguimos que 
 	las dos operaciones de consulta sean prácticamente inmediatas. La TablaCuentas permite un acceso directo a todas las cuentas
 	sinónimas gracias a una lista enlazada en que "siguiente" conecta cada nodo con el siguiente. La TablaTitulares permite a su vez
 	acceso directo a todos los titulares cuyo NIF sea sinónimo según h (añadimos para ello dos enlaces a la clase Titulares: uno que 
 	apunta a la cuenta de la que es titular, para poder imprimir dicha información rápidamente y otro que apunta a otro titular con 
 	la misma imágen de hash).
	Eliminar y incluir no presentan una mejora temporal excesivamente espectacular, ya que debemos buscar y modificar ambas tablas
	de hash.
 	Sin embargo, decidimos apostar por esta estructuración que nos aporta unos mecanismos de consulta muy rápidos y de inclusión y
 	supresión que podrían ser mejores con otra implementación.

	OBSERVACIÓN: a la hora de implementar las funciones de consulta no devuelven ninguna lista, esa "lista" representa los elementos
	impresos.
	 	
 ---
 
 		-> Invariante <-	
 	Para toda 0 <= i < 23 se cumple que TablaCuentas[i] apunta a NULL o bien a un Nodo n tal que la imagen de hash de n->cuenta = i.
 	Cada nodo n apunta a otra cuenta cuya imagen de hash según h es i o bien a NULL mediante el enlace "siguiente". El enlace L_titulares
 	apunta a un titular de la cuenta.
 	Los titulares, a su vez, cuentan con un campo 'siguiente' que apunta a otro titular de la misma cuenta.
 	Ningún nodo es apuntado por más de un enlace "siguiente". No hay ninguna cuenta repetida en la estructura.
 	
 	Para toda 0 <= i < 23 se cumple que TablaCuentas[i] apunta a NULL o a bien a un titular t tal que la imagen de hash de t->NIF = i.
 	Cada t apunta a su vez mediante el enlace 'mismo_hash' a otro titular con i como imágen de hash o a NULL.
 	Ningún titular es apuntado por más de un enlace "mismo_hash". Puede haber en TablaTitulares[i] varios titulares con el mismo NIF, sin
 	embargo no apuntana la misma cuenta.
 	
 	El invariante siempre se cumple:
 		->caso base : justo despues de inicializar la estructura, para cada 0 <= i < 23, Ventas.tabla[i] apunta NULL, de modo que
 		se cumple nuestro invariante.
 		->suponiendo que el invariante se cumple, antes de INCLUIR una nueva cuenta/titular se dan dos casos:
 			a) la cuenta no está en la estructura. Se cumple el invariante pues al añadirlo no estará repetido.
 			b) Si la cuenta ya estaba en la estructura, se cumple el invariante respecto a las cuentas ya que no hay ninguna modificación.
 			  En cualquiera de los casos, respecto al titular:
				1) no está en la estructura: se añade y por tanto no hay repetición de ninguna clase. Al añadirlo al inicio... bla bla bla sigue cumpliendo, joder
				2) está en la estructura: no haces nada, se sigue cumpliendo.
???? 		->suponiendo que el invariante se cumple antes de realizar una ELIMINACIÓN de una cuenta se dan dos casos:
???? 			a) La cuenta no está en la estructura: no hacemos nada y por tanto se sigue cumpliendo el invariante
???? 			b) Si la cuenta ya estaba en la estructura, se cumple el invariante. La cuenta será eliminada y también la lista de titulares
???? 			   de dicha cuenta manteniendo los enlaces de forma que el invariante siga cumpliéndose.    // QUIZA PODRIAMOS PONERLO E LA POST DE ALGNA FORMA Y PONER AQUI... POR LA POST. A CASCARLA!
 		->ninguna de las operaciones de consulta modifica Bancario, de modo que si el invariante se cumplía al inicio, seguirá
		 cumpliéndose.	
 ---
 
 		-> Equivalencia <-
 	Dos estructuras Bancario son equivalentes si para todo 0 <= i < 23 se tiene que:
			Bancario1.TablaTitulares[i]  y   Bancario2.TablaTitulares[i]
		contienen los mismos titulares, aunque tal vez en diferente órden.
			Bancario1.TablaCuentas[i]    y   Bancario2.TablaCuentas[i]
		contienen los mimos nodos, aunque tal vez en diferente órden.
	En dos estructuras Bancario equivalentes las dos operaciones de consulta muestran la misma información, aunque quizá
	en diferente órden una de la otra.
 
 ---
 
 	Finalmente podemos ver que la implementacion cumple con los axiomas de la representacion :	


		incluir( incluir ( B, C, T), C, T) = incluir (B, C, T)
	Si se pretende incluir un titular ya existente en una determinada cuenta, entonces no realizamos ninguna modificación con lo cual el axioma se cumple.

		Eliminar( Crear (), C ) = Crear ()
	si eliminamos C de un Bancario vacío, Bancario no es modificado. Se cumple el axioma
		Eliminar( incluir ( B, C1, T1), C) = incluir ( eliminar ( B, C), C1, T1)
	si eliminamos C de Bancario, Bancario sigue conteniendo todas las cuentas diferentes de C y todos los titulares que no sean titulares de C. Con lo cual el axioma se cumple.
	 	Eliminar( incluir ( B, C, T), C) = Eliminar( B, C)
	si eliminamos una cuenta de la estructura, ni C ni ninguna otra referencia a C ni a sus titulares se mantendrá en Bancario. Por tanto se cumple el axioma.

		Consulta_titulares( Crear(), C ) = []
	si el titular no está en la lista, no imprimimos nada. Por tanto el axioma se cumple.
		Consulta_titulares( incluir( B, C, T), C) ) = [ Consulta_titulares( B, C ) | T ]
	si consultamos titulares de C y T es titular de C, T forma parte de los titulares impresos. Por tanto el axioma se cumple.
		Consulta_titulares( incluir( B, C1, T1), C) = Consulta_titulares ( B, C)
	si consultamos titulares de C, ningun titular de una cuenta que no sea C será impreso. Por tanto el axioma se cumple.
	
		consulta_cuentas( Crear(), T) = []
	si la cuenta no está en la lista, no imprimimos nada. Por tanto el axioma se cumple.
		consulta_cuentas( incluir ( B, C, T), T) ) = [ consulta_cuentas( B, T ) | C ]
	si consultamos cuentas de T y T es titular de C, C forma parte de las cuentas impresas. Por tanto el axioma se cumple.
		consulta_cuentas( incluir ( B, C1, T1), T) ) = consulta_cuentas( B, T )
	si consultamos cuentas de T, ninguna cuenta de la que T no sea titular será impresa. Por tanto el axioma se cumple

*/
