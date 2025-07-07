/**
 * L[i]: maior lucro obtido a partir de uma madeira de tamanho i.
 *       dados os tamanhos A[1. . .k] e os valores B[1. . .k].
 *
 * V[i]: maior valor de um pedaço de madeira de tamanho i, caso exista, ou 0.
 *
 * L[i]: 0, se i = 0;
 *       max{V[j]+L[i-j]: 1≤j≤i}, se i>0.
 *
 * Calcular L[n].
 *
 */

#include <bits/stdc++.h>
using namespace std;

int R[100] = {0};

int maiorLucro(int l, int *A, int *B, int k);
void rastreio(int *A, int n);

int main()
{
  int A[] = {2, 4, 6, 8}, B[] = {1, 2, 3, 4}, k = 4, l = 10;

  printf("Maior lucro: %d\n", maiorLucro(l, A, B, k));
}

int maiorLucro(int l, int *A, int *B, int k)
{
  int L[l + 1], i, j, V[l + 1] = {0}, aux;

  for (i = 0; i < k; i++)
    V[A[i]] = B[i];

  L[0] = 0;
  R[0] = -1;

  for (i = 1; i <= l; i++)
  {
    L[i] = 0;
    R[i] = -1;

    for (j = 1; j <= i; j++)
    {
      aux = V[j] + L[i - j];

      if (L[i] < aux)
      {
        L[i] = aux;
        R[i] = j;
      }
    }
  }

  return L[l];
}

// void rastreio(int *A, int n)
// {
//   if (R[n] > 0)
//   {
//     rastreio(A, R[n]);
//     printf("%d ", );
//   }
// }
