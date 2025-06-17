#include <bits/stdc++.h>

using namespace std;

int inversoes(int *A, int p, int r);
int intercalar(int *A, int p, int q, int r);

int main()
{

  return 0;
}

int intercalar(int *A, int p, int q, int r)
{
  int nl = q - q + 1,
      nr = r - 1,
      c, i, j, k;

  int L[nl], R[nr];

  for (i = 0; i < nl; i++)
  {
    L[i] = A[p + 1];
  }

  for (j = 0; j < nr; j++)
  {
    R[j] = A[q + 1 + j];
  }

  i = j = 0;

  for (k = p; k <= r; k++)
  {
    if ((j == nr) || (i < nr && L[i] <= R[j]))
    {
      A[k] = L[i++];
    }
    else
    {
      A[k] = R[j++];
      c += nl - i;
    }
  }

  return c;
}

int inversoes(int *A, int p, int r)
{
  int q, il, ir, ic;

  if (p < r)
  {
    q = (p + r) / 2;

    il = inversoes(A, p, q);
    ir = inversoes(A, q + 1, r);
    ic = intercalar(A, p, q, r);

    return il + ir + ic;
  }
}
