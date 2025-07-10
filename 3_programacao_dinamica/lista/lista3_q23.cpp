/**
 * Dados os operandos A[0..n-1] e B[0..n-2]
 *
 * 1. M[i,j]: maior valor obtido operandos A[i..j] e operadores B[i..j-1]
 *
 * 2. M[i,j]: 0, se i > j
 *            A[i], se i = j
 *            max{calcular(M[i,k], M[k+1,j], B[k]) i <= k < j }, caso contrário
 *
 * 3. M[0,n-1]
 *
 */

#include <bits/stdc++.h>
using namespace std;

float calcular(float x, float y, char op);
float maiorValor(float *A, char *B, int n);

int main()
{
  float A[] = {0.3, 1.0, 4.0, 0.7, 0.2};
  char B[] = {'+', 'x', '-', 'x'};

  int n = sizeof(A) / sizeof(int);

  printf("Maior valor: %.2f\n", maiorValor(A, B, n));
}

float calcular(float x, float y, char op)
{
  switch (op)
  {
  case '+':
    return x + y;

  case '-':
    return x - y;

  case 'x':
    return x * y;

  default:
    return x / y;
  }
}

float maiorValor(float *A, char *B, int n)
{
  float M[n][n] = {{0}}, q;
  int i, j, k;

  for (i = n - 1; i >= 0; i--)
  {
    for (j = 0; j < n; j++)
    {
      if (i > j)
        M[i][j] = 0;
      else if (i == j)
        M[i][j] = A[i];
      else
      {
        M[i][j] = calcular(M[i][i], M[i + 1][j], B[i]);

        for (k = i + 1; k < j; k++)
        {
          q = calcular(M[i][k], M[k + 1][j], B[k]);

          if (M[i][j] < q)
          {
            M[i][j] = q;
          }
        }
      }
    }
  }

  return M[0][n - 1];
}

// float maiorValorSolucaoProfessor(float *A, char *B, int n)
// {
//   float M[n][n] = {{0}}, q;
//   int i, j, k;

//   for (i = n - 1; i >= 0; i--)
//   {
//     M[i][i] = A[i];

//     for (j = i + 1; j < n; j++)
//     {
//       M[i][j] = calcular(M[i][i], M[i + 1][j], B[i]);

//       for (k = i + 1; k < j; k++)
//       {
//         q = calcular(M[i][k], M[k + 1][j], B[k]);

//         if (M[i][j] < q)
//         {
//           M[i][j] = q;
//         }
//       }
//     }
//   }

//   return M[0][n - 1];
// }
