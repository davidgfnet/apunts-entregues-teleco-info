#include <stdio.h>
#include <limits.h>

int Sum3(int a, int b, int c);
int TestSum3(int a, int b, int c);

main (int argc, char *argv[])
{
   int vtest[10] = {1, -1, 0, INT_MIN, INT_MAX, 7, -13, 34, 9, 3000};
   int i, j, k;
   int xxxx, test;
   int error;

   error = 0;
   for (i=0; i<10; i++) 
     for (j=0; j<10; j++)
       for (k=0; k<10; k++) {
       xxxx = Sum3(vtest[i], vtest[j], vtest[k]);
       test = TestSum3(vtest[i], vtest[j], vtest[k]);
       if (xxxx != test) error++; 
     }
  
   if (!error)
     printf("\n\nLa funcion programada funciona correctamente.\n\n");
   else
     printf("\n\nSe han producido %d errores.\n\n", error);
}

int TestSum3 (int x, int y, int z) 
{
  return x+y+z;
}

int Sum3(int x, int y, int z)
{
   /*  Sumar x+y+z usando solo una +
    *  ejemplo: Sum3(1,2,3) = 6
    *  Operadores legales : ! ~ & ^ | << >>
    *  Numero máximo de operadores: 16
    *  Nivel de dificultad: 3
    */

    int temp1 = x ^ y;
    int temp2 = x & y; // me llevo una!
    temp2 = temp2 << 1;  // Sumar al siguiente!
    temp1 = temp1 ^ temp2;

   return -1;
}
