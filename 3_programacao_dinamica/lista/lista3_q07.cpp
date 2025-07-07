/**
 * S[i]: maior subseq. crescente de A[0. . .i], incluindo A[i].
 *
 * S[i]: 1, se i = 0;
 *       1, se i>0 e não há valor menor que A[i] antes dele
 *       max{1+S[k]:0≤k≤i e A[k]<A[i]}, caso contrário.
 *
 * Calcular o maior valor de S.
 *
 */

#include <bits/stdc++.h>
using namespace std;

int R[100] = {0};

int maiorSubsequenciaCrescente(int *A, int n);
void rastreio(int *A, int n);

int main()
{
  int A[] = {5, 2, 8, 6, 3, 5, 9, 6, 8},
      n = sizeof(A) / sizeof(int);

  printf("Maior subsec. cresc.: %d\n", maiorSubsequenciaCrescente(A, n));
}

int maiorSubsequenciaCrescente(int *A, int n)
{
  int S[n], i, k;

  for (i = 0; i < n; i++)
  {
    S[i] = 1;

    for (k = 0; k <= i; k++)
    {
      if (A[k] < A[i])
      {
        S[i] = S[k] + 1;
      }
    }
    printf("S[0...%d]: %d\n", i, S[i]);
  }

  return S[n - 1];
}
