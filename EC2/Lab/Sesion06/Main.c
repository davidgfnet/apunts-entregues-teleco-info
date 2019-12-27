#include <stdio.h>

void PrintBase(unsigned int x, unsigned int b);

main(int argc, char *argv[]) 
{  
   int x, base; 

  if (argc == 3){ 

    x = atoi(argv[1]); /* elemento a escribir en pantalla */
    base = atoi(argv[2]); /* base */
    printf("El numero %d en base %d es: ", x, base);    
    PrintBase(x, base); 
  }
  else
    printf ("\nERROR: hay que indicar el numero a escribir y la base.\n\n");
}

