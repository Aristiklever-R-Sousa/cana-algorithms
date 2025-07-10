/**
 *
 * 1. S[i]: maior soma de elementos de A[0. . .i], incluindo o A[i].
 * 2. S[i]: A[i], se i=0 ou S[i-1] ≤ 0;
 *          S[i-1]+A[i], se i>0 e S[i-1] > 0.
 * 3. max{S[i]: 0 ≤ i ≤ n-1}.
 *
 */

#include <bits/stdc++.h>
using namespace std;

int startPositionIdx = 0;
int startPositionTempIdx = 0;
int endPositionIdx = 0;

int solidez(int *A, int n);
void rastreio(int *A);

int main()
{
  int A[9] = {5, 15, -30, 10, -5, 40, 10, -5, 3};

  printf("Solução: %d\n", solidez(A, 9));

  rastreio(A);

  return 0;
}

int solidez(int *A, int n)
{
  int S[n], max, i;

  S[0] = A[0];
  max = A[0];

  for (i = 1; i < n; i++)
  {
    S[i] = A[i];

    if (S[i - 1] > 0)
    {
      S[i] = S[i - 1] + A[i];
    }
    else
    {
      startPositionTempIdx = i;
    }

    if (max < S[i])
    {
      max = S[i];
      startPositionIdx = startPositionTempIdx;
      endPositionIdx = i;
    }
  }

  // for (i = 0; i < n; i++)
  //   printf("%d\n", S[i]);

  return max;
}

void rastreio(int *A)
{
  printf("Subvetor: [ ");
  for (int i = startPositionIdx; i <= endPositionIdx; i++)
  {
    printf("%d ", A[i]);
  }
  printf("]\n");
}
