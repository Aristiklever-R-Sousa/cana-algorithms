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

int R[100] = {0};

void rastreio(int *P, int *V, int i, int j);

int ksp(int *P, int *V, int n, int c);

int main()
{
  int V[5] = {18, 7, 13, 9, 8},
      P[5] = {8, 3, 6, 6, 4},
      n, c = 10;

  n = sizeof(P) / sizeof(int);
  printf("%d\n", ksp(P, V, 5, c));

  printf("Possivel solucao:\n");
  rastreio(P, V, n, c);

  return 0;
}

int ksp(int *P, int *V, int n, int c)
{
  int M[c], q;

  M[0] = 0;
  R[0] = 0;

  for (int i = 1; i <= c; i++)
  {
    M[i] = 0;
    R[i] = 0;

    for (int j = 1; j <= n; j++)
      if (P[j - 1] <= i)
      {
        q = V[j - 1] + M[i - P[j - 1]];

        if (q > M[i])
        {
          M[i] = q;
          R[i] = j + 1;
        }
      }
  }

  return M[c];
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

// --------------------------------------

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
