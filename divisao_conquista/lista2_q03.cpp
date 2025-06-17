#include <bits/stdc++.h>

using namespace std;

int getMajorityNumber(int *A, int p, int r);
int getMajorityNumberLinear(int *A, int n);

int main()
{

  int n = 11;

  int A[n] = {1, 2, 3, 3, 5, 1, 1, 8, 4543434, 2, 4543434};

  int x = getMajorityNumber(A, 0, n);

  if (x != false || x == 0)
  {
    printf("Majoritário: %d\n", x);
  }
  else
  {
    printf("Não possui Majoritário\n");
  }

  return 0;
}

int getMajorityNumber(int *A, int p, int r)
{

  int n, q, i, ml, mr, cl, cr;

  if (p < r)
  {
    n = (r - p + 1);
    q = (p + r) / 2;
    ml = getMajorityNumber(A, p, q);
    mr = getMajorityNumber(A, q + 1, r);
    cl = cr = 0;

    for (i = p; i <= r; i++)
    {
      if (A[i] == ml)
      {
        cl++;
      }
      else if (A[i] == mr)
      {
        cr++;
      }
    }

    if (cl > n / 2)
    {
      return ml;
    }
    else if (cr > n / 2)
    {
      return mr;
    }
    else
    {
      return -1;
    }
  }
  else
  {
    return A[i];
  }

  return false;
}

int getMajorityNumberLinear(int *A, int n)
{

  int i, m, c;

  m = A[0];
  c = 1;

  for (i = 1; i < n; i++)
  {
    if (A[i] == m)
      c++;
    else if (c > 0)
      c--;
    else
    {
      m = A[i];
      c = 1;
    }
  }

  if (c > 0)
  {
    for (i = c = 0; i < n; i++)
    {
      if (A[i] == m)
        c++;
    }

    if (c > n / 2)
    {
      return m;
    }
  }

  return -1;
}
