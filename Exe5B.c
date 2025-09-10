#include <stdio.h>

int main() {
    double x, S = 0.0;
    int i;

    printf("Digite o valor de x: ");
    scanf("%lf", &x);

    for (i = 1; i <= 20; i++) {
        if (i % 2 == 0) {
            S -= x / i;
        } else {
            S += x / i;
        }
    }

    printf("Resultado da serie b): %.2lf\n", S);

    return 0;
}
