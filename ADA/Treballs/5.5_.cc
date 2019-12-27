
// Exercici 5.6 modificat per a que mostri tots els subconjunts
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

vector <int> solucio ( const vector <int> & llista, int i, int j ) {
	
}

int main () {
	int suma, nentrada;
	cin >> suma >> nentrada;
	vector <int> llista (nentrada);
	for (int i = 0; i < nentrada; i++) cin >> llista[i];

	
	vector <int> sol = solucio ( llista, llista.size(), suma );
}


