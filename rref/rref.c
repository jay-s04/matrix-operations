#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>

void printMatrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%lf\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void GaussianElimination(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        double factor, mult;
        for (int j = 0; j < rows; j++) {
            factor = matrix[i][i];
            mult = matrix[j][i] / matrix[i][i];
            for (int k = 0; k < cols; k++) {
                if (j == i) {
                    matrix[j][k] /= factor; // Make the diagonal ones
                }
                else {
                    // For everything that is not the pivots
                    matrix[j][k] -= (matrix[i][k] * mult);
                }
            }
        }
    }
    // convert -0.00 to 0
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == -0) matrix[i][j] = 0;
        }
    }
    return;
}



void killMatrix(double** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main(int argc, char** argv) {
    assert(argc == 2);
    FILE* f = fopen(argv[1], "r");
    assert(f != NULL);

    int rows, cols;
    assert(fscanf(f, "%d %d", &rows, &cols));
    double** matrix = (double**) malloc(sizeof(double*) * rows);
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double*) malloc(sizeof(double) * cols);
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            assert(fscanf(f, "%lf", (*(matrix + i) + j)));
        }
    }
    GaussianElimination(matrix, rows, cols);
    printMatrix(matrix, rows, cols);
    killMatrix(matrix, rows);
    

    return EXIT_SUCCESS;
}