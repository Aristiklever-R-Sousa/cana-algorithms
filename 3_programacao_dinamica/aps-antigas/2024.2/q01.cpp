#include <bits/stdc++.h>

/* ========================================================================================
   Dados uma quantidade k de lampadas e uma quantidade n de lampadas
   que nao podem ser acesas consecutivamente

   1. L[i]: quantidade máxima de possibilidade de lampadas acesas dado i lâmpadas disponiveis
            considerando que n lampadas nao podem ficar acesas consecutivamente
   2. L[i]: 1, se i = 0
            2, se i = 1
            {L[i-1] * 2 | 2 ≤ i < n}
            {L[i-1] + L[i-1] + L[i-1] | n <= i <= k}
   3. L[k] = ?
   ======================================================================================== */

using namespace std;

int R[100][100] = {{0}};

int maiorQuantidadeConfigsLampadasAcesas(int qtdLampadas, int qtdNaoPermitidaLampadasAcesasConsec);
void rastreio();

int main()
{

  int qtdLampadas = 4,
      qtdNaoPermitidaLampadasAcesasConsec = 3;

  printf("Qtd: %d\n", maiorQuantidadeConfigsLampadasAcesas(qtdLampadas, qtdNaoPermitidaLampadasAcesasConsec));

  return 0;
}

int maiorQuantidadeConfigsLampadasAcesas(int qtdLampadas, int qtdNaoPermitidaLampadasAcesasConsec)
{
  if (qtdLampadas == 1)
    return 2;

  int L[qtdLampadas + 1], i;
  L[0] = 1;
  L[1] = 2;

  for (i = 2; i < qtdNaoPermitidaLampadasAcesasConsec; i++)
  {
    L[i] = L[i - 1] * 2;
  }

  for (i = qtdNaoPermitidaLampadasAcesasConsec; i <= qtdLampadas; i++)
  {
    L[i] = L[i - 1] + L[i - 2] + L[i - 3];
  }

  return L[qtdLampadas];
}
