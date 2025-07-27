#include <bits/stdc++.h>

using namespace std;

struct Task
{
  int id;
  int prazo;
  float multa;
};

float minMultaTotalSum(Task *T, int n);

bool compare(const Task &x, const Task &y)
{
  return x.multa > y.multa;
}

int main()
{

  int M[] = {40, 30, 50, 20},
      P[] = {2, 1, 3, 2};

  int n = sizeof(M) / sizeof(int);

  Task T[n];

  for (int i = 0; i < n; i++)
  {
    T[i].id = i + 1;
    T[i].prazo = P[i];
    T[i].multa = M[i];
  }

  printf("Valor mínimo total de multas: %.2f\n", minMultaTotalSum(T, n));

  return 0;
}

float minMultaTotalSum(Task *T, int n)
{
  int i = 0, D[n] = {0}, prazo = 0;
  float totalMulta = 0;

  sort(T, T + n, compare);

  for (i = 0; i < n; i++)
  {
    prazo = T[i].prazo - 1;

    while (prazo >= 0 && D[prazo])
    {
      prazo--;
    }
    if (prazo >= 0)
    {
      D[T[i].prazo - 1] = T[i].id;
    }
    else
    {
      totalMulta += T[i].multa;
    }
  }

  return totalMulta;
}
