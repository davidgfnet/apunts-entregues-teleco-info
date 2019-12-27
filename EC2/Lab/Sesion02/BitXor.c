#include <stdio.h>
#include <limits.h>

int BitXor(int a, int b);
int TestXor(int a, int b);

main (int argc, char *argv[])
{
   int vtest[10] = {1, -1, 0, INT_MIN, INT_MAX, 7, -13, 34, 9, 3000};
   int i, j;
   int xxxx, test;
   int error;

   error = 0;
   for (i=0; i<10; i++)
     for (j=0; j<10; j++) {
       xxxx = BitXor(vtest[i], vtest[j]);
       test = TestXor(vtest[i], vtest[j]);
       if (xxxx != test) error++; 
     }
  
   if (!error)
     printf("\n\nLa funcion programada funciona correctamente.\n\n");
   else
     printf("\n\nSe han producido %d errores.\n\n", error);
}

int TestXor (int a, int b) 
{
   return (a ^ b);
}

int BitXor(int a, int b)
{
   /*  Calculad a ^ b 
    *  ejemplo: BitXOr(7,3) = 4
    *  Operadores legales : ~ & 
    *  Numero máximo de operadores: 14 
    *  Nivel de dificultad: 2
    */

   /* Programad la xor bit a bit utilizando unicamente
      los operadores: & y ~  */

   return ~((~((~a)&b))&(~((~b)&a)));

}
