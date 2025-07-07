#include <bits/stdc++.h>


int main() {
    int A*, n = 100000, i;
    double ti, tf;

    A = (int *) calloc(n, sizeof(int));

    for(i = 0; i < n; i++) {
        A[i] = rand() % n + 1;
    }

    ti = click();
    quickSort();
    tf = clock();
    printf("Tempo: %f\n", (tf - ti) / CLOCKS_PER_SECONDS);

    free(A);

    return 0;
}

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