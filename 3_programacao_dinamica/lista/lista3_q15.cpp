/**
 * S[i,j]: maior soma de elementos de A[1. . .i] não superior a j.
 * S[i,j] = 0, se i=0 ou j=0;
 *          S[i-1,j], se i>0, j>0 e A[i]>j;
 *          max(S[i-1,j],A[i]+S[i-1,j-A[i]]), se i>0, j>0 e A[i]≤j.
 * Verificar se S[n,T]=T.
 */

#include <bits/stdc++.h>
using namespace std;

int R[100][100] = {{0}};

bool verificaSoma(int *A, int n, int t);

void rastreio(int *A, int n, int t);

int main()
{

  int A[] = {1, 3, 7, 9}, t = 11;

  int n = sizeof(A) / sizeof(int);

  printf("Há um subconjunto em A que some %d? ", t);
  if (verificaSoma(A, n, t))
  {
    printf("Sim!\n");
    printf("Possível subconjunto: \n");
    rastreio(A, n, t);
    printf("\n");
  }
  else
  {
    printf("Não!\n");
  }

  return 0;
}

bool verificaSoma(int *A, int n, int t)
{
  int S[n + 1][t + 1], i, j, aux;

  for (i = 0; i <= n; i++)
    S[i][0] = 0;

  for (j = 0; j <= t; j++)
    S[0][j] = 0;

  for (i = 1; i <= n; i++)
    for (j = 1; j <= t; j++)
      if (A[i - 1] > j)
      {
        S[i][j] = S[i - 1][j]; // Recua linha
        R[i][j] = 1;
      }
      else
      {
        aux = A[i - 1] + S[i - 1][j - A[i - 1]];
        if (S[i - 1][j] > aux)
        {
          S[i][j] = S[i - 1][j]; // Recua linha
          R[i][j] = 1;
        }
        else
        {
          S[i][j] = aux; // Recua linha e j - A[i-1] colunas
          R[i][j] = 2;
        }
      }

  return S[n][t] == t;
}

void rastreio(int *A, int n, int t)
{
  if (R[n][t])
  {
    if (R[n][t] == 1)
    {
      rastreio(A, n - 1, t);
      // printf("%d ", A[n - 1]);
    }
    else
    {
      rastreio(A, n - 1, t - A[n - 1]);
      printf("%d ", A[n - 1]);
    }
  }
}
