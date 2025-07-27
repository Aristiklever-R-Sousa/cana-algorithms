#include <bits/stdc++.h>

using namespace std;

char *maxNumber(char *N, int n, int d);

bool compare(const float &x, const float &y)
{
  return x > y;
}

int main()
{

  char N[] = "1324205", d = 4;

  int n = strlen(N);

  char *resultado = maxNumber(N, n, d);

  printf("Maior número: %s\n", resultado);

  return 0;
}

char *maxNumber(char *N, int n, int d)
{
  char *maxNumber = (char *)malloc((n - d + 1) * sizeof(char));
  int maxNumberPosition = 0, i = 0, removes = 0;

  for (i = 0; i < n; i++)
  {
    while (removes < d && maxNumberPosition > 0 && maxNumber[maxNumberPosition - 1] < N[i])
    {
      maxNumberPosition--;
      removes++;
    }

    maxNumber[maxNumberPosition] = N[i];
    maxNumberPosition++;
  }

  while (d > removes && maxNumberPosition > 0)
  {
    maxNumberPosition--;
    removes++;
  }

  maxNumber[maxNumberPosition] = '\0';

  return maxNumber;
}
