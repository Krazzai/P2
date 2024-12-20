/*Feito por Luca Carazzai de Castro
  RA: 850847
*/
#include <stdio.h>
#include <stdlib.h>

#define M 10
#define N 15

void preencherMatriz(int m[][N], int lin, int col);
void imprimirMatriz(int m[][N], int lin, int col);
void maiorCadaColuna(int m[][N], int lin, int col, int v[]);
void imprimirVetor(int v[], int tam);
void indiceMaisRepetidos(int m[][N], int lin, int col);

int main() {
    int matriz[M][N];
    int vetor[N];
    int opcao;
    do {
        printf("\nMENU\n\n");
        printf("1 - preencher matriz com aleatorios\n");
        printf("2 - Maior cada coluna\n");
        printf("3 - Linha ou Coluna com mais repetidos\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            preencherMatriz(matriz, M, N);
            imprimirMatriz(matriz, M, N);
            break;
        case 2:
            maiorCadaColuna(matriz, M, N, vetor);
            imprimirVetor(vetor, N);
        case 3:
            indiceMaisRepetidos(matriz, M, N);
            break;
        default:
            break;
        }
    } while (opcao != 0);
    return 0;
}

void preencherMatriz(int m[][N], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            m[i][j] = rand() % 100 + 1;
        }
    }
}

void imprimirMatriz(int m[][N], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%3d ", m[i][j]);
        }
        printf("\n");
    }
}

void maiorCadaColuna(int m[][N], int lin, int col, int v[]) {
    for (int j = 0; j < col; ++j) {
        int maior = m[0][j];
        for (int i = 1; i < lin; ++i) {
            if (m[i][j] > maior) {
                maior = m[i][j];
            }
        }
        v[j] = maior;
    }
}

void imprimirVetor(int v[], int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void indiceMaisRepetidos(int m[][N], int lin, int col) {
    int maiorRepeticoes = 0;
    int indiceMaior = -1;
    int tipoIndice = 0;

     for (int i = 0; i < lin; ++i) {
        int repeticoesLinha = 0, repeticoesColuna = 0;
        int contagemLinha[101] = {0};
        int contagemColuna[101] = {0};

        for (int j = 0; j < col; ++j) {
            contagemLinha[m[i][j]]++;
            if (contagemLinha[m[i][j]] == 2) {
                repeticoesLinha++;
            }
        }

        if (repeticoesLinha > maiorRepeticoes) {
            maiorRepeticoes = repeticoesLinha;
            indiceMaior = i;
            tipoIndice = 0;
        }

        if (repeticoesColuna > maiorRepeticoes) {
            maiorRepeticoes = repeticoesColuna;
            indiceMaior = i;
            tipoIndice = 1;
        }
    }

    if (tipoIndice == 0) {
        printf("\nA linha com mais repetidos e a linha %d, com %d repeticoes.\n", indiceMaior, maiorRepeticoes);
    } 
    
    else {
        printf("\nA coluna com mais repetidos e a coluna %d, com %d repeticoes.\n", indiceMaior, maiorRepeticoes);
    }
}