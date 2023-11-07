#include <stdio.h>
#include <stdlib.h>


int* dynamic_array(int size);


int main() {
    int size = 0;

    printf("Enter the number of array elements:\n");
    scanf("%d", &size);

    int* array = dynamic_array(size);
    if (array != NULL) {
        for (int i = 0; i < size; i++) printf("%d\t", *(array+i));
    }

    free(array);
    array = NULL;

    return 0;
}

int* dynamic_array(int size) {
    int* new_array = calloc(size, sizeof(int));

    if (new_array != NULL) {
        for (int i = 0; i < size; i++) new_array[i] = (2 * i) + 1;
        return new_array;
    }
    return NULL;
}
