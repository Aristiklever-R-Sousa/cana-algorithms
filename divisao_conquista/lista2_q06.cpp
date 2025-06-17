#include <bits/stdc++.h>

using namespace std;

int getKthElement(int *A, int *B, int n, int k);
int getKthElementWithDivisionAndConquist(int *X, int px, int rx, int *Y, int py, int ry, int k);

int main()
{

  int n = 5;

  int A[n] = {4, 5, 7, 8, 9};
  int B[n] = {1, 2, 3, 6, 10};

  // int x = getKthElement(A, B, n, 5);
  int x = getKthElementWithDivisionAndConquist(A, 0, n, B, 0, n, 6);

  printf("Elemento: %d\n", x);

  return 0;
}

int getKthElementWithDivisionAndConquist(int *X, int px, int rx, int *Y, int py, int ry, int k)
{
  if (px > rx)
  {
    return Y[py + k - 1];
  }
  else if (py > ry)
  {
    return X[px + k - 1];
  }
  else
  {
    int qx = (px + rx) / 2;
    int qy = (py + ry) / 2;

    int lx = qx - px + 1;
    int ly = qy - py + 1;

    if (k < lx + ly)
    {
      if (X[qx] < Y[qy])
      {
        return getKthElementWithDivisionAndConquist(X, px, rx, Y, py, qy - 1, k);
      }
      else
      {
        return getKthElementWithDivisionAndConquist(X, px, qx - 1, Y, py, ry, k);
      }
    }
    else
    {
      if (X[qx] < Y[qy])
      {
        return getKthElementWithDivisionAndConquist(X, qx + 1, rx, Y, py, ry, k - lx);
      }
      else
      {
        return getKthElementWithDivisionAndConquist(X, px, rx, Y, qy + 1, ry, k - ly);
      }
    }
  }
}

int getKthElement(int *A, int *B, int n, int k)
{

  int low = max(0, k - n);
  int high = min(k, n);

  while (low <= high)
  {
    int i = (low + high) / 2;
    int j = k - i;

    if (A[i - 1] <= B[j] && B[j - 1] <= A[i])
    {
      return max(A[i - 1], B[j - 1]);
    }
    else if (A[i - 1] > B[j])
    {
      high = i - 1;
    }
    else
    {
      low = i + 1;
    }
  }

  return false;
}
