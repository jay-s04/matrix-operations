#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "matrix.h"


int main(int argc, char** argv) {
    assert(argc == 2);
    FILE* f = fopen(argv[1], "r");
    assert(f != NULL);

    int n;
    assert(fscanf(f, "%d", &n));
    double** matrix = (double**) malloc(sizeof(double*) * n);
    for (int i = 0; i < n; i++) {
        matrix[i] = (double*) malloc(sizeof(double) * n);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            assert(fscanf(f, "%lf", (*(matrix + i) + j)));
        }
    }
    

    // printMatrix(matrix, n);
    printf("%ld\n", determinant(matrix, n));
    killMatrix(matrix, n);
}