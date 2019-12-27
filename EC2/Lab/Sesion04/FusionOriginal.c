void Fusion(int res[], int v1[], int v2[], int n)
{
  int i, j, k;

  i = 0;
  j = 0;
  k = 0;
  while ((i<n) && (j<n)) {
    if (v1[i] < v2[j]) {
      res[k] = v1[i];
      i++;
      k++;
    }
    else {
      res[k] = v2[j];
      j++;
      k++;
    }
  }
  while (i<n) {
    res[k] = v1[i];
    i++;
    k++;
  }
  while (j<n) {
    res[k] = v2[j];
    j++;
    k++;
  }

}

