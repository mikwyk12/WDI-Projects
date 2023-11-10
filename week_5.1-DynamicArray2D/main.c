#include <stdio.h>
#include <stdlib.h>
#define ROW 4
#define COL 5


float** createMatrix(int rows, int cols);
void fillMatrix(float** tab, int rows, int cols);
void printMatrix(float** tab, int rows, int cols);
void deleteMatrix(float*** a_tab, int rows);


int main() {
    float **matrix = createMatrix(ROW, COL);

    if (matrix != NULL) {
        fillMatrix(matrix, ROW, COL);
        printf("\t----Final Matrix----\t\n");
        printMatrix(matrix, ROW, COL);
        deleteMatrix(&matrix, ROW);
    }    return 0;
}


float** createMatrix(int rows, int cols) {
    float **matrix = malloc(rows * sizeof(float *));
    if (matrix == NULL) return NULL;

    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(float));
        if (matrix[i] == NULL) deleteMatrix(&matrix, rows);
    }

    if (matrix == NULL) deleteMatrix(&matrix, rows);

    return matrix;
}

void fillMatrix(float** tab, int rows, int cols) {
    float counter = 1;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++)
            tab[row][col] = counter++;
    }
}

void printMatrix(float** tab, int rows, int cols) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            printf("%.2f\t", tab[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

void deleteMatrix(float*** a_tab, int rows) {
    for (int row = 0; row < rows; row++) {
        free((*a_tab)[row]);
        (*a_tab)[row] = NULL;
    }

    free(*a_tab);
    *a_tab = NULL;
    printf("Matrix deletion completed\n");
}
