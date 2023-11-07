#include <stdio.h>
#include <stdlib.h>


double * add(double* tab, int n, double new_elem);


int main() {
    double * array = NULL;

    for (int i = 0; i < 10; i++) {
        array = add(array, i, i);
        if (array == NULL) return -1;
    }

    printf("New array:\t");
    for (int j = 0; j < 10; j++) {
        printf("%.2lf\t", array[j]);
    }

    free(array);
    array = NULL;

    return 0;
}

double * add(double* tab, int n, double new_elem) {
    double* new_tab = calloc(n+1, sizeof(double));

    if (new_tab != NULL) {
        for (int i = 0; i < n; i++) new_tab[i] = tab[i];
        new_tab[n] = new_elem;

        free(tab);
        tab = NULL;

        return new_tab;
    }

    return NULL;
}
