#include <bits/stdc++.h>

/* ==================================================================
   Dadas duas cadeias A[0..m-1] e B[0..n-1]
   1. L[i,j]: tamanho da maior subseq. comum de A[0..i-1] e B[0..j-1]
   2. L[i,j]: 0, se i = 0 ou j = 0
              1 + L[i-1,j-1], se A[i-1] = B[j-1]
              Max(L[i,j-1], L[i-1,j]), caso contrário
   3. L[m,n] = ?
   ================================================================== */

using namespace std;

int R[201][201] = {0};

void rastreio(char *A, int m, int n);

int lcs(char *A, char *B, int m, int n);
int lcsWithTracking(char *A, char *B, int m, int n);

int main()
{
  char A[200], B[200];

  strcpy(A, "ACCGGTCGAGTGCGCGGAAG");
  strcpy(B, "GCGTTCGGAATGCCGTTGC");

  // strcpy(A, "BDCABA");
  // strcpy(B, "ABCBDAB");

  int m = strlen(A);
  int n = strlen(B);
  printf("Tamanho da maior subseq. comum: %d\n", lcs(A, B, m, n));
  printf("Tamanho da maior subseq. comum: %d\n", lcsWithTracking(A, B, m, n));

  rastreio(A, m, n);
  printf("\n");

  return 0;
}

int lcs(char *A, char *B, int m, int n)
{
  int L[m + 1][n + 1] = {0};

  for (int i = 0; i <= m; i++)
  {
    L[i][0] = 0;
  }

  for (int i = 0; i <= n; i++)
  {
    L[0][i] = 0;
  }

  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (A[i - 1] == B[j - 1])
      {
        L[i][j] = 1 + L[i - 1][j - 1];
      }
      else
      {
        L[i][j] = max(L[i][j - 1], L[i - 1][j]);
      }
    }
  }

  return L[m][n];
}

int lcsWithTracking(char *A, char *B, int m, int n)
{
  int L[m + 1][n + 1] = {0};

  for (int i = 0; i <= m; i++)
  {
    L[i][0] = 0;
  }

  for (int i = 0; i <= n; i++)
  {
    L[0][i] = 0;
  }

  for (int i = 1; i <= m; i++)
  {
    printf("Linha #%d: ", i);

    for (int j = 1; j <= n; j++)
    {
      if (A[i - 1] == B[j - 1])
      {
        L[i][j] = 1 + L[i - 1][j - 1];
        R[i][j] = 1; // Recuar linha e coluna
      }
      else
      {
        if (L[i - 1][j] >= L[i][j - 1])
        {
          L[i][j] = L[i - 1][j];
          R[i][j] = 2; // Recuar linha
        }
        else
        {
          L[i][j] = L[i][j - 1];
          R[i][j] = 3; // Recuar coluna
        }
      }
      printf(" %d ", R[i][j]);
    }
    printf("\n");
  }

  return L[m][n];
}

void rastreio(char *A, int m, int n)
{
  if (m && n)
  {
    if (R[m][n] == 1)
    {
      rastreio(A, m - 1, n - 1);
      printf("%c", A[m - 1]);
    }
    else if (R[m][n] == 2)
      rastreio(A, m - 1, n);
    else
      rastreio(A, m, n - 1);
  }
}
