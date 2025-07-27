#include <bits/stdc++.h>

using namespace std;

int qtdCaixas(float *L, int n, float c, int qttMaxByBox);

bool compare(const float &x, const float &y)
{
  return x > y;
}

int main()
{

  float L[] = {1, 2, 1.5}, c = 3;

  int n = sizeof(L) / sizeof(float), qttMaxByBox = 2;

  printf("Menor quantidade de caixas: %d\n", qtdCaixas(L, n, c, qttMaxByBox));

  return 0;
}

int qtdCaixas(float *L, int n, float c, int qttMaxByBox)
{
  int i = 0, qtt = 1, currentQttInBox = 0;
  float currentAvailableWeightInBox = c;

  sort(L, L + n, compare);

  for (i = 0; i < n; i++)
  {
    printf("L[%d] = %.2f\n", i, L[i]);
  }

  for (i = 0; i < n; i++)
  {
    if (L[i] > currentAvailableWeightInBox || currentQttInBox >= qttMaxByBox)
    {
      qtt++;
      currentQttInBox = 0;
      currentAvailableWeightInBox = c;
    }
    else
    {
      currentQttInBox++;
      currentAvailableWeightInBox -= L[i];
    }
  }

  return qtt;
}
