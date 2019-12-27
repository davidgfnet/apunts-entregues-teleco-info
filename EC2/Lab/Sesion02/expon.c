#include <stdlib.h>

main (int argc, char *argv[])
{
   int error, i, result, base, exp;

   if (argc != 3)
      error = 1;
   else {
      result = 1;
      base = atoi(argv[1]);  //atoi es una funci¢n que convierte un string en un entero
      exp = atoi(argv[2]);
     if (exp > 0)
         for (i = 0; i < exp; i++)
	    result = result * base;
      error = 0;
      printf("%d elevado a %d es %d \n", base, exp, result);
	     
   }
   return (error);

}

