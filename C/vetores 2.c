/*Faça um programa que tenha no máximo 5 variáveis , 
que peça para o usuário digitar 1000 números e depois imprima uma tabela contendo a quantidade de números que terminam em 0, 1, 2, ..., 9.*/

#include <stdio.h>

#define TAMANHO 1000

int main() {
    int numeros[TAMANHO], contagem[10] = {0}, i, resto;
    
    printf("Digite %d números:\n", TAMANHO);
    for (i = 0; i < TAMANHO; i++) {
        scanf("%d", &numeros[i]);
        resto = numeros[i] % 10;
        contagem[resto]++;
    }
    
    printf("\nQuantidade de números por dígito final:\n");
    for (i = 0; i < 10; i++) {
        printf("Dígito %d: %d vezes\n", i, contagem[i]);
    }
    
    return 0;
}
