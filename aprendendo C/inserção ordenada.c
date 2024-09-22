#include <stdio.h>

/*Faça um programa que peça para o usuário digitar QTD valores e insira num vetor de capacidade QTD. 
Você deve garantir que este vetor esta ordenado durante a digitação*/



int main() {
    int qtd;
    printf("Digite a quantidade de valores que deseja inserir: ");
    scanf("%d", &qtd);

    if (qtd <= 0) {
        printf("A quantidade deve ser maior que zero.\n");
        return 1;
    }

    int numeros[qtd];  // Declaração do vetor com capacidade QTD

    // Entrada de dados
    for (int i = 0; i < qtd; i++) {
        int valor;
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &valor);
        
        // Insere o valor no vetor em ordem
        int j = i;  // Usamos j para encontrar a posição correta
        while (j > 0 && numeros[j - 1] > valor) {
            numeros[j] = numeros[j - 1];  // Move os elementos para a direita
            j--;
        }
        numeros[j] = valor;  // Insere o novo valor na posição correta
    }

    // Exibe os valores ordenados
    printf("Valores em ordem crescente:\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}