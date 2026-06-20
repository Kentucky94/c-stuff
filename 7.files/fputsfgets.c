#include <stdio.h>

// reads lines from f1 and writes those to f2 inside square brackets
// if a line is longer than 50 symbols, no data will be written
void string50 (FILE *f1, FILE *f2) {
    char buffer[51];

    // if successful we get address, if not we get NULL
    while (fgets(buffer, sizeof(buffer), f1)) {
        int i;
        int nlpos = -1;
        for (i = 0; i < sizeof(buffer) && buffer[i]; i++) {
            if (buffer[i] == '\n') {  // found linebreak, line was completely written
                nlpos = i;
                break;
            }
        }
        
        // no linebreak means either end of file or too long line
        if (nlpos == -1) {
            int c;
            fputc('n', f2);
            while ((c = fgetc(f1)) != EOF) {
                if (c == '\n') {
                    break;
                }
            }
        } else {
            buffer[nlpos] = '\0';
            fprintf(f2, "[%s]\n", buffer);
        }
    }
}

int main () {
    // char *string = "Hello world\n";

    // fputs(string, stdout);

    FILE *src, *dest;

    src = fopen("sincos.txt", "r");
    if (!src) {
        perror("sincos.txt");
        return 1;
    }

    dest = fopen("dest.txt", "w");
    if (!src) {
        perror("dest.txt");
        return 2;
    }

    string50(src, dest);

    return 0;
}