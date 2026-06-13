#include <stdio.h>
#include <stdlib.h>

void readFile (FILE *stream) {
    int c;
    while ((c = fgetc(stream)) != EOF) {
        if (c == '\n') {
            putchar('\n');
            continue;
        }
        putchar(c);
    }
}

int main () {
    FILE *f;
    f = fopen("file.txt", "r");
    if (!f) {
        perror("file.txt");
        exit(1);
    }

    readFile(f);

    fclose(f);

    return 0;
}