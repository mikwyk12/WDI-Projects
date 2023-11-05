#include <stdio.h>
#define SIZE 9


void bubble_sort(int tab[], int size);
void print_array(int tab[], int size);


int main() {
    int array[SIZE] = {7,6,9,3,1,5,7,12,8};

    printf("Array before sorting: ");
    print_array(array, SIZE);

    bubble_sort(array, SIZE);

    printf("\nArray after sorting: ");
    print_array(array, SIZE);

    return 0;
}


void bubble_sort(int tab[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i; j++) {
            if (tab[j] > tab[j+1]) {
                tab[j] += tab[j+1];
                tab[j+1] = tab[j] - tab[j+1];
                tab[j] -= tab[j+1];
            }
        }
    }
}


void print_array(int tab[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }
}