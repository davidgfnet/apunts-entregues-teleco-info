#include <stdio.h>
#include <limits.h>

int CopyLSB(int a);
int TestCopyLSB(int a);

main (int argc, char *argv[])
{
   int vtest[10] = {1, -1, 0, INT_MIN, INT_MAX, 7, -13, 34, 9, 3000};
   int i;
   int xxxx, test;
   int error;

   error = 0;
   for (i=0; i<10; i++) {
       xxxx = CopyLSB(vtest[i]);
       test = TestCopyLSB(vtest[i]);
       if (xxxx != test) error++; 
     }
  
   if (!error)
     printf("\n\nLa funcion programada funciona correctamente.\n\n");
   else
     printf("\n\nSe han producido %d errores.\n\n", error);
}

int TestCopyLSB (int a) 
{
      return (a&0x1) ? -1 : 0;
}

int CopyLSB(int a)
{
   /*  Esta funcion copia el bit menos significativo de a en todos los bits
    *  ejemplo: CopyLSB(5) = 0xFFFFFFFF, CopyLSB(8) = 0
    *  
    *  Operadores Legales: ! ~ & ^ | + << >>
    *  Numero máximo de operadores: 5
    *  Nivel de dificultad: 2
    */

   a = a << 31;
   a = a >> 31;

   return a;
}
