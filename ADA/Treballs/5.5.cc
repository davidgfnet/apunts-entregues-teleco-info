
// Exercici 5.6 modificat per a que mostri tots els subconjunts
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

bool criteri (int a, int b) { return a > b; }

bool millor (vector <int> a, vector <int> b) {
	int tam = a.size();
	if (b.size() < tam) tam = b.size();
	for (int i = 0; i < tam; i++) {
		if (a > b) return true;
		else if (a < b) return false;
	}
	return a.size() > b.size();
}

vector <int> combinacio ( const vector <int> &llista, int select, int nentrada, int triats,int necessaris, vector <int> actual , int sumadeseada, int acum) {
	if (triats == necessaris) {
		if (acum != sumadeseada) return vector <int>();
		
		// Ordenar!
		sort (actual.begin(), actual.end(),criteri);
		return actual;
	}else{
		// Dels que queden en triem un
		vector <int> solucio;
		for (int i = select; i < nentrada; i++) {
			actual.push_back(llista[i]);
			vector <int> temp = combinacio ( llista, i+1, nentrada, triats+1, necessaris, actual ,sumadeseada, acum + llista[i]);
			if (temp.size() != 0) {
				if (millor(temp, solucio)) solucio = temp;
			}
			actual.pop_back();
		}
		return solucio;
	}
}

int main () {
	int suma, nentrada;
	cin >> suma >> nentrada;
	vector <int> llista (nentrada);
	for (int i = 0; i < nentrada; i++) cin >> llista[i];

	vector <int> solucio;
	for (int nsortida = 0; nsortida <= nentrada; nsortida++) {
		vector <int> temp;
		vector <int> sol = combinacio ( llista, 0, nentrada , 0, nsortida, temp, suma, 0);
		if (millor(sol, solucio)) solucio = sol;

	}

	if (solucio.size() != 0) {
		cout << "{";
		for (int i = 0; i < solucio.size(); i++) {
			if (i != solucio.size()-1) cout << solucio[i] << ",";
			else cout << solucio[i];
		}
		cout << "}" << endl;
	}else{
		cout << "SENSE SOLUCIO" << endl;
	}
}


