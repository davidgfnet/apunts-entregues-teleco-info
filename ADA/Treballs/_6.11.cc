/*
   Dado que sudoku hecho completamente por backtracking es un problema muy largo 
   aÃ±adimos algunas optimizaciones. Primero buscamos alguna casilla que estÃ© forzada a tener un nÃºmero concreto.
   Una vez hemos rellenado esas casilla probamos las demÃ¡s con sus posibles nÃºmeros.
*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

typedef vector < vector <int> > sudoku ;
bool operator<(const sudoku & a, const sudoku & b) {
    for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (a[i][j] < b[i][j]) return true;
		}
	}

	return false;
}

// Junta dos vectores
void anade (vector <sudoku> &a, vector <sudoku> b) {
	for (int i = 0; i < b.size(); i++) a.push_back(b[i]);
}

// Dice si un numero puede ir en una casilla dada
bool compat ( const vector < vector <int> > & taula, int row, int col, int num) {
	// Comprobar fila, columna y cuadro
	for (int i = 0; i < 9; i++) if (taula[i][col] == num) return false;
	for (int i = 0; i < 9; i++) if (taula[row][i] == num) return false;
	int crow = row /3;
	int ccol = col /3;
	for (int i = crow*3; i < (crow+1)*3; i++) {
		for (int j = ccol*3; j < (ccol+1)*3; j++) {
			if (taula[i][j] == num) return false;
		}
	}
	return true;
}

// Devuelve el Ãºnico nÃºmero que puede ir en esa casilla o 0 si hay mÃ¡s de uno
// Asume que la casilla por la que preguntamos estÃ¡ a 0, si no falla!
int num ( const vector < vector <int> > & taula, int row, int col ) {
	bool tempo[10];
	for (int i = 0; i < 10; i++) tempo[i] = true;

	for (int i = 0; i < 9; i++) tempo[ taula[i][col] ] = false;
	for (int i = 0; i < 9; i++) tempo[ taula[row][i] ] = false;

	int crow = row /3;
	int ccol = col /3;
	for (int i = crow*3; i < (crow+1)*3; i++) {
		for (int j = ccol*3; j < (ccol+1)*3; j++) {
			tempo[ taula[i][j] ] = false;
		}
	}

	int num = 0;
	for (int i = 1; i < 10; i++) if (tempo[i]) num++;
	
	if (num == 0) return -1; // Este caso cubre el caso de una casilla donde no puede ir ningun numero!
	if (num > 1) return 0; // No podem saber quin nombre va!

	for (int i = 1; i < 10; i++) if (tempo[i]) return i;
	return 0;
}

vector <sudoku> backtrack (sudoku & taula, int numzeros , int fila, int columna) {
	vector <sudoku> ret;
	if (numzeros == 0) {
		// Es soluciÃ³n!
		ret.push_back (taula);
		return ret;
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (taula[i][j] == 0) {
				int numero = num (taula, i,j);
				if (numero == -1) return ret;  // No tiene solucion este sudoku!
				if (numero != 0) {
					taula[i][j] = numero;
					ret = backtrack (taula, numzeros-1,fila,columna);
					taula[i][j] = 0;
					return ret;
				}
			}
		}
	}

	// Probar las restantes con sus posibles nÃºmeros
	while (taula[fila][columna] != 0) {
		fila++;
		if (fila == 9) { fila = 0; columna++; }
	}

	for (int k = 1; k <= 9; k++) {
		if (compat (taula,fila,columna,k)) {
			taula[fila][columna] = k;
			anade (ret, backtrack (taula,numzeros-1,fila,columna) ); // anade las soluciones a las ya encontradas
			taula[fila][columna] = 0;  // Deshacer cambios
		}
	}
	return ret;	
}

bool igual (sudoku a, sudoku b)  {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (a[i][j] != b[i][j]) return false;
		}
	}
	return true;
}


int main () {
	vector < vector <int> > taula (9);
	for (int i = 0; i < 9; i++) taula[i] = vector <int> (9);

	int numzeros = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			char a;
			cin >> a;
			while (not (a >= '0' and a <= '9') ) cin >> a;
			taula[i][j] = int (a - '0');
			if (taula[i][j] == 0) numzeros++;
		}
	}

	vector <sudoku> sol = backtrack (taula,numzeros,0,0);
	if (sol.size() != 0) {
		// Eliminar soluciones repetidas y ordenarlas
		sort (sol.begin(), sol.end());
		vector <sudoku> sol2;
		sol2.push_back (sol[0]);

		for (int i = 1; i < sol.size(); i++)
			if (not igual(sol[i],sol[i-1]))
				sol2.push_back (sol[i]);

		for (int k = 0; k < sol2.size(); k++) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					cout << sol2[k][i][j];
					if (j != 8) cout << " ";
					if (j == 2 or j == 5) cout << "| ";
				}
				cout << endl;
				if (i == 2 or i == 5) cout << "---------------------" << endl;
			}
			cout << endl;
		}
	}else{
		cout << "sense solucio" << endl;
	}
}

