/**
 * E[i,j]: distância de edição entre A[0. . .i-1] e B[0. . .j-1].
 * diff(X,Y) = 1, se X 6= Y; e 0, caso contrário
 *
 * S[i]: 1, se i = 0;
 *       1, se i>0 e não há valor menor que A[i] antes dele
 *       max{1+S[k]:0≤k≤i e A[k]<A[i]}, caso contrário.
 *
 * Calcular o maior valor de S.
 *
 */

#include <bits/stdc++.h>
using namespace std;

int R[100] = {0};

int distanciaDeEdicao(char *A, char *B, int an, int bn);
void rastreio(int *A, int n);

int main()
{
  char A[] = "SNOWY", B[] = "SUNNY";
  int an = sizeof(A) / sizeof(char),
      bn = sizeof(B) / sizeof(char);

  printf("Dist de Edicao: %d\n", distanciaDeEdicao(A, B, an, bn));
}

int distanciaDeEdicao(char *A, char *B, int an, int bn)
{
  int E[an + 1][bn + 1], i, j, sum1, sum2, sum3;

  for (i = 0; i <= an; i++)
    E[i][0] = i;

  for (i = 0; i <= an; i++)
    E[0][i] = i;

  for (i = 1; i <= an; i++)
    for (j = 1; j <= bn; j++)
    {
      sum1 = E[i - 1][j] + 1;
      sum2 = E[i][j - 1] + 1;
      sum3 = E[i - 1][j - 1] + (A[i - 1] != B[j - 1] ? 1 : 0);

      // E[i][j] = min(sum1, sum2);

      if (sum1 < sum2 && sum1 < sum3)
      {
        E[i][j] = sum1;
      }
      else if (sum2 < sum1 && sum2 < sum3)
      {
        E[i][j] = sum2;
      }
      else if (sum3 < sum1 && sum3 < sum2)
      {
        E[i][j] = sum3;
      }
    }

  return E[an][bn];
}
