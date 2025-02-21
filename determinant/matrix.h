#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>

void printMatrix(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf\t", matrix[i][j]);
        }
        printf("\n");
    }
}
void killMatrix(double** matrix, int n) {
    if (matrix == NULL) return;
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Now we slowly break down the determinant functions

long determinant(double** matrix, int n) {
    if (n == 1) {
        long answer = (long) **matrix;
        return answer;
    }
    if (n == 2) {
        long answer = (long) ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
        return answer;
    }

    double det = 0;
    for (int c = 0; c < n; c++) {
        double** submatrix = (double**) malloc(sizeof(double*) * n);
        for (int s = 0; s < n; s++) {
            submatrix[s] = (double*) malloc(sizeof(double) * n);
        }

        for (int i = 1; i < n; ++i) {
            int subcolumn = 0;
            for (int j = 0; j < n; ++j) {
                if (j == c) continue;
                // Fill submatrix
                submatrix[i - 1][subcolumn++] = matrix[i][j];
            }
        }

        int sign = (int) pow(-1, c);
        det += sign * (matrix[0][c]) * determinant(submatrix, n - 1);
        killMatrix(submatrix, n);
    }

    return (long) det;

}