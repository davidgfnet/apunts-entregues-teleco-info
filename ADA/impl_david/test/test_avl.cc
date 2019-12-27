

#include <iostream>
#include "avl.h"

using namespace std;

int main () {
	AVL<int,int> arbol;

	for (int i = 0; i < 20; i++) {
		arbol.insert (i,0);
	}

	for (int i = 1; i < 6; i++) {
		arbol.print_level(i);	std::cout << endl;
	}
	for (int i = 4; i < 16; i++) {
		arbol.remove (i);

	for (int i = 1; i < 6; i++) {
		arbol.print_level(i);	std::cout << endl;
	}


	}

/*
	arbol.insert (4,0);
	arbol.insert (3,0);
	arbol.insert (1,0);
	arbol.insert (7,0);
	arbol.insert (6,0);
	arbol.insert (8,0);
	arbol.insert (10,0);
	arbol.insert (2,0);
	arbol.insert (9,0);
	arbol.insert (5,0);
*/

	for (int i = 1; i < 6; i++) {
		arbol.print_level(i);	std::cout << endl;
	}


}



