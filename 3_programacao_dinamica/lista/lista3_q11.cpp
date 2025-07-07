#include <bits/stdc++.h>

/* ===========================================================
   Dada uma coleção de elementos A[0..n-1], cuja soma é T.
   Se T é múltiplo de 3, então faça s = T/3.
   1. M[i,j,k]: 1, se existem subcoleções de A[0..i-1] cujas
                somas sejam j e k. 0, caso contrário.
   2. M[i,j,k] = 1, se j = 0 e k = 0.
                 0, se i = 0 e, j > 0 ou k > 0
                 (Ai <= j e M[i-1,j-Ai,k]) ou
                 (Ai <= k e M[i-1,j,k-Ai]) ou
                 (M[i-1,j,k])
   3. M[n,s,s] = ?
   =========================================================== */

using namespace std;

int R[10][10][10] = {{{0}}};

int particao3(int *A, int n, int s);
void rastreiorc(int *A, int i, int j, int k);
void rastreioit(int *A, int i, int j, int k);

int main()
{
  int A[] = {1, 2, 3, 4, 4, 5, 8}, n, i, t, p = 0, s;

  n = sizeof(A) / sizeof(int);

  for (i = t = 0; i < n; i++)
    t += A[i];

  if (t % 3 == 0)
  {
    s = t / 3;
    p = particao3(A, n, s);
  }

  if (p)
  {
    printf("E possivel particioar!\n");
    printf("Possivel solucao:\n");
    // rastreiorc(A, n, s, s);
    rastreioit(A, n, s, s);
  }
  else
    printf("Nao e possivel particionar!\n");

  return 0;
}

int particao3(int *A, int n, int s)
{
  int M[n + 1][s + 1][s + 1], i, j, k;

  for (i = 0; i <= n; i++)
    for (j = 0; j <= s; j++)
      for (k = 0; k <= s; k++)
      {
        if (j == 0 && k == 0)
        {
          M[i][j][k] = 1;
          R[i][j][k] = 3;
        }
        else if (i == 0 && (j > 0 || k > 0))
        {
          M[i][j][k] = 0;
        }
        else if (A[i - 1] <= j && M[i - 1][j - A[i - 1]][k])
        {
          M[i][j][k] = 1;
          R[i][j][k] = 1;
        }
        else if (A[i - 1] <= k && M[i - 1][j][k - A[i - 1]])
        {
          M[i][j][k] = 1;
          R[i][j][k] = 2;
        }
        else if (M[i - 1][j][k])
        {
          M[i][j][k] = 1;
          R[i][j][k] = 3;
        }
        else
          M[i][j][k] = 0;
      }

  return M[n][s][s];
}

void rastreiorc(int *A, int i, int j, int k)
{
  int x = R[i][j][k];

  if (i)
    if (x == 1)
    {
      rastreiorc(A, i - 1, j - A[i - 1], k);
      printf("%d ==> 1\n", A[i - 1]);
    }
    else if (x == 2)
    {
      rastreiorc(A, i - 1, j, k - A[i - 1]);
      printf("%d ==> 2\n", A[i - 1]);
    }
    else if (x == 3)
    {
      rastreiorc(A, i - 1, j, k);
      printf("%d ==> 3\n", A[i - 1]);
    }
}

void rastreioit(int *A, int i, int j, int k)
{
  int P[i] = {0}, x, n;

  n = i;

  while ((i > 0) && (x = R[i][j][k]))
  {
    P[i - 1] = x;

    if (x == 1)
      j -= A[i - 1];
    else if (x == 2)
      k -= A[i - 1];

    i--;
  }

  for (j = 0; j < 3; j++)
  {
    printf("%c:", 'I' + j);

    for (i = 0; i < n; i++)
      if (P[i] == j + 1)
        printf(" %d", A[i]);

    printf("\n");
  }

  printf("\n");
}
