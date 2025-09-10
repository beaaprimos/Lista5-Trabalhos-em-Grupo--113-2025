#include <stdio.h>
#include <math.h>

unsigned long long fatorial(int n) {
    if (n < 0) return 0; 
    unsigned long long fat = 1;
    for (int i = 1; i <= n; i++) {
        fat *= i;
    }
    return fat;
}

int main() {
    int A[6];
    double B[6][3]; // Matriz B com 6 linhas e 3 colunas

    printf("Digite 6 valores inteiros para a matriz A:\n");
    for (int i = 0; i < 6; i++) {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);

        B[i][0] = sqrt(A[i]);       
        B[i][1] = fatorial(A[i]);    
        B[i][2] = pow(A[i], 5);    
    }

    printf("\nMatriz B (Raiz Quadrada | Fatorial | Potência de 5):\n");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < 6; i++) {
        printf("B[%d]: %.2f\t%llu\t%.2f\n", i, B[i][0], (unsigned long long)B[i][1], B[i][2]);
    }

    return 0;
}
