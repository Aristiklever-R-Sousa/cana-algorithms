#include <bits/stdc++.h>
/* ============================================================
   Dados os pesos P[0..n-1] e valores V[0..n-1] de n produtos e
   a capacidade c da mochila

   1. L[i]: Lucro máximo obtido com uma mochila de capacidade i
   2. L[i]: 0, se i = 0 ou se não existe produto que cabe na mochila
            max{V[j] + L[i-P[j]] | 0 <= j < n e P[j] <= i}
   3. L[c] = ?
   ============================================================ */

using namespace std;

int R[100] = {0};

int MochilaRep(int *P, int *V, int n, int c);
void rastreio(int *P, int *V, int n, int c);
void rastreior(int *P, int *V, int n, int c);

int main()
{
  int V[] = {18, 7, 13, 9, 8},
      P[] = {8, 3, 6, 5, 4}, n, c = 15;

  n = sizeof(P) / sizeof(int);
  printf("Lucro maximo: %d\n", MochilaRep(P, V, n, c));
  printf("Possivel solucao:\n");
  rastreio(P, V, n, c);
  return 0;
}

int MochilaRep(int *P, int *V, int n, int c)
{
  int L[c + 1], i, j, q;

  L[0] = 0;
  R[0] = 0;

  for (i = 1; i <= c; i++)
  {
    L[i] = 0;
    R[i] = 0;

    for (j = 0; j < n; j++)
      if (P[j] <= i)
      {
        q = V[j] + L[i - P[j]];

        if (q > L[i])
        {
          L[i] = q;
          R[i] = j + 1;
        }
      }
  }

  return L[c];
}

void rastreio(int *P, int *V, int n, int c)
{
  int Q[n] = {0}, i;

  while (R[c])
  {
    Q[R[c] - 1]++;
    c -= P[R[c] - 1];
  }

  for (i = 0; i < n; i++)
    if (Q[i] > 0)
      printf("Coletar %d unidade(s) do %do. produto\n", Q[i], i + 1);
}

void rastreior(int *P, int *V, int n, int c)
{
  if (R[c])
  {
    rastreior(P, V, n, c - P[R[c] - 1]);
    printf("Coletar uma unidade do %do. produto\n", R[c]);
  }
}

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
