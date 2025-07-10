#include <bits/stdc++.h>

/* ==========================================================================
   Dada uma sequência de cartas S[0..n-1]
   1. M[i,j] : Maior diferença que se pode obter com cartas S[i..j]
   2. M[i,j] = 0, se i > j
               S[i], se i = j
               max(S[i] - M[i+1,j], S[j] - M[i,j-1]), caso contrário
   3. M[0,n-1] = ?
   ========================================================================== */

using namespace std;

int somamin(int *S, int n);

int main()
{
  int S[] = {10, 15, 8, 4}, n;

  n = sizeof(S) / sizeof(int);
  printf("Menor soma para o jogador 1: %d\n", somamin(S, n));

  return 0;
}

int somamin(int *S, int n)
{

  int M[n][n], i, j, aux1, aux2;

  for (i = n - 1; i >= 0; i--)
    for (j = 0; j < n; j++)
      if (i == j)
        M[i][j] = S[i];
      else if (i > j)
        M[i][j] = 0;
      else
      {
        aux1 = S[i] - M[i + 1][j];
        aux2 = S[j] - M[i][j - 1];

        if (aux1 > aux2)
          M[i][j] = aux1;
        else
          M[i][j] = aux2;
      }

  return M[0][n - 1];
}
