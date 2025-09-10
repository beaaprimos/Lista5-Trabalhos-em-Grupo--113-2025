#include<stdio.h>
#include<ctype.h>

int main(){
    char in[8];//inclui os 7 caracteres + o nulo '\0'
    char out[10];// saída formatada
    int i=0, j=0; // i = leitura, k = escrita
    int sep = 0;// separador já inserido (0 = não, 1 = sim)

    
    printf("Escreva um número real de até 7 dígitos:\n");
   
    while (i < 7) {
        char c = getchar();

        // ENTER encerra a leitura
        if (c == '\n') break;

        // Aceita apenas dígitos, ponto ou vírgula
        if (isdigit(c)) {
            out[j++] = c;
        } else if ((c == '.' || c == ',') && !sep) {
            out[j++] = ','; // substitui ponto por vírgula
          sep = 1;
        }
        // ignora qualquer outro caractere
        i++;
    }

    out[j] = '\0'; 
    printf("Número formatado: %s\n", out);
    return 0;
}
