#include <stdio.h>

int main (int argc, char **argv) {
    FILE *src, *dest;
    int c;

    if (argc < 3) {
        printf("Too few args\n");
        return 0;
    }

    src = fopen(argv[1], "r");
    if (!src) {
        perror(argv[1]);
        return 1;
    }

    dest = fopen(argv[2], "w");
    if (!src) {
        perror(argv[2]);
        return 2;
    }

    while((c = fgetc(src)) != EOF) {
        fputc(c, dest);
    }

    fclose(src);
    fclose(dest);
    
    return 0;
}