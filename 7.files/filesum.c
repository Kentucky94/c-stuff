#include <stdio.h>

void intfilesum (FILE *src, int *sum, int *count) {
    int n;
    *sum = 0;
    *count = 0;
    while (fscanf(src, "%d", &n) == 1) {
        *sum += n;
        (*count)++;
    }
}

int main () {
    FILE *src;
    int sum, count;

    src = fopen("numbers.txt", "r");
    if (!src) {
        perror("numbers.txt");
        return 1;
    }

    intfilesum(src, &sum, &count);

    printf("Results: %d %d \n", sum, count);

    fclose(src);

    return 0;
}