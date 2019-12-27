void PrintChar(char c)
{  printf("%c", c);
}

char ConvDec(int i) //i es un número entre 0 y 9
{  return i + '0'; 
}

char ConvGen(int i) //i es un número entre 0 y 19
{  if (i <= 9)
     return i + '0';
   else
     return i + 'A' - 10;
}

char ConvTab(int i) //i es un número entre 0 y 19
{  char T[20] = "0123456789ABCDEFGHIJ";

   return T[i];
}
