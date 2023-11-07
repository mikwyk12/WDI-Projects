#include <stdio.h>


void char_delete(char text[], char ltr);


int main() {
    char txt[] = "Zaawansowane techniki programowania ";
    char letter;

    printf("Your text: ");
    puts(txt);
    printf("Enter a character which you want to delete:");
    scanf("%c", &letter);

    char_delete(txt, letter);

    return 0;
}


void char_delete(char text[], char ltr) {
    char * p2 = text;
    for (char * p1 = text; *p1 != '\0'; p1++) {
        if (*p1 != ltr) {
            *(p2++) = *p1;
        }
    }
    *p2 = '\0';
    printf("\nFinal result:\n");
    puts(text);
}
