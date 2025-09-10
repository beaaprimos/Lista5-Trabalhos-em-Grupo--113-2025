#include <stdio.h>

#define TAM 10

void ordenar(int vetor[]) {
    for (int i = 0; i < TAM - 1; i++) {
        for (int j = 0; j < TAM - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int pesquisar(int vetor[], int valor) {
    for (int i = 0; i < TAM; i++) {
        if (vetor[i] == valor) {
            return i; // Retorna a posição
        }
    }
    return -1; // Valor não encontrado
}

int main() {
    int A[TAM], B[TAM];

    // Leitura dos elementos do vetor A
    printf("Digite 10 valores para o vetor A:\n");
    for (int i = 0; i < TAM; i++) {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
        B[i] = 2 * A[i];
    }

    printf("\nVetor B ordenado:\n");
    for (int i = 0; i < TAM; i++) {
        printf("B[%d] = %d\n", i, B[i]);
    }

    int valor;
    printf("\nDigite um valor para pesquisar no vetor B: ");
    scanf("%d", &valor); \\DESGRAÇAAAAAAA

    int posicao = pesquisar(B, valor);
    if (posicao != -1) {
        printf("Valor %d encontrado na posição B[%d].\n", valor, posicao);
    } else {
        printf("Valor %d não encontrado no vetor B.\n", valor);
    }

    return 0;
}
