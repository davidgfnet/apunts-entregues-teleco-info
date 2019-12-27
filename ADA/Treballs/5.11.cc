
// Exercici 5.6 modificat per a que mostri tots els subconjunts
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

void permutacio ( const vector <string> &llista, int triats,int total, vector <string> actual ) {
	if (triats == total) {
		cout << "(";
		for (int i = 0; i < actual.size(); i++) {
			if (i != actual.size()-1) cout << actual[i] << ",";
			else cout << actual[i];
		}
		cout << ")" << endl;
	}else{
		// Dels que queden en triem un
		for (int i = 0; i < llista.size(); i++) {
			actual.push_back(llista[i]);
			permutacio ( llista, triats+1, total, actual );
			actual.pop_back();
		}
	}
}

int main () {
	int nentrada;
	cin >> nentrada;
	vector <string> llista (nentrada);
	for (int i = 0; i < nentrada; i++) cin >> llista[i];

	vector <string> temp;
	permutacio ( llista, 0, nentrada, temp);
}


