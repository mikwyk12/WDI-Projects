#include <stdio.h>
#include <string.h>


void sort_array(char *tab[], int size);
void print_array(char *tab[], int size);


int main() {
    char* tab[5] = {"Kot ma Ale", "Ala ma kota", "Ola ma psa", "Pies ma pchly", "Ala nie lubi Oli"};
    int size = sizeof(tab)/sizeof(char *);

    printf("Array before sorting:\n\n");
    print_array(tab, size);

    sort_array(tab, size);

    printf("\nArray after sorting:\n\n");
    print_array(tab, size);

    return 0;
}


void sort_array(char *tab[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(tab[j], tab[j+1]) > 0) {
                char* tmp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = tmp;
            }
        }
    }
}
void print_array(char *tab[], int size){
    for (int i = 0; i < size; i++) puts(tab[i]);
}

