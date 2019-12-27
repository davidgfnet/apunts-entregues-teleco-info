
// Exercici 5.6 modificat per a que mostri tots els subconjunts
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

void combinacio ( const vector <string> &llista, int select, int nentrada, int triats,int necessaris, vector <string> actual ) {
	if (triats == necessaris) {
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
			combinacio ( llista, i+1, nentrada, triats+1, necessaris, actual );
			actual.pop_back();
		}
	}
}

int main () {
	int nentrada;
	cin >> nentrada;
	vector <string> llista (nentrada);
	for (int i = 0; i < nentrada; i++) cin >> llista[i];

	for (int nsortida = 0; nsortida <= nentrada; nsortida++) {
		vector <string> temp;
		combinacio ( llista, 0, nentrada , 0, nsortida, temp);
	}
}


