#include <stdio.h>
#include <stdlib.h>

void tail(char * filename, int n);

int main() {
    tail("../input.txt", 10);
    return 0;
}

void tail(char * filename, int n) {
    FILE * inputFile = fopen(filename, "r");

    if (inputFile == NULL) {
        printf("The file input.txt cannot by opened.");
        return;
    }

    int allocatedSize = 10;

    long * linePositions = malloc(allocatedSize * sizeof(long));

    if (linePositions == NULL) {
        printf("Memory allocation error");
        return;
    }

    int lineCounter = 0;
    long position;
    char line[256];

    while ((position = ftell(inputFile)) != EOF && fgets(line, sizeof(line), inputFile) != NULL) {
        if (lineCounter == allocatedSize) {
            allocatedSize += 10;
            long * temp = realloc(linePositions, allocatedSize * sizeof(long));

            if (temp == NULL) {
                printf("Memory allocation error");
                free(linePositions);
                fclose(inputFile);
                return;
            }
            linePositions = temp;
        }
        linePositions[lineCounter] = position;
        lineCounter++;
    }

    if (fseek(inputFile, linePositions[lineCounter - n], SEEK_SET) != 0) return;

    for (int i = 0; i < n; i++) {
        if (fseek(inputFile, linePositions[lineCounter - n + i], SEEK_SET) != EOF) {
            fgets(line, sizeof(line), inputFile);
            printf("%s", line);
        }
    }

    free(linePositions);
    linePositions = NULL;
    fclose(inputFile);
}
