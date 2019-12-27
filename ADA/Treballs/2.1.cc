
/* Leemos el grafo y lo guardamos usando una estructura de listas
   Después lanzamos un DFS. Si encontramos algun ciclo (elemento visitado
   más de una vez no es un arbol. Si al acabar queda nodos por visitar
   el grafo no es conexo, lo que implica que no es un arbol.      */

#include <iostream>
#include <vector>

using namespace std;

bool lanza_DSF (int nodo, int anterior, const vector < vector <int> > & grafo, vector <bool> & vistos) {
	if (vistos[nodo]) {
		return true; // Ya visto, no es un arbol, contiene un ciclo
	}else{
		vistos[nodo] = true;
		for (int i = 0; i < grafo[nodo].size(); i++) {
			if (anterior != grafo[nodo][i]) 
				if (lanza_DSF (grafo[nodo][i],nodo,grafo,vistos)) return true;
		}
		return false;
	}
}

int main () {
	int n;
	while (cin >> n) {

		vector <bool> vistos (n);
		vector < vector <int> > grafo (n);

		// Crear el grafo O(n+e)
		for (int i = 0; i < n; i++) vistos[i] = false;

		for (int i = 0; i < n; i++) {
			int n2;
			cin >> n2;
			// Añadimos esto para avisar que vamos a añadir n2 elementos al vector
			grafo[i].reserve(n2);
			for (int j = 0; j < n2; j++) {
				int tmp;
				cin >> tmp;
				grafo[i].push_back(tmp);
			}
		}

		// Lanzamos un DFS i miramos si tiene ciclos O(n+e) 
		bool noarbol = lanza_DSF (0,-1,grafo,vistos);
		
		// Comprovar si es conexo. O(n)
		for (int i = 0; i < n; i++) 
			if (vistos[i] == false) {
				noarbol = true;
				break;
			}

		if (noarbol) cout << "NO es un arbre" << endl;
		else cout << "es un arbre" << endl;
	}
	
}




