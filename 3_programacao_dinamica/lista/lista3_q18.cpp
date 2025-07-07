#include <bits/stdc++.h>
/* ===============================================================
   Dado o vetor P[0..n] de dimensões das matrizes, onde a ordem
   de uma matriz Ai é P(i) x P(i+1), com 0 <= i < n

   1. M[i,j]: número mínimo de produtos escalares de Ai x ... x Aj
   2. M[i,j] = 0, se i >= j
               min{M[i,k] + M[k+1,j] + P[i] x P[k+1] x P[j+1] |
                   i <= k < j}
   3. M[0,n-1] = ?
   =============================================================== */

using namespace std;

int R[100][100] = {{0}};

int matrixchain(int *P, int n);
void rastreio(int i, int j);

int main()
{
  int P[] = {200, 2, 30, 20, 5}, i, j, n;

  n = sizeof(P) / sizeof(int) - 1;
  printf("Menor num. de multiplicacoes: %d\n", matrixchain(P, n));
  printf("Possivel solucao: ");
  rastreio(0, n - 1);
  return 0;
}

int matrixchain(int *P, int n)
{
  int M[n][n], i, j, k, q;

  for (i = n - 1; i >= 0; i--)
  {
    M[i][i] = 0;
    R[i][i] = 0;

    for (j = i + 1; j < n; j++)
    {
      k = i;
      M[i][j] = M[i][k] + M[k + 1][j] + P[i] * P[k + 1] * P[j + 1];
      R[i][j] = i;

      for (k = i + 1; k < j; k++)
      {
        q = M[i][k] + M[k + 1][j] + P[i] * P[k + 1] * P[j + 1];

        if (q < M[i][j])
        {
          M[i][j] = q;
          R[i][j] = k;
        }
      }
    }
  }

  return M[0][n - 1];
}

void rastreio(int i, int j)
{
  int k = R[i][j];

  if (i > j)
    return;

  if (i == j)
    printf("A%d", i + 1);
  else if (i < j)
  {
    printf("(");
    rastreio(i, k);
    printf("x");
    rastreio(k + 1, j);
    printf(")");
  }
}
