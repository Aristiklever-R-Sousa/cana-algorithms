#include <bits/stdc++.h>

using namespace std;

int getAmountDuplicates(int *A, int n);

int main()
{

  int n = 11;

  int A[n] = {1, 2, 3, 3, 5, 1, 1, 8, 4543434, 2, 4543434};

  int x = getAmountDuplicates(A, n);

  printf("Duplicadas: %d\n", x);

  return 0;
}

int getAmountDuplicates(int *A, int n)
{

  sort(A, A + n);

  int duplicatesQuantity = 0;

  for (int i = 1; i < n; i++)
  {
    if (A[i - 1] == A[i])
    {
      duplicatesQuantity++;
    }
  }

  return duplicatesQuantity;
}
