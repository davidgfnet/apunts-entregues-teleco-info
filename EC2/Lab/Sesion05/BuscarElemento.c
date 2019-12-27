#include <stdio.h>
#include "elemento.h"

int BuscarElemento(int *low, int *high, int *mid, int xx, S1 v[])
{  
  if (xx == v[*mid].k + *(v[*mid].m))
    return *mid;	/* elemento encontrado */
  else
    if (*mid < *high) {
      *mid = *high;
      (*low)++;
    } else {
      *mid = *low;
      (*high)--;
    }
  return -1;            /* elemento no encontrado */
}

