#include <bits/stdc++.h>

using namespace std;

/**
 * DADO UM VETOR A COM N ELEMENTOS INTEIROS
 * 1. S[i]: tamanho da maior subsequencia crescente incluindo o elemento A[i]
 * 2. S[i]: 1, se i = 0
            1, se não existe 0 <= j < i tal que A[j] < A[i]
            max{1 + S[j]: 0 <= j < i e A[j] < A[i]}, caso contrário
 * 3. Encontrar o maior valor de S
 */

int sscmax(int *A, int n);

int main()
{
  int A[] = {};

  return 0;
}
