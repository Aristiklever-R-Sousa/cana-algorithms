/**
 * C[i, j]: menor custo para fazer os cortes necessários entre as marcas i e j.
 * C[i, j]: 0, se j-i≤1 ou se não há ponto de corte entre i e j;
 *          min{C[i,Pk]+C[Pk,j]: i<Pk<j} + (j-i), caso contrário.
 * Calcular C[0, l]
 */

#include <bits/stdc++.h>
using namespace std;

int menorCusto(int l, int *K, int nk);

int main()
{

  int l = 10,
      k[3] = {2, 4, 7},
      nk = 3;

  printf("Menor custo: %d\n", menorCusto(l, k, nk));

  return 0;
}

int menorCusto(int l, int *K, int nk)
{

  int C[l + 1][l + 1];

  for (int i = l; i >= 0; i--)
    for (int j = 0; j <= l; j++)
    {
      if (j - i <= 1)
        C[i][j] = 0;
      else
      {
        C[i][j] = INT_MAX;

        for (int k = 0; k < nk; k++)
        {
          if (i < K[k] && K[k] < j)
            C[i][j] = min(C[i][j], C[i][K[k]] + C[K[k]][j] + (j - i));
        }

        if (C[i][j] == INT_MAX)
        {
          C[i][j] = 0;
        }
      }

      // printf("C[%d][%d]: %d\n", i, j, C[i][j]);
    }

  return C[0][l];
}
