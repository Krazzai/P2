#include <stdio.h>

#define TAM 500
typedef struct{
    char nome[TAM];
    int idade;
    char endereco[TAM];
} Estrutura;

int main(){
    Estrutura estrutura;

    getchar();

    printf("Qual seu nome?\n");

    fgets(estrutura.nome, TAM, stdin);

    printf("Qual a sua idade?\n");
    scanf("%d",&estrutura.idade);

    getchar();

    printf("Qual seu endereço?\n");
    fgets(estrutura.endereco, TAM, stdin);

    printf("\n seu nome é %s, sua idade é %d, e seu endereço é %s",estrutura.nome,estrutura.idade,estrutura.endereco);

    return 0;



}