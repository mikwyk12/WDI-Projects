#include <stdio.h>
#define MAX_SIZE 100

int main() {
    FILE *in_file, *out_file;
    int ltr = 0;
    char line[MAX_SIZE];

    in_file = fopen("../input.txt", "r");
    if (in_file == NULL) {
        printf("The file input.txt cannot by opened.");
        return -1;
    }

    out_file = fopen("../output.txt", "w");
    if (out_file == NULL) {
        printf("The file output.txt cannot by opened.");
        fclose(in_file);
        return -1;
    }

    while (ltr != EOF) {
        ltr = fgetc(in_file);
        fputc(ltr, out_file);
    }

    printf("\n\n");
    rewind(in_file);

    while (fgets(line, MAX_SIZE, in_file) != NULL) {
        fputs(line, out_file);
    }

    fclose(in_file);
    fclose(out_file);

    return 0;
}
