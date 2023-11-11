#include <stdio.h>
#include <stdlib.h>

int * compress(double **, int *);
int uncompress(double **, int *, int);

int main() {
    int size = 10;
    double *array = calloc(size, sizeof(double));

    if (array == NULL) return -1;
    array[2] = 3.0;
    array[5] = 1.0;
    array[8] = 7.0;

    int *index_tab = compress(&array, &size);

    if (index_tab == NULL) return -1;

    printf("SPARSE ARRAY COMPRESSION\n");
    for (int i = 0; i < size; i++) {
        printf("index_tab[%d]: %d\t\t", i, index_tab[i]);
        printf("array[%d]: %.2lf\n", i, array[i]);
    }

    size = uncompress(&array, index_tab, size);

    printf("\nSPARSE ARRAY DECOMPRESSION\n");
    for (int i = 0; i < size; i++) {
        printf("%.2lf\t", array[i]);
    }

    free(array);
    array = NULL;

    return 0;
}


int * compress(double ** a_table, int *a_size) {
    int new_size = 0;
    int k = 0;

    for (int i = 0; i < *a_size; i++) {
        if ((*a_table)[i] != 0.0) new_size++;
    }

    double * new_table = malloc(new_size * sizeof(double));
    if (new_table == NULL) return NULL;
    int * index_table = malloc(new_size * sizeof(int));
    if (index_table == NULL) return NULL;

    for (int j = 0; j < *a_size; j++) {
        if ((*a_table)[j] != 0.0) {
            new_table[k] = (*a_table)[j];
            index_table[k] = j;
            k++;
        }
    }

    free(*a_table);

    *a_table = new_table;
    *a_size = new_size;

    return index_table;
}

int uncompress(double ** a_table, int *indexes, int size) {
    int new_size = indexes[size-1] + 1;
    double * new_table = calloc(new_size, sizeof(double));

    if (new_table == NULL) return -1;

    for (int i = 0; i < size; i++) {
        new_table[indexes[i]] = (*a_table)[i];
    }

    free(*a_table);
    *a_table = new_table;
    free(indexes);
    indexes = NULL;

    return new_size;
}