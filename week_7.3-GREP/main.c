#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1000

void grep(char* filename, char* substring);

int main() {
    grep("../input.txt", "gravida");

    return 0;
}

void grep(char* filename, char* substring) {
    FILE * inputFile = fopen(filename, "r");

    if (inputFile != NULL) {
        char line[MAX_SIZE];

        while (fgets(line, sizeof(line), inputFile) != NULL) {
            if (strstr(line, substring) != NULL)
                printf("%s\n", line);
        }

        fclose(inputFile);
    }
    else printf("The file input.txt cannot by opened.");
}
