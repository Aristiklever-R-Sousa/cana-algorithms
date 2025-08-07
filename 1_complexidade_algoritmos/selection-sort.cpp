#include <bits/stdc++.h>

using namespace std;

void selectionsort(int *A, int n);

int main()
{
  int A[] = {2, 4, 3, 8, 5, 7, 6, 1, 9}, i, n;
  double ti, tf;

  n = sizeof(A) / sizeof(int);
  selectionsort(A, n);
  printf("A:");

  for (i = 0; i < n; i++)
    printf(" %d", A[i]);

  printf("\n");
  return 0;
}

void selectionsort(int *A, int n)
{
  int i, j, k;

  for (i = 0; i < n - 1; i++)
  {
    j = i;

    for (k = j + 1; k < n; k++)
      if (A[k] < A[j])
        j = k;

    swap(A[i], A[j]);
  }
}
