#include <stdio.h>
#include <limits.h>

int IsGreater(int a, int b);
int TestIsGreater(int a, int b);

main (int argc, char *argv[])
{
   int vtest[10] = {1, -1, 0, INT_MIN, INT_MAX, 7, -13, 34, 9, 3000};
   int i, j;
   int xxxx, test;
   int error;

   error = 0;
   for (i=0; i<10; i++)
     for (j=0; j<10; j++) {
       xxxx = IsGreater(vtest[i], vtest[j]);
       test = TestIsGreater(vtest[i], vtest[j]);
       if (xxxx != test) error++;
     }
  
   if (!error)
     printf("\n\nLa funcion programada funciona correctamente.\n\n");
   else
     printf("\n\nSe han producido %d errores.\n\n", error);
}

int TestIsGreater (int a, int b) 
{
   return (a > b);
}

int IsGreater(int a, int b)
{
   /* Esta funcion devuelve 1 si a>b y 0 en caso contrario.
    *  ejemplo: IsGreater(7,3) = 1, IsGreater(3,7) = 0
    *  Operadores legales : ! ~ & ^ | + << >>º 
    *  Numero máximo de operadores: 24 
    *  Nivel de dificultad: 3
    */

	// Restem A + ~B + 1
	// Ja que es Major estricte restem 1!
	
	long long temp = (long long)a + (~(long long)b);
	temp = temp >> 63;
	temp = ~ temp;
	temp = temp & 0x1;

	return temp;
}

