#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main() {
    char *text = calloc(SIZE, sizeof(char));
    if (text == NULL) {
        printf("Memory allocation error!");
        return -1;
    }

    int currentSize = SIZE;
    int currentIndex = 0;
    char ltr;

    printf("Enter character, end with a period (.)\n");

    while (1) {
        ltr = getchar();

        if (ltr == '.') {
            break;
        }

        text[currentIndex++] = ltr;

        if (currentIndex == currentSize) {
            currentSize += SIZE;
            text = realloc(text, currentSize * sizeof(char));
            if (text == NULL) {
                printf(stderr, "Memory allocation error!\n");
                return -1;
            }
        }
    }

    text[currentIndex] = '\0';

    printf("Final text: %s\n", text);

    free(text);
    text = NULL;

    return 0;
}
