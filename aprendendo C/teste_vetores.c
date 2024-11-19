#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funções de ordenação

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Função para medir o tempo de execução
long long measureTime(void (*sortFunc)(int[], int), int arr[], int n) {
    clock_t start = clock();
    sortFunc(arr, n);
    clock_t end = clock();
    return ((long long)(end - start)) * 1000 / CLOCKS_PER_SEC;  // Tempo em milissegundos
}

// Função para gerar um vetor de números aleatórios
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (n * 2);  // Gerando números aleatórios até o dobro do tamanho
    }
}

// Função para gerar um vetor ordenado em ordem crescente
void generateSortedArrayAsc(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

// Função para gerar um vetor ordenado em ordem decrescente
void generateSortedArrayDesc(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i - 1;
    }
}

// Função principal para rodar os testes
void runTests() {
    const long long maxTime = 5 * 60 * 1000;  // 5 minutos em milissegundos
    int size = 10000;  // Tamanho inicial do vetor

    while (1) {
        printf("Rodando os testes com tamanho de vetor: %d\n", size);

        // Cenário 1: Vetor desordenado
        int arrUnsorted[size];
        generateRandomArray(arrUnsorted, size);

        long long timeBubbleUnsorted = measureTime(bubbleSort, arrUnsorted, size);
        long long timeInsertionUnsorted = measureTime(insertionSort, arrUnsorted, size);
        long long timeSelectionUnsorted = measureTime(selectionSort, arrUnsorted, size);

        // Cenário 2: Vetor ordenado (crescente)
        int arrSortedAsc[size];
        generateSortedArrayAsc(arrSortedAsc, size);

        long long timeBubbleAsc = measureTime(bubbleSort, arrSortedAsc, size);
        long long timeInsertionAsc = measureTime(insertionSort, arrSortedAsc, size);
        long long timeSelectionAsc = measureTime(selectionSort, arrSortedAsc, size);

        // Cenário 3: Vetor ordenado (decrescente)
        int arrSortedDesc[size];
        generateSortedArrayDesc(arrSortedDesc, size);

        long long timeBubbleDesc = measureTime(bubbleSort, arrSortedDesc, size);
        long long timeInsertionDesc = measureTime(insertionSort, arrSortedDesc, size);
        long long timeSelectionDesc = measureTime(selectionSort, arrSortedDesc, size);

        // Exibindo os resultados
        printf("BubbleSort (Desordenado): %lld ms\n", timeBubbleUnsorted);
        printf("InsertionSort (Desordenado): %lld ms\n", timeInsertionUnsorted);
        printf("SelectionSort (Desordenado): %lld ms\n", timeSelectionUnsorted);

        printf("BubbleSort (Ordenado Crescente): %lld ms\n", timeBubbleAsc);
        printf("InsertionSort (Ordenado Crescente): %lld ms\n", timeInsertionAsc);
        printf("SelectionSort (Ordenado Crescente): %lld ms\n", timeSelectionAsc);

        printf("BubbleSort (Ordenado Decrescente): %lld ms\n", timeBubbleDesc);
        printf("InsertionSort (Ordenado Decrescente): %lld ms\n", timeInsertionDesc);
        printf("SelectionSort (Ordenado Decrescente): %lld ms\n", timeSelectionDesc);

        // Verificando se algum tempo de execução ultrapassou 5 minutos
        if (timeBubbleUnsorted > maxTime || timeInsertionUnsorted > maxTime || timeSelectionUnsorted > maxTime ||
            timeBubbleAsc > maxTime || timeInsertionAsc > maxTime || timeSelectionAsc > maxTime ||
            timeBubbleDesc > maxTime || timeInsertionDesc > maxTime || timeSelectionDesc > maxTime) {
            printf("Tempo de execução excedeu o limite de 5 minutos. Reduzindo o tamanho do vetor pela metade.\n");
            size /= 2;
        } else {
            printf("Todos os testes concluídos dentro do tempo limite.\n");
            break;
        }
    }
}

int main() {
    srand(time(NULL));  // Inicializa o gerador de números aleatórios
    runTests();  // Executa os testes
    return 0;
}
