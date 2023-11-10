#include <stdio.h>
#include <stdlib.h>
#define SIZE 5


int createContinousMatrix(double***, int);
void deleteContinousMatrix(double***);
int copyMatrix(double***, double**, int);
void fillMatrix(double**, int, int);
void printMatrix(double**, int, int);

int main() {
    double **matrix1;
    double **matrix2;

    if (createContinousMatrix(&matrix1, SIZE) == -1) return -1;
    fillMatrix(matrix1, SIZE, SIZE);
    printf("MATRIX 1\n");
    printMatrix(matrix1, SIZE, SIZE);

    copyMatrix(&matrix2, matrix1,SIZE);
    printf("MATRIX 2 <- Copy of MATRIX 1\n");
    printMatrix(matrix2, SIZE, SIZE);

    deleteContinousMatrix(&matrix1);
    deleteContinousMatrix(&matrix2);

    return 0;
}

int createContinousMatrix(double*** atab, int n) {
    double **matrix = malloc(n * sizeof(double *));

    if (matrix == NULL) return -1;

    double *data = malloc(n * n * sizeof(double));
    if (data == NULL) {
        free(matrix);
        return -1;
    }

    for (int i = 0; i < n; i++) matrix[i] = &data[i * n];

    *atab = matrix;

    return 0;
}

void deleteContinousMatrix(double*** atab) {
    free(*atab[0]);
    *atab[0] = NULL;
    free(*atab);
    *atab = NULL;
}

int copyMatrix(double*** pdest, double** src, int n) {
    double **dest;
    int res = createContinousMatrix(&dest, n);

    if (res == -1) return -1;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            dest[row][col] = src[row][col];
        }
    }
    *pdest = dest;

    return 0;
}

void fillMatrix(double** tab, int rows, int cols) {
    float counter = 1;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++)
            tab[row][col] = counter++;
    }
}

void printMatrix(double** tab, int rows, int cols) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            printf("%.2f\t", tab[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}
