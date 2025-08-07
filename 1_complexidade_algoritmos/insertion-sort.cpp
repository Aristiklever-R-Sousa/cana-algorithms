#include <bits/stdc++.h>

using namespace std;

void insertionsort(int *A, int n);

int main()
{
  int A[] = {2, 4, 3, 8, 5, 7, 6, 1, 9}, i, n;
  double ti, tf;

  n = sizeof(A) / sizeof(int);
  insertionsort(A, n);
  printf("A:");

  for (i = 0; i < n; i++)
    printf(" %d", A[i]);

  printf("\n");
  return 0;
}

void insertionsort(int *A, int n)
{
  int i, j, x;

  for (i = 1; i < n; i++)
  {
    x = A[i];
    j = i - 1;

    while (j >= 0 && A[j] > x)
    {
      A[j + 1] = A[j];
      j--;
    }

    A[j + 1] = x;
  }
}
