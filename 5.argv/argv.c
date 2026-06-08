#include <stdio.h>

int main (int argc, char **argv) {
    for (int i = 0; i < argc; i++) {
        // %s (string) prints a string in address taken from argv[i]
        printf("[%s]\n", argv[i]);
        // %p (pointer) prints address itself
        printf("[%p]\n", argv[i]);
    }

    return 0;
}