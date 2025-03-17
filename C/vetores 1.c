/*Faça um programa (modularizado) para solicitar que um usuário preencha um vetor de tamanho 100 e depois imprima:
a)o somatório de todos os valores pares do vetor;
b)o produtório de todos os valores ímpares do vetor e
c)o menor valor do vetor.*/

#include <stdio.h>

#define TAMANHO 100

void preencherVetor(int vetor[]);
int somatorioPares(int vetor[]);
long long produtorioImpares(int vetor[]);
int menorValor(int vetor[]);

int main() {
    int vetor[TAMANHO];
    
    preencherVetor(vetor);
    
    printf("Somatório dos valores pares: %d\n", somatorioPares(vetor));
    printf("Produtório dos valores ímpares: %lld\n", produtorioImpares(vetor));
    printf("Menor valor do vetor: %d\n", menorValor(vetor));
    
    return 0;
}

void preencherVetor(int vetor[]) {
    printf("Preencha o vetor com %d valores:\n", TAMANHO);
    for (int i = 0; i < TAMANHO; i++) {
        scanf("%d", &vetor[i]);
    }
}

int somatorioPares(int vetor[]) {
    int soma = 0;
    for (int i = 0; i < TAMANHO; i++) {
        if (vetor[i] % 2 == 0) {
            soma += vetor[i];
        }
    }
    return soma;
}

long long produtorioImpares(int vetor[]) {
    long long produto = 1;
    int temImpar = 0;
    for (int i = 0; i < TAMANHO; i++) {
        if (vetor[i] % 2 != 0) {
            produto *= vetor[i];
            temImpar = 1;
        }
    }
    return temImpar ? produto : 0;
}

int menorValor(int vetor[]) {
    int menor = vetor[0];
    for (int i = 1; i < TAMANHO; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }
    return menor;
}
