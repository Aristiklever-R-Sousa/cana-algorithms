#include <bits/stdc++.h>

using namespace std;

/**
 * DADO UM VETOR A COM N ELEMENTOS INTEIROS
 * 1. S[i]: tamanho da maior subsequencia crescente incluindo o elemento A[i]
 * 2. S[i]: 1, se i = 0
            1, se não existe 0 <= j < i tal que A[j] < A[i]
            max{1 + S[j]: 0 <= j < i e A[j] < A[i]}, caso contrário
 * 3. Encontrar o maior valor de S
 */

int sscmax(int *A, int n);

int main()
{

  int A[] = {3, 1, 8, 6, 2, 5, 4, 7, 2}, n = 9;

  sscmax(A, n);

  return 0;
}

int sscmax(int *A, int n)
{

  int S[n] = {0}, q = 0, smax = 0;

  S[0] = smax = 1;

  for (int i = 1; i < n; i++)
  {
    S[i] = 1;

    for (int j = i - 1; j <= 0; j--)
    {
      if (A[j] < A[i])
      {
        q = S[j] + 1;

        if (q > S[i])
        {
          S[i] = q;
        }
      }
    }

    if (smax < S[i])
      smax = S[i];
  }

  return smax;
}

int rastreio()
{

  return 0;
}
