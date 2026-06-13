#include <stdio.h>
#include <math.h>

int main () {
    FILE *dest;
    int grad;

    dest = fopen("sincos.txt", "w");
    if (!dest) {
        perror("sincos.txt");
        return 1;
    }

    for (grad = 0; grad < 360; grad++) {
        double rads, s, c;
        rads = (double)grad * M_PI / 180.0;
        s = sin(rads);
        c = cos(rads);
        fprintf(dest, "%03d % 7.5f % 7.5f\n", grad, s, c);
    }

    fclose(dest);

    return 0;
}