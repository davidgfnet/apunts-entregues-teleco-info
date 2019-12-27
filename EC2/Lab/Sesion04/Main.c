#include <stdio.h>
#define N 10

void Fusion(int res[], int v1[], int v2[], int n);

main() {
  int res[N+N];
  int v1[N] = {-23, -6, -1, 0, 3, 5, 9, 15, 21, 33};
  int v2[N] = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8};  
  int i;
  int sum;


  for (i=0; i<N; i++)
     printf("%4d ", v1[i]);
  printf("\n");
  for (i=0; i<N; i++)
     printf("%4d ", v2[i]);
  printf("\n");

  Fusion(res, v1, v2, N);

  for (i=0; i<N+N; i++)
     printf("%4d ", res[i]);
  printf("\n");

}
