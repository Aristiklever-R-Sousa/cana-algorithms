#include <bits/stdc++.h>

using namespace std;

int maxSumValoresContiguos(int *V, int n, int k);

int main()
{

  int V[] = {1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1},
      k = 4;

  int n = sizeof(V) / sizeof(int);

  printf("Menor soma de valores contíguos: %d\n", maxSumValoresContiguos(V, n, k));

  return 0;
}

int maxSumValoresContiguos(int *V, int n, int k)
{
  int minTotalSum = 0, i = 0, sumAux = 0,
      firstValueIndexFromSum = 0;

  for (i = 0; i < k; i++)
  {
    minTotalSum += V[i];
  }

  for (i = k; i < n; i++)
  {
    sumAux = minTotalSum - V[firstValueIndexFromSum] + V[i];
    if (minTotalSum < sumAux)
    {
      firstValueIndexFromSum++;
      minTotalSum = sumAux;
    }
  }

  return minTotalSum;
}
