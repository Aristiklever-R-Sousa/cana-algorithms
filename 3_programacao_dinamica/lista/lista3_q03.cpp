/**
 *
 * 1. P[i]: Menor penalização até o Km ai
 * 2. P[i]: 0, se i = 0
 *          min(P[j] + |200 - (A[i] - A[j])|), 0 <= j < i
 * 3. Calcular P[n]
 *
 */

#include <bits/stdc++.h>
using namespace std;

int R[201] = {-1};

void rastreio(int *A, int n);
void rastreioOutra(int *A, int n);

int menorPenalizacao(int *A, int n);
int menorPenalizacaoOutra(int *A, int n);

int main()
{
  int A[5] = {0, 300, 500, 600, 710},
      n = 5;

  printf("Menor penalização: %d\n\n", menorPenalizacao(A, n));
  // printf("Menor penalização: %d\n\n", menorPenalizacaoOutra(A, n));

  printf("Rastreio:\n");
  // rastreio(A, n - 1);
  rastreioOutra(A, n);
}

int menorPenalizacao(int *A, int n)
{
  int P[n] = {0}, p;

  for (int i = 0; i < n; i++)
  {
    P[i] = INT_MAX;
    R[i] = -1;
  }

  P[0] = 0;
  R[0] = 0;

  for (int i = 1; i < n; i++)
  {
    // P[i] = P[i] + abs(200 - (A[i] - A[0]));
    R[i] = i;

    for (int j = 0; j < i; j++)
    {
      p = P[j] + abs(200 - (A[i] - A[j]));

      if (P[i] > p)
      {
        P[i] = p;
        R[i] = j;
      }
    }
    printf("P[%d] -> %d | R[%d] -> %d | A[%d] -> %d\n", i, P[i], i, R[i], i, A[i]);
  }

  return P[n - 1];
}

int menorPenalizacaoOutra(int *A, int n)
{
  int P[n + 1] = {0}, p;

  for (int i = 0; i <= n; i++)
  {
    P[i] = INT_MAX;
    R[i] = -1;
  }

  P[0] = 0;
  R[0] = 0;

  for (int i = 1; i <= n; i++)
  {
    P[i] = abs(200 - (A[i - 1]));
    R[i] = i;

    for (int j = 1; j < i; j++)
    {
      p = P[j] + abs(200 - (A[i - 1] - A[j - 1]));

      if (P[i] > p)
      {
        P[i] = p;
        R[i] = j;
      }
    }
  }

  return P[n];
}

void rastreio(int *A, int n)
{

  for (int i = 0; i < n; i++)
    printf("KM %d\n", A[R[i]]);
}

void rastreioOutra(int *A, int n)
{
  int aux = n;

  while (aux != R[aux])
  {
    printf("Pare no km %d\n", A[R[aux] - 1]);
    aux = R[aux];
  }
}
