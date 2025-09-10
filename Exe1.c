#include<stdio.h>
#include<string.h>
int main(){
   char x[5];
   char y[5], z[5];// 4 dígitos + caractere nulo '\0'

    printf("Digite um número de 4 dígitos: ");
    scanf("%4s", x);
    
    // Rotação à esquerda: x2 x3 x4 x1
    y[0]=x[1];
    y[1]=x[2];
    y[2]=x[3];
    y[3]=x[0];
    y[4]='\0';
    
    // Rotação à direita: x4 x1 x2 x3
    z[0]=x[3];
    z[1]=x[0];
    z[2]=x[1];
    z[3]=x[2];
    z[4]='\0';
    
    printf("Rotação à esquerda: %s\n", y);
    printf("Rotação à direita: %s\n", z);
    
    return 0;
    
	}
