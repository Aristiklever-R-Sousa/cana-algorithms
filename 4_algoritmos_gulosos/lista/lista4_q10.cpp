#include <bits/stdc++.h>

using namespace std;

int minArrows(int *S, int n);

int main()
{
  int B[] = {5, 1, 5, 4, 2, 3};
  int n = sizeof(B) / sizeof(int);

  printf("Minimo de flechas usadas: %d\n", minArrows(B, n));

  return 0;
}

int minArrows(int *B, int n)
{
  int F[400] = {0}, i = 0, minTotalUsedArrows = 0;

  for (i = 0; i < n; i++)
  {
    if (F[B[i]] > 0)
    {
      F[B[i]]--;
      if (B[i] > 1)
      {
        F[B[i] - 1]++;
      }
    }
    else
    {
      minTotalUsedArrows++;
      if (B[i] > 1)
        F[B[i] - 1]++;
    }
  }

  return minTotalUsedArrows;
}
