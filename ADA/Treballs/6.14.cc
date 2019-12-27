
/* Dado un estado del solitario probaremos todas las combinaciones posibles.
   Para toda posicion con piedra que se puede desplazar modificamos la tabla, 
   llamamos recursivamente para ese nuevo tablero i al acabar deshacemos el cambio
   para poder probar con otras piedras antes que con ésa. El coste es muy elevado 
   ya que cada llamada busca piedras O(n²).
*/

#include <iostream>
#include <vector>

using namespace std;


int backtrack(vector <bool> &taula, int n, int numb) {
	if (numb == 1) {
		// Fi!!! Buscar si esta en medio
		if ((n % 2 == 1) and (taula[(n/2)*n + n/2]) ) return 3;
		else return 1;
	}
	// Buscamos todos los movimientos posibles
	int sol = 0;
	for (int i = 0; i < n; i++) {	
		for (int j = 0; j < n; j++) {
			// Si hay piedra...
			if (taula[i*n+j]) {
				// Si se puede mover a la derecha ...
				if (j+2 < n) {
					if (taula[i*n+j+1] and not taula[i*n+j+2]) {
						taula[i*n+j+2] = true; taula[i*n+j+1] = false; taula[i*n+j] = false;
						sol = sol | backtrack (taula,n,numb-1);
						taula[i*n+j+2] = false; taula[i*n+j+1] = true; taula[i*n+j] = true; // Restaura estat
					}
				}
				// Si se puede mover a la izqda ...
				if (j-2 >= 0) {
					if (taula[i*n+j-1] and not taula[i*n+j-2]) {
						taula[i*n+j-2] = true; taula[i*n+j-1] = false; taula[i*n+j] = false;
						sol = sol | backtrack (taula,n,numb-1);
						taula[i*n+j-2] = false; taula[i*n+j-1] = true; taula[i*n+j] = true; // Restaura estat
					}
				}
				// Si se puede mover arriba ...
				if (i-2 >= 0) {
					if (taula[(i-1)*n+j] and not taula[(i-2)*n+j]) {
						taula[(i-2)*n+j] = true; taula[(i-1)*n+j] = false; taula[i*n+j] = false;
						sol = sol | backtrack (taula,n,numb-1);
						taula[(i-2)*n+j] = false; taula[(i-1)*n+j] = true; taula[i*n+j] = true; // Restaura estat
					}
				}
				// Si se puede mover abajo ...
				if (i+2 < n) {
					if (taula[(i+1)*n+j] and not taula[(i+2)*n+j]) {
						taula[(i+2)*n+j] = true; taula[(i+1)*n+j] = false; taula[i*n+j] = false;
						sol = sol | backtrack (taula,n,numb-1);
						taula[(i+2)*n+j] = false; taula[(i+1)*n+j] = true; taula[i*n+j] = true; // Restaura estat
					}
				}
				if (sol == 3) return 3;
			}
		}
	}
	return sol;
}


int main () {
	int n;
	cin >> n;

	vector <bool> taula (n*n);
	int numb = 0;

	for (int i = 0; i < n; i++) {	
		for (int j = 0; j < n; j++) {
			char tmp;
			cin >> tmp;
			taula[i*n+j] = (tmp == 'P');
			if (tmp == 'P') numb++;
		}
	}

	int sol = backtrack (taula,n,numb);
	// Ultimo bit: hay solucion. Penultimo: es maca
	
	if (sol == 0) cout << "no te solucio" << endl;
	else if (sol == 1) cout << "te solucio" << endl;
	else  cout << "te solucio maca" << endl;
}




