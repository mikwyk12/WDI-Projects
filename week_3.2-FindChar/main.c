#include <stdio.h>
#define SIZE 20


char * find_char(char *text, char ltr);


int main() {
    char tab[SIZE];
    char letter;
    char* result = NULL;

    printf("Enter your text and wanted character:\n");
    fgets(tab, SIZE, stdin);
    scanf("%c", &letter);

    result = find_char(tab, letter);

    if (result == NULL) printf("There is no character %c in your text.\n", letter);
    else printf("There is a character %c in your text.\nAddress of the character: %p\n", letter, result);

    return 0;
}

char * find_char(char *text, char ltr){
    for (int i = 0; i < SIZE; i++) {
        if (text[i] == ltr) {
            return &text[i];
        }
    }
    return NULL;
}
