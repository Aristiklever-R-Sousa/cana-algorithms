/**
 * COMPLEXIDADES ASSINTÓTICAS
 * CASOS:
 *  MELHOR - O(n)
 *  MÉDIO  - O(n²)
 *  PIOR   - O(n²)
 */

#include <bits/stdc++.h>

using namespace std;

void bubblesort(int *A, int n);

int main()
{
  int *A, i, n = 100000;
  double ti, tf;

  A = (int *)calloc(n, sizeof(int));
  for (i = 0; i < n; i++)
    A[i] = i + 1;

  ti = clock();
  bubblesort(A, n);
  tf = clock();
  printf("Tempo: %f\n", (tf - ti) / CLOCKS_PER_SEC);
  free(A);
  return 0;
}

void bubblesort(int *A, int n)
{
  int i, j;

  for (i = n - 1; i > 0; i--)
    for (j = 0; j < i; j++)
      if (A[j] > A[j + 1])
        swap(A[j], A[j + 1]);
}
