#include <stdio.h>

float media(float n1, float n2) {
    return (n1 + n2) / 2.0;
}

int main() {
    float a, b, result
    printf("Insira o primeiro numero: ");
    scanf("%f", &a);
    printf("Insira o segundo numero: ");
    scanf("%f", &b);
    result = media(a, b);
    printf("\nNumero 1: %.2f\n", a);
    printf("Numero 2: %.2f\n", b);
    printf("Media : %.2f\n", result);

    return 0;
}
