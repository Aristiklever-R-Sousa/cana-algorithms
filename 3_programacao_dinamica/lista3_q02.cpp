#include <bits/stdc++.h>

/* ==================================================================
   Dada uma cadeia S[0..n-1]
   1. P[i,j]: maior subsequencia palindromo de S[i...j]
   2. P[i,j]: 0, se i > j
              1, se i = j
              2 + P[i+1,j-1], se i < j e S[i] = S[j]
              Max(P[i,j-1], P[i-1,j]), caso contrário
   3. P[1,n] = ?
   ================================================================== */

using namespace std;

int R[201][201] = {0};

void rastreio(char *S, int m, int n);

int lcs(char *S, int n);

int main()
{
  char S[200];

  // strcpy(S, "ACGTAGTCAAAATCG");
  strcpy(S, "ACATCA");
  int n = strlen(S);
  printf("Tamanho da maior subseq. que é um palíndromo: %d\n\n", lcs(S, n));

  printf("Rastreio: \n");
  rastreio(S, n - 1, n - 1);
  printf("\n");

  return 0;
}

int lcs(char *S, int n)
{
  printf("Tam: %d\n", n);

  int P[n][n] = {0};

  for (int i = n - 1; i >= 0; i--)
  {
    printf("Linha #%d: ", i);
    for (int j = 0; j < n; j++)
    {
      if (i > j)
      {
        P[i][j] = 0;
      }
      else if (i == j)
      {
        P[i][j] = 1;
      }
      else
      {
        if (S[i] == S[j])
        {
          P[i][j] = 2 + P[i + 1][j - 1]; // Avança linha, recua coluna
          R[i][j] = 1;
        }
        else
        {
          if (P[i][j - 1] > P[i + 1][j])
          {
            P[i][j] = P[i][j - 1]; // Recua coluna
            R[i][j] = 2;
          }
          else
          {
            P[i][j] = P[i + 1][j]; // Avança linha
            R[i][j] = 3;
          }
        }
      }
      printf(" %d ", P[i][j]);
    }

    printf("\n");
  }

  return P[0][n - 1];
}

void rastreio(char *A, int m, int n)
{
  // # TODO: Entender isso melhor

  if (m && n)
  {
    if (R[m][n] == 1)
    {
      rastreio(A, m + 1, n - 1);
      printf("%c", A[m]);
    }
    else if (R[m][n] == 2)
      rastreio(A, m, n - 1);
    else
      rastreio(A, m + 1, n);
  }
}
