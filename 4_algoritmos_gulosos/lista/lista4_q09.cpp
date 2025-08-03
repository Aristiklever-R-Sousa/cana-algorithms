#include <bits/stdc++.h>

using namespace std;

int minSum(int *S, int n);

int main()
{
  // int S[] = {3, 4, 6, 8, 14, 15, 16, 17, 21, 25, 26, 27, 30, 31, 40, 41, 42, 43};
  int S[] = {1, 2, 3, 4, 5, 100};
  int n = sizeof(S) / sizeof(int);

  printf("Soma minima dos tamanhos dos intervalos: %d\n", minSum(S, n));

  return 0;
}

int minSum(int *S, int n)
{
  int auxSum = 0, i = 0, k = 0,
      maxGapOne, maxGapTwo, maxGapThree,
      maxGapOnePosition, maxGapTwoPosition, maxGapThreePosition;

  k = S[n - 1] - S[0] + 1;

  maxGapOne = S[1] - S[0] + 1;
  maxGapOnePosition = 0;

  maxGapTwo = S[2] - S[1] + 1;
  maxGapTwoPosition = 1;

  maxGapThree = S[3] - S[2] + 1;
  maxGapThreePosition = 2;

  for (i = 3; i < n - 1; i++)
  {
    auxSum = S[i + 1] - S[i] + 1;

    if (auxSum > maxGapOne)
    {
      maxGapThree = maxGapTwo;
      maxGapThreePosition = maxGapTwoPosition;

      maxGapTwo = maxGapOne;
      maxGapTwoPosition = maxGapOnePosition;

      maxGapOne = auxSum;
      maxGapOnePosition = i;
    }
    else if (auxSum > maxGapTwo)
    {
      maxGapThree = maxGapTwo;
      maxGapThreePosition = maxGapTwoPosition;

      maxGapTwo = auxSum;
      maxGapTwoPosition = i;
    }
    else if (auxSum > maxGapThree)
    {
      maxGapThree = auxSum;
      maxGapThreePosition = i;
    }

    printf("[%d, %d] -> %d\n", S[i], S[i + 1], auxSum);
  }

  printf("MAX1[%d]: [%d, %d] -> %d\n", maxGapOnePosition, S[maxGapOnePosition], S[maxGapOnePosition + 1], maxGapOne);
  printf("MAX2[%d]: [%d, %d] -> %d\n", maxGapTwoPosition, S[maxGapTwoPosition], S[maxGapTwoPosition + 1], maxGapTwo);
  printf("MAX3[%d]: [%d, %d] -> %d\n", maxGapThreePosition, S[maxGapThreePosition], S[maxGapThreePosition + 1], maxGapThree);

  auxSum = (S[maxGapOnePosition] - S[0] + 1) + (S[n - 1] - S[maxGapOnePosition] + 1);
  if (k > auxSum)
  {
    k = auxSum;
  }
  printf("ONE: %d | aux: %d\n", k, auxSum);

  if (maxGapOnePosition > maxGapTwoPosition)
  {
    auxSum = S[maxGapTwoPosition] - S[0] + 1;
    auxSum += S[maxGapOnePosition] - S[maxGapTwoPosition + 1] + 1;
    auxSum += S[n - 1] - S[maxGapOnePosition + 1] + 1;
  }
  else
  {
    auxSum = S[maxGapOnePosition] - S[0] + 1;
    auxSum += S[maxGapTwoPosition] - S[maxGapOnePosition + 1] + 1;
    auxSum += S[n - 1] - S[maxGapTwoPosition + 1] + 1;
  }

  if (k > auxSum)
  {
    k = auxSum;
  }
  printf("TWO: %d | aux: %d\n", k, auxSum);

  if (maxGapOnePosition > maxGapTwoPosition)
  {
    if (maxGapTwoPosition > maxGapThreePosition)
    {
      auxSum = S[maxGapThreePosition] - S[0] + 1;
      auxSum += S[maxGapTwoPosition] - S[maxGapThreePosition + 1] + 1;
      auxSum += S[maxGapOnePosition] - S[maxGapTwoPosition + 1] + 1;
      auxSum += S[n - 1] - S[maxGapOnePosition + 1] + 1;
    }
    else if (maxGapOnePosition > maxGapThreePosition)
    {
      auxSum = S[maxGapTwoPosition] - S[0] + 1;
      auxSum += S[maxGapThreePosition] - S[maxGapTwoPosition + 1] + 1;
      auxSum += S[maxGapOnePosition] - S[maxGapThreePosition + 1] + 1;
      auxSum += S[n - 1] - S[maxGapOnePosition + 1] + 1;
    }
    else
    {
      auxSum = S[maxGapTwoPosition] - S[0] + 1;
      auxSum += S[maxGapOnePosition] - S[maxGapTwoPosition + 1] + 1;
      auxSum += S[maxGapThreePosition] - S[maxGapOnePosition + 1] + 1;
      auxSum += S[n - 1] - S[maxGapThreePosition + 1] + 1;
    }
  }
  else
  {
    if (maxGapOnePosition > maxGapThreePosition)
    {
      auxSum = S[maxGapThreePosition] - S[0] + 1;
      auxSum += S[maxGapOnePosition] - S[maxGapThreePosition + 1] + 1;
      auxSum += S[maxGapTwoPosition] - S[maxGapOnePosition + 1] + 1;
      auxSum += S[n - 1] - S[maxGapTwoPosition + 1] + 1;
    }
    else if (maxGapTwoPosition > maxGapThreePosition)
    {
      auxSum = S[maxGapOnePosition] - S[0] + 1;
      auxSum += S[maxGapThreePosition] - S[maxGapOnePosition + 1] + 1;
      auxSum += S[maxGapTwoPosition] - S[maxGapThreePosition + 1] + 1;
      auxSum += S[n - 1] - S[maxGapTwoPosition + 1] + 1;
    }
    else
    {
      auxSum = S[maxGapOnePosition] - S[0] + 1;
      auxSum += S[maxGapTwoPosition] - S[maxGapOnePosition + 1] + 1;
      auxSum += S[maxGapThreePosition] - S[maxGapTwoPosition + 1] + 1;
      auxSum += S[n - 1] - S[maxGapThreePosition + 1] + 1;
    }
  }

  if (k > auxSum)
  {
    k = auxSum;
  }
  printf("THREE: %d | aux: %d\n", k, auxSum);

  return k;
}
