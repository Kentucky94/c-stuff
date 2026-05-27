#include <stdio.h>
#include <math.h>

double discrim(double a, double b, double c) {
    return b * b - 4 * a * c;
}

int main() {
    double p, q, r, d, root_1, root_2;
    int n;

    printf("Please print equation coefficients\n");
    n = scanf("%lf %lf %lf", &p, &q, &r);

    // if we have less than 3 successful parameters taken, exit with failure
    if (n != 3) {
        printf("Error, wrong input!\n");
        return 1;
    }

    if (p == 0) {
        printf("Not a quadratic equation!\n");
        return 2;
    }

    d = discrim(p, q, r);

    if (d < 0) {
        printf("No roots\n");
        return 0;
    }

    d = sqrt(d);
    root_1 = (-q + d) / 2 * p;
    root_2 = (-q - d) / 2 * p;

    printf("Roots are: %.5lf %.5lf", root_1, root_2);

    return 0;
}