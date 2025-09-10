#include <stdio.h>

int main() {
    int i, sx, qtdM = 0, qtdH = 0;
    float alt, mAlt, menorAlt;
    float somamu = 0.0;

    printf("Insira a altura da pessoa 1: ");
    scanf("%f", &alt);
    printf("Insira  o sexo da pessoa 1 (1 = masculino, 2 = feminino): ");
    scanf("%d", &sx);

    mAlt = menorAlt = alt;

    if (sx == 1) {
        qtdH++;
    } else if (sx == 2) {
        somamu += alt;
        qtdM++;}
    
    for (i = 2; i <= 50; i++) {
        printf("Insira a altura da pessoa %d: ", i);
        scanf("%f", &alt);
        printf("Insira o sexo da pessoa %d (1 = masculino, 2 = feminino): ", i);
        scanf("%d", &sx);
        
        if (alt > mAlt) {
            mAlt = alt;
        }
        if (alt < menorAlt) {
            menorAlt = alt;
        }
        if (sx == 1) {
            qtdH++;
        } else if (sx == 2) {
            somamu += alt;
            qtdM++;
        }
    }
    printf("\nA maior altura do grupo: %.2f\n", mAlt);
    printf("A menor altur do grupo: %.2f\n", menorAlt);


    printf("Numero total de homens: %d\n", qtdH);

    return 0;
}
