
// Exercici 5.6 modificat per a que mostri tots els subconjunts
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

void combinacio ( const vector <int> &llista, int select, int nentrada, int triats,int necessaris, vector <int> actual , int sumadeseada) {
	if (triats == necessaris) {
		int suma = 0;
		for (int i = 0; i < actual.size(); i++) suma += actual[i];
		if (suma != sumadeseada) return;
		cout << "{";
		for (int i = 0; i < actual.size(); i++) {
			if (i != actual.size()-1) cout << actual[i] << ",";
			else cout << actual[i];
		}
		cout << "}" << endl;
	}else{
		// Dels que queden en triem un
		for (int i = select; i < nentrada; i++) {
			actual.push_back(llista[i]);
			combinacio ( llista, i+1, nentrada, triats+1, necessaris, actual ,sumadeseada );
			actual.pop_back();
		}
	}
}

int main () {
	int suma, nentrada;
	cin >> suma >> nentrada;
	vector <int> llista (nentrada);
	for (int i = 0; i < nentrada; i++) cin >> llista[i];

	for (int nsortida = 0; nsortida <= nentrada; nsortida++) {
		vector <int> temp;
		combinacio ( llista, 0, nentrada , 0, nsortida, temp, suma);
	}
}


