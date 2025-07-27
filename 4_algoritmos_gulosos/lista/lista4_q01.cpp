#include <bits/stdc++.h>

using namespace std;

struct Product
{
  int id;
  float weight;
  float value;
  float weightPerValue;
};

float mochilaFracionada(Product *P, int n, float c);

bool compare(const Product &x, const Product &y)
{
  return x.weightPerValue > y.weightPerValue;
}

int main()
{

  float V[] = {18.00, 7.00, 13.00, 9.00, 8.00},
        P[] = {8.00, 3.00, 6.00, 5.00, 4.00},
        V_P[] = {2.25, 2.33, 2.16, 1.80, 2.00},
        c = 10.00;

  int n = 5;

  Product Pro[n];

  for (int i = 0; i < n; i++)
  {
    Pro[i].id = i;
    Pro[i].weight = P[i];
    Pro[i].value = V[i];
    Pro[i].weightPerValue = V_P[i];
  }

  printf("Maior valor possível: %.2f\n", mochilaFracionada(Pro, n, c));

  return 0;
}

float mochilaFracionada(Product *P, int n, float c)
{
  int i = 0;
  float l = 0;

  sort(P, P + n, compare);

  while (i < n && c >= P[i].weight)
  {
    l += P[i].value;
    c -= P[i].weight;
    i++;
  }

  if (i < n && c > 0)
  {
    l += c * (P[i].value / P[i].weight);
  }

  return l;
}
