#include <bits/stdc++.h>

/* ========================================================================================
   Dados os vetores de pesos e valores dos n produtos - P[0..n-1] e V[0-n-1] e uma mochila
   de capacidade C

   1. M[i,j]: Lucro máximo obtido com os i primeiros produtos e uma mochila de capacidade j
   2. M[i,j]= 0, se i = 0 ou j = 0
              M[i-1,j], se i > 0, j > 0 e P[i-1] > j
              max(V[i-1] + M[i-1, j - P[i-1]], M[i-1,j]), caso contrário
   3. M[n,C]
   ======================================================================================== */

using namespace std;

int R[100][100] = {{0}};

int lucromax(int *P, int *V, int n, int c);
void rastreio(int *P, int *V, int i, int j);

int main()
{
  int V[] = {18, 7, 13, 9, 8},
      P[] = {8, 3, 6, 5, 4},
      n, c = 10, l;

  n = sizeof(P) / sizeof(int);
  l = lucromax(P, V, n, c);
  printf("Lucro máximo: %d\n", l);
  printf("Possivel solução:\n");
  rastreio(P, V, n, c);
  return 0;
}

int lucromax(int *P, int *V, int n, int c)
{
  int M[n + 1][c + 1], q, i, j;

  for (i = 0; i <= n; i++)
    M[i][0] = 0;

  for (j = 0; j <= c; j++)
    M[0][j] = 0;

  for (i = 1; i <= n; i++)
    for (j = 1; j <= c; j++)
    {
      M[i][j] = M[i - 1][j];
      R[i][j] = 0;

      if (P[i - 1] <= j)
      {
        q = V[i - 1] + M[i - 1][j - P[i - 1]];

        if (q > M[i][j])
        {
          M[i][j] = q;
          R[i][j] = 1;
        }
      }
    }

  return M[n][c];
}

void rastreio(int *P, int *V, int i, int j)
{
  if (i > 0 && j > 0)
    if (R[i][j] == 1)
    {
      rastreio(P, V, i - 1, j - P[i - 1]);
      printf("Coletar o produto %d que pesa %d e vale %d\n", i, P[i - 1], V[i - 1]);
    }
    else
      rastreio(P, V, i - 1, j);
}
