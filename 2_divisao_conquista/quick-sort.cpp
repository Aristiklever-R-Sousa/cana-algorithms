#include <bits/stdc++.h>

using namespace std;

int particionar(int *A, int p, int r);
void quicksort(int *A, int p, int r);

/*
int main() {
  int *A, n = 100000, i;
  double ti, tf;

  A = (int *) calloc(n, sizeof(int));

  for (i = 0; i < n; i++)
    A[i] = rand() % n + 1;

  ti = clock();
  mergesort(A, 0, n-1);
  tf = clock();
  printf("Tempo: %f\n", (tf - ti) / CLOCKS_PER_SEC);
  free(A);
  return 0;
}
*/

int main()
{
    int A[] = {2, 5, 6, 4, 7, 9, 3, 8, 1}, n, i;

    n = sizeof(A) / sizeof(int);
    quicksort(A, 0, n - 1);
    printf("A:");

    for (i = 0; i < n; i++)
        printf(" %d", A[i]);

    printf("\n");
    return 0;
}

int particionar(int *A, int p, int r)
{
    int i = p - 1, j;

    for (j = p; j < r; j++)
        if (A[j] <= A[r])
            swap(A[++i], A[j]);

    swap(A[++i], A[r]);
    return i;
}

void quicksort(int *A, int p, int r)
{
    int q;

    if (p < r)
    {
        q = particionar(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}
