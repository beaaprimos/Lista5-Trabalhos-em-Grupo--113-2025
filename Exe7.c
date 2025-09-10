#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

typedef struct {
    char nome[50];
    int idade;
} Administrativo;

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar() {
    printf("\nPressione Enter para continuar...");
    getchar();
}

void lerString(char *str, int tamanho) {
    fgets(str, tamanho, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void mostrar(Administrativo adm[]) {
    printf("Lista de administrativos:\n");
    for (int i = 0; i < MAX; i++) {
        printf("%s - %d anos\n", adm[i].nome, adm[i].idade);
    }
}

void cadastrar(Administrativo adm[]) {
    limparTela();
    for (int i = 0; i < MAX; i++) {
        printf("Digite o nome do administrativo %d: ", i + 1);
        lerString(adm[i].nome, sizeof(adm[i].nome));
        printf("Digite a idade de %s: ", adm[i].nome);
        scanf("%d", &adm[i].idade);
        while (getchar() != '\n');
    }
    printf("Cadastro concluído.\n");
    pausar();
}

void classificar(Administrativo adm[]) {
    limparTela();
    int op;
    Administrativo x;

    printf("Classificar por:\n1 - Nome\n2 - Idade\nEscolha: ");
    scanf("%d", &op);
    while (getchar() != '\n');

    for (int i = 0; i < MAX - 1; i++) {
        for (int j = i + 1; j < MAX; j++) {
            if ((op == 1 && strcmp(adm[i].nome, adm[j].nome) > 0) ||
                (op == 2 && adm[i].idade > adm[j].idade)) {
                x = adm[i];
                adm[i] = adm[j];
                adm[j] = x;
            }
        }
    }

    printf("Administrativos classificados por %s:\n", op == 1 ? "nome" : "idade");
    mostrar(adm);
    pausar();
}

void corrigir(Administrativo adm[]) {
    limparTela();
    char nome[50];
    printf("Digite o nome do administrativo a corrigir: ");
    lerString(nome, sizeof(nome));
    for (int i = 0; i < MAX; i++) {
        if (strcmp(adm[i].nome, nome) == 0) {
            printf("Digite o novo nome: ");
            lerString(adm[i].nome, sizeof(adm[i].nome));
            printf("Digite a nova idade: ");
            scanf("%d", &adm[i].idade);
            while (getchar() != '\n');
            printf("Dados atualizados com sucesso.\n");
            pausar();
            return;
        }
    }
    printf("Administrativo não encontrado.\n");
    pausar();
}

void pesquisar(Administrativo adm[]) {
    limparTela();
    int op;
    printf("Pesquisar por:\n1 - Nome\n2 - Idade\nEscolha: ");
    scanf("%d", &op);
    while (getchar() != '\n');

    if (op == 1) {
        char nome[50];
        printf("Digite o nome: ");
        lerString(nome, sizeof(nome));
        for (int i = 0; i < MAX; i++) {
            if (strcmp(adm[i].nome, nome) == 0) {
                printf("Encontrado: %s, %d anos\n", adm[i].nome, adm[i].idade);
                pausar();
                return;
            }
        }
        printf("Nome não encontrado.\n");
    } else if (op == 2) {
        int idade, achou = 0;
        printf("Digite a idade: ");
        scanf("%d", &idade);
        while (getchar() != '\n');
        for (int i = 0; i < MAX; i++) {
            if (adm[i].idade == idade) {
                printf("Encontrado: %s, %d anos\n", adm[i].nome, adm[i].idade);
                achou = 1;
            }
        }
        if (!achou) {
            printf("Nenhum administrativo com essa idade.\n");
        }
    } else {
        printf("Opção inválida.\n");
    }
    pausar();
}

void listarAposentados(Administrativo adm[]) {
    limparTela();
    printf("Administrativos aposentados (>= 60 anos):\n");
    for (int i = 0; i < MAX; i++) {
        if (adm[i].idade >= 60) {
            printf("%s - %d anos\n", adm[i].nome, adm[i].idade);
        }
    }
    pausar();
}

void listarAtivos(Administrativo adm[]) {
    limparTela();
    printf("Administrativos ativos (< 60 anos):\n");
    for (int i = 0; i < MAX; i++) {
        if (adm[i].idade < 60) {
            printf("%s - %d anos\n", adm[i].nome, adm[i].idade);
        }
    }
    pausar();
}

int main() {
    Administrativo adm[MAX];
    int op;

    do {
        limparTela();
        printf("\nMenu:\n");
        printf("1 - Cadastrar administrativos\n");
        printf("2 - Classificar\n");
        printf("3 - Corrigir dados\n");
        printf("4 - Pesquisar\n");
        printf("5 - Listar aposentados\n");
        printf("6 - Listar ativos\n");
        printf("0 - Sair\nEscolha: ");
        scanf("%d", &op);
        while (getchar() != '\n');

        switch (op) {
            case 1: cadastrar(adm); break;
            case 2: classificar(adm); break;
            case 3: corrigir(adm); break;
            case 4: pesquisar(adm); break;
            case 5: listarAposentados(adm); break;
            case 6: listarAtivos(adm); break;
            case 0: printf("Encerrando programa.\n"); break;
            default: printf("Opção inválida.\n"); pausar();
        }
    } while (op != 0);

    return 0;
}

