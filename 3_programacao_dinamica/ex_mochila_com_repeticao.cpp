#include <bits/stdc++.h>

/* ============================================================
   Dados os pesos P[0..n-1] e valores V[0..n-1] de n produtos e
   a capacidade c da mochila

   1. L[i]: Lucro máximo obtido com uma mochila de capacidade i
   2. L[i]: 0, se i = 0 ou se não existe produto que cabe na mochila
            max{V[j] + L[i-P[j]] | 1 <= j <= n e P[j] <= i}
   3. L[c] = ?
   ============================================================ */

using namespace std;

int R[100] = {0};

void rastreioit(int *P, int *V, int i, int j);
void rastreiorc(int *P, int *V, int n, int c);

int ksp(int *P, int *V, int n, int c);

int main()
{
  int V[5] = {18, 7, 13, 9, 8},
      P[5] = {8, 3, 6, 6, 4},
      n, c = 10;

  n = sizeof(P) / sizeof(int);
  printf("%d\n", ksp(P, V, 5, c));

  printf("Possivel solucao:\n");
  rastreioit(P, V, n, c);

  return 0;
}

int ksp(int *P, int *V, int n, int c)
{
  int M[c + 1], q;

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

void rastreioit(int *P, int *V, int n, int c)
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

void rastreiorc(int *P, int *V, int n, int c)
{
  if (R[c])
  {
    rastreiorc(P, V, n, c - P[R[c] - 1]);
    printf("Coletar uma unidade do %do. produto\n", R[c]);
  }
}
