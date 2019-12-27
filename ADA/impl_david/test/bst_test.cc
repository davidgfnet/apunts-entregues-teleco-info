

#include <iostream>
#include "bst.h"

using namespace std;

int main () {
	BST <int,int> arbol;
	arbol.insert (1,0);
	arbol.insert (11,0);
	arbol.insert (22,0);
	arbol.insert (34,0);
	arbol.insert (93,0);
	arbol.insert (49,0);
	arbol.insert (12,0);
	arbol.insert (42,0);
	arbol.insert (45,0);
	arbol.insert (5,0);
	arbol.insert (3,0);
	arbol.insert (2,0);

	for (int i = 1; i < 14; i++) {
		arbol.print_level(i);	std::cout << endl;
	}

	arbol.remove (1);
	arbol.remove (11);
	arbol.remove (22);
	arbol.remove (34);
	arbol.remove (93);
	arbol.remove (49);
	arbol.remove (12);
	arbol.remove (42);
//	arbol.remove (45);
	arbol.remove (5);
	arbol.remove (3);
	arbol.remove (2);

	for (int i = 1; i < 14; i++) {
		arbol.print_level(i);	std::cout << endl;
	}

}


