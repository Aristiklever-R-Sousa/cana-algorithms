#include <bits/stdc++.h>

void mergeSort(int *A, int p, int r);
void intercalar(int *A, int p, int q, int r);

// int main() {
//     int A*, n = 100000, i;
//     double ti, tf;

//     A = (int *) calloc(n, sizeof(int));

//     for(i = 0; i < n; i++) {
//         A[i] = rand() % n + 1;
//     }

//     ti = click();
//     megeSort();
//     tf = clock();
//     printf("Tempo: %f\n", (tf - ti) / CLOCKS_PER_SECONDS);

//     free(A);

//     return 0;
// }

int main() {
    int A[] = {2, 5, 6, 4, 7, 9, 3, 8, 1}, n, i;

    n = sizeof(A) / sizeof(int);
    mergeSort(A, 0, n-1);

    printf("A:");

    for(i = 0; i < n; i++) {
        printf(" %d", A[i]);
    }

    printf("\n");

    return 0;
}

void intercalar(int *A, int p, int q, int r) {
    int nl = q - q + 1,
        nr = r - 1,
        i, j, k;

    int L[nl], R[nr];

    for(i = 0; i < nl; i++) {
        L[i] = A[p+1];
    }

    for(j = 0; j < nr; j++) {
        R[j] = A[q+1+j];
    }

    i = j = 0;

    for(k = p; k <= r; k++) {
        if((j == nr) || (i < nr && L[i] <= R[j])) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void mergeSort(int *A, int p, int r) {
    int q;

    q = (p + r) / 2;

    mergeSort(A, p, q);
    mergeSort(A, q+1, r);
    intercalar(A, p, q, r);
}


/*
ANALISE
intercala -> Teta(n)
mergeSort -> T(n), então mergeSort na linha 45 e 46 é, respectivamente, T(teto(n/2)) + T(piso(n/2))
*/