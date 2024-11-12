#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_VETOR 10000000
#define TEMPO_LIMITE 300000  // 5 minutos em milissegundos

// Função para gerar um vetor aleatório
void gerarVetorAleatorio(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 1000000; // valores aleatórios entre 0 e 999999
    }
}

// Função para gerar um vetor ordenado crescente
void gerarVetorCrescente(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i;
    }
}

// Função para gerar um vetor ordenado decrescente
void gerarVetorDecrescente(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - i;
    }
}

// Função de medição de tempo
long long tempoExecucao(void (funcao)(int, int), int *vetor, int tamanho) {
    clock_t inicio, fim;
    inicio = clock();
    funcao(vetor, tamanho);
    fim = clock();
    return ((fim - inicio) * 1000) / CLOCKS_PER_SEC;  // Retorna o tempo em milissegundos
}

// Função de ordenação Bubble Sort
void bubbleSort(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// Função de ordenação Insertion Sort
void insertionSort(int *vetor, int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

// Função de ordenação Selection Sort
void selectionSort(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            int temp = vetor[i];
            vetor[i] = vetor[minIdx];
            vetor[minIdx] = temp;
        }
    }
}

// Função para criar e medir o tempo de execução
void medirTempo(int vetor, int tamanho, void (*algoritmo)(int, int), const char *nomeAlgoritmo, FILE *arquivo) {
    long long tempo = tempoExecucao(algoritmo, vetor, tamanho);
    fprintf(arquivo, "%d,%lld,%s\n", tamanho, tempo, nomeAlgoritmo);
}

int main() {
    FILE *arquivo = fopen("resultados.csv", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return 1;
    }

    // Cabeçalho do arquivo CSV
    fprintf(arquivo, "Tamanho,Vetor Desordenado,Vetor Ordenado Crescente,Vetor Ordenado Decrescente\n");

    int tamanhos[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000};
    int numTamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
    
    for (int i = 0; i < numTamanhos; i++) {
        int tamanho = tamanhos[i];
        if (tamanho > MAX_VETOR) {
            tamanho = MAX_VETOR;
        }

        // Alocação dinâmica do vetor
        int *vetor = (int *)malloc(tamanho * sizeof(int));
        if (vetor == NULL) {
            printf("Falha na alocação de memória!\n");
            return 1;
        }

        // Vetor desordenado
        gerarVetorAleatorio(vetor, tamanho);
        medirTempo(vetor, tamanho, bubbleSort, "Bubble Sort Desordenado", arquivo);
        medirTempo(vetor, tamanho, insertionSort, "Insertion Sort Desordenado", arquivo);
        medirTempo(vetor, tamanho, selectionSort, "Selection Sort Desordenado", arquivo);

        // Vetor ordenado crescente
        gerarVetorCrescente(vetor, tamanho);
        medirTempo(vetor, tamanho, bubbleSort, "Bubble Sort Crescente", arquivo);
        medirTempo(vetor, tamanho, insertionSort, "Insertion Sort Crescente", arquivo);
        medirTempo(vetor, tamanho, selectionSort, "Selection Sort Crescente", arquivo);

        // Vetor ordenado decrescente
        gerarVetorDecrescente(vetor, tamanho);
        medirTempo(vetor, tamanho, bubbleSort, "Bubble Sort Decrescente", arquivo);
        medirTempo(vetor, tamanho, insertionSort, "Insertion Sort Decrescente", arquivo);
        medirTempo(vetor, tamanho, selectionSort, "Selection Sort Decrescente", arquivo);

        // Libera a memória
        free(vetor);
    }

    fclose(arquivo);
    printf("Dados gravados com sucesso no arquivo 'resultados.csv'\n");

    return 0;
}