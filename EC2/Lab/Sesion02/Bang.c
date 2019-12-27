#include <stdio.h>
#include <limits.h>

int Bang(int a);
int TestBang(int a);

main (int argc, char *argv[])
{
   int vtest[10] = {1, -1, 0, INT_MIN, INT_MAX, 7, -13, 34, 9, 3000};
   int i;
   int xxxx, test;
   int error;

   error = 0;
   for (i=0; i<10; i++) {
       xxxx = Bang(vtest[i]);
       test = TestBang(vtest[i]);
       if (xxxx != test) error++; 
     }
  
   if (!error)
     printf("\n\nLa funcion programada funciona correctamente.\n\n");
   else
     printf("\n\nSe han producido %d errores.\n\n", error);
}

int TestBang (int a) 
{
      return (!a);
}

int Bang(int a)
{
   /*  Esta funcion calcula !x
    *  ejemplo: Bang(3)=0, Bang(0)=1
    *  
    *  Operadores Legales: ~ & ^ | + << >>
    *  Numero máximo de operadores: 12
    *  Nivel de dificultad: 4
    */

   return a + (~a) + 1;

}
