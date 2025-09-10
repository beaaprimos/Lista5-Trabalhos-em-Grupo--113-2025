#include <stdio.h>

#define TAM 15

int main() {
    float compra[TAM], venda[TAM];
    float totalCompra = 0, totalVenda = 0, lucroTotal = 0;
    int lucroMenor10 = 0, lucroEntre10e20 = 0, lucroMaior20 = 0;

    for (int i = 0; i < TAM; i++) {
        printf("Mercadoria %d\n", i + 1);
        printf("Preço de compra: R$ ");
        scanf("%f", &compra[i]);
        printf("Preço de venda: R$ ");
        scanf("%f", &venda[i]);

        // Acumulando totais
        totalCompra += compra[i];
        totalVenda += venda[i];

        
        float lucro = venda[i] - compra[i];
        float percentualLucro = (lucro / compra[i]) * 100;

        lucroTotal += lucro;

        if (percentualLucro < 10.0)
            lucroMenor10++;
        else if (percentualLucro <= 20.0)
            lucroEntre10e20++;
        else
            lucroMaior20++;
    }

    printf("\n RELATÓRIO DE LUCROS\n");
    printf("Total de compra: R$ %.2f\n", totalCompra);
    printf("Total de venda: R$ %.2f\n", totalVenda);
    printf("Lucro total: R$ %.2f\n", lucroTotal);
    printf("\nClassificação das mercadorias:\n");
    printf("Lucro < 10%%: %d mercadorias\n", lucroMenor10);
    printf(" Lucro entre 10%% e 20%%: %d mercadorias\n", lucroEntre10e20);
    printf(" Lucro > 20%%: %d mercadorias\n", lucroMaior20);

    return 0;
}
