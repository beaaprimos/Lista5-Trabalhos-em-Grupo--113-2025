#include <stdio.h>

int main() {
    int n= 1;
    int d;
    double S = 0.0;

    for (d = 1; d <= 50; d++) {
        S += (double)n / d;
        n += 2;
    }

    printf("Resultado da serie a): %.2lf\n", S);

    return 0;
}
