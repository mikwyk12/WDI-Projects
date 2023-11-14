#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *in_file;

    in_file = fopen("../input.txt", "rb");

    if (in_file == NULL) {
        printf("The file input.txt cannot by opened.");
        return -1;
    }

    fseek( in_file, 0, SEEK_END);
    int fileSize = ftell(in_file);
    fseek(in_file, 0, SEEK_SET);

    char * array = malloc(fileSize);
    fread(array, 1, fileSize, in_file);

    fclose(in_file);

    FILE *out_file;

    out_file = fopen("../output.txt", "wb");

    if (out_file == NULL) {
        printf("The file output.txt cannot by opened.");
        free(array);
        return -1;
    }

    for (int i = 0; i < 3; i++) fwrite(array, 1, fileSize, out_file);
    memset(array, 'A', fileSize);

    fseek(out_file, fileSize-1, SEEK_SET);
    fwrite(array, 1, fileSize, out_file);

    fclose(out_file);
    free(array);

    return 0;
}
