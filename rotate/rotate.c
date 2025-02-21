#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

void RotateArray(int** matrix, int n) {
    // First, we transpose rows to columns
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Reverse all the rows
    for(int i=0; i<n; i++){
        for(int j=0, k=n-1; j<k; j++, k--){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][k];
            matrix[i][k] = temp;
        }
    }
}

void freeMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(*(matrix + i));
    }
    return;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Please input a file name when you run it\n");
        return EXIT_FAILURE;
    }
    FILE* f = fopen(argv[1], "r");

    if (f == NULL) {
        printf("Failed to open file\n");
        return EXIT_FAILURE;
    }
    

    int rows, cols;
    assert(fscanf(f, "%d %d", &rows, &cols));
    // int matrix[rows][cols];
    int** matrix = (int**) malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*) malloc(sizeof(int) * cols);
    }
    // Now we fill it
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            assert(fscanf(f, "%d", (*(matrix + i) + j)));
        }
    }

    RotateArray(matrix, rows);

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    freeMatrix(matrix, rows);
    return EXIT_SUCCESS;

}