#include <stdio.h>

int main() {
    int X, B;
    int d1, d2, d3;
    int dec;

    printf("Digite um numero de 3 digitos (X): ");
    scanf("%d", &X);

    printf("Digite a base (B) entre 1 e 10: ");
    scanf("%d", &B);

    if (B < 1 || B > 10) {
        printf("Base invalida. Deve estar entre 1 e 10.\n");
        return 1;
    }

    d1 = X / 100;         // centena
    d2 = (X / 10) % 10;   // dezena
    d3 = X % 10;          // unidade

    if (d1 >= B || d2 >= B || d3 >= B) {
        printf("Digitos invalidos para a base %d.\n", B);
        return 1;
    }

    dec = d1 * B * B + d2 * B + d3;

    printf("O numero %d na base %d equivale a %d na base 10.\n", X, B, dec);

    return 0;
}
