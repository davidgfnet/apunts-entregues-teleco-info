#include "elemento.h"

int Buscar(S1 v[], int x, int N){

   int low, high, mid;
   int trobat;
  
   /* búsqueda alternada */
   low = 0;
   mid = low;
   high = N-1;
   while (low <= high) {
 	trobat = BuscarElemento(&low, &high, &mid, x, v);
	if (trobat >= 0) break;
   }
   return trobat;
}

