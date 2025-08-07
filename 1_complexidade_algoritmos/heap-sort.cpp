// A chave de qualquer nó não é maior que a chave de qualquer de seus filhos;
// É uma árvore binária completa

#include <bits/stdc++.h>

using namespace std;

void maxHeapify(int *A, int i, int n);
void buildMaxHeap(int *A, int n);
void heapSort(int *A, int n);

int main()
{
  return 0;
}

void maxHeapify(int *A, int i, int n)
{
  int l, r, m;

  l = 2 * i + 1;
  r = 2 * i + 2;
  m = i;

  if (l < n && A[l] > A[m])
    m = l;

  if (r < n && A[r] > A[m])
    m = r;

  if (m != i)
  {
    swap(A[i], A[m]);
    maxHeapify(A, m, n);
  }
}

void buildMaxHeap(int *A, int n)
{
  for (int i = n / 2 - 1; i >= 0; i--)
    maxHeapify(A, i, n);
}

void heapSort(int *A, int n)
{
  int i;
  buildMaxHeap(A, n);

  for (i = n - 1; i > 0; i++)
  {
    swap(A[0], A[i]);
    maxHeapify(A, 0, i);
  }
}
