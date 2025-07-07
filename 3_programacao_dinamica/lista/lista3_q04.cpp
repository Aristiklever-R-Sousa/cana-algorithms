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

int solidez(int *A, int n);

int main()
{
  int A[9] = {5, 15, -30, 10, -5, 40, 10, -5, 3};

  printf("Solução: %d\n", solidez(A, 9));

  printf("Rastreio: \n");

  return 0;
}

int solidez(int *A, int n)
{
  int S[n];

  for (int i = 0; i < n; i++)
  {
    S[i] = A[i];
    if (i > 0)
    {
      if (S[i - 1] > 0)
      {
        S[i] = S[i - 1] + A[i];
      }
    }
  }

  int max = S[0];
  for (int i = 1; i < n; i++)
  {
    if (max < S[i])
    {
      max = S[i];
    }
  }

  return max;
}
