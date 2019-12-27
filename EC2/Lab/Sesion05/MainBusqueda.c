#include <stdio.h>
#include "elemento.h"


int BuscarElemento(int *low, int *high, int *mid, int xx, S1 v[]);
int Buscar(S1 v[], int x, int N);


main(int argc, char *argv[]) 
{  
   int a=1, b=27;
   S1 v[20] = {{'3', 2, &a}, {'r', 4, &b}, {'y', 6, &a}, {'8', 7, &b}, {'x', 8, &a}, {'z', 14, &b}, {'p', 15, &a}, {'$', 21, &b}, {'r', 32, &a}, {'+', 44, &b}, {'y', 45, &a}, {'%', 49, &b}, {'g', 54, &a}, {'b', 57, &b}, {'m', 61, &a}, {'q', 64, &b}, {'!', 67, &a}, {'-', 78, &b}, {'i', 88, &a}, {'z', 91, &b}};
	       

   int trobat;
   int x; 

  if (argc == 2){ 
    x = atoi(argv[1]); /* elemento a buscar */
  
     /* Invocar la función de búsqueda */
     trobat = Buscar(v, x, 20);
 
     if (trobat >= 0) 
       printf("\nEncontrado elemento %d en la posicion %d con valor %c \n\n", x, trobat, v[trobat].c);
     else
       printf("\nNO encontrado elemento %d\n\n", x);
  }
  else
    printf ("\nERROR: hay que indicar el elemento a buscar\n\n");
}

