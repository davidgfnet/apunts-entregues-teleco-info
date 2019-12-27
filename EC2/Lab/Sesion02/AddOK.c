#include <stdio.h>
#include <limits.h>

int AddOK(int a, int b);
int TestAddOK(int a, int b);

main (int argc, char *argv[])
{
   int vtest[10] = {1, -1, 0, INT_MIN, INT_MAX, 7, -13, 34, 9, 3000};
   int i, j;
   int xxxx, test;
   int error;

   error = 0;
   for (i=0; i<10; i++) 
     for (j=0; j<10; j++) {
       xxxx = AddOK(vtest[i], vtest[j]);
       test = TestAddOK(vtest[i], vtest[j]);
       if (xxxx != test) error++; 
     }
  
   if (!error)
     printf("\n\nLa funcion programada funciona correctamente.\n\n");
   else
     printf("\n\nSe han producido %d errores.\n\n", error);
}

int TestAddOK (int x, int y) 
{
  int sum = x+y;
  return !(x < 0 && y < 0 && sum >= 0) && !(x > 0 && y > 0 && sum <= 0);
}

int AddOK(int x, int y)
{
   /*  Esta función determina si puede calcularse x+y sin que se produzca overflow
    *  ejemplo: AddOK(0x80000000,0x80000000) = 0,
    *           AddOK(0x80000000,0x70000000) = 1, 
    *  Operadores legales : ! ~ & ^ | + << >>
    *  Numero máximo de operadores: 20
    *  Nivel de dificultad: 3
    */

	int sx = x >> 31;
	int sy = y >> 31;

	int ss = ((x+y) >> 31);

	return     ( (~(    (sx & sy & (~ss)) |  ((~sx)&(~sy)&ss)     ) & 0x1 ));
}

