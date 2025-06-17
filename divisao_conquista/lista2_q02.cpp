#include <bits/stdc++.h>

using namespace std;

bool checksIfHasTwoNumbersThatAddUpToX(int *A, int n, int x);

int main()
{

  int n = 10;

  int A[n] = {3, 4, 5, 6, 7, 8, 9, 11, 15, 17};

  bool x = checksIfHasTwoNumbersThatAddUpToX(A, n, 32);

  printf("Existe? %s\n", x ? "Sim" : "Não");

  return 0;
}

bool checksIfHasTwoNumbersThatAddUpToX(int *A, int n, int x)
{

  sort(A, A + n);

  int i = 0, j = n - 1, sum = 0;

  while (A[i] < A[j])
  {
    sum = A[i] + A[j];

    if (sum == x)
    {
      return true;
    }
    else if (sum > x)
    {
      j--;
    }
    else
    {
      i++;
    }
  }

  return false;
}
