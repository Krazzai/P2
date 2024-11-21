#include <stdio.h>
#include <string.h>

#define TAM 100
#define NUM_ALUNOS 5

typedef struct {
    int matricula;
    char nome[TAM];
    float nota1;
    float nota2;
    float nota3;
} Aluno;

float calcularMedia(Aluno aluno) {
    return (aluno.nota1 + aluno.nota2 + aluno.nota3) / 3.0;
}

int main() {
    Aluno alunos[NUM_ALUNOS];
    int indiceMaiorNota1 = 0;
    int indiceMaiorMedia = 0;
    int indiceMenorMedia = 0;

    // Entrada de dados
    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("Aluno %d:\n", i + 1);

        printf("Digite a matricula: ");
        scanf("%d", &alunos[i].matricula);
        getchar(); // Limpar o buffer de entrada

        printf("Digite o nome: ");
        fgets(alunos[i].nome, TAM, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0'; // Remover o '\n'

        printf("Digite a nota da primeira prova: ");
        scanf("%f", &alunos[i].nota1);

        printf("Digite a nota da segunda prova: ");
        scanf("%f", &alunos[i].nota2);

        printf("Digite a nota da terceira prova: ");
        scanf("%f", &alunos[i].nota3);

        getchar(); // Limpar o buffer antes do próximo aluno
        printf("\n");
    }

    // Identificar o aluno com maior nota na primeira prova
    for (int i = 1; i < NUM_ALUNOS; i++) {
        if (alunos[i].nota1 > alunos[indiceMaiorNota1].nota1) {
            indiceMaiorNota1 = i;
        }
    }

    // Identificar os alunos com maior e menor média geral
    float maiorMedia = calcularMedia(alunos[0]);
    float menorMedia = calcularMedia(alunos[0]);

    for (int i = 1; i < NUM_ALUNOS; i++) {
        float mediaAtual = calcularMedia(alunos[i]);
        if (mediaAtual > maiorMedia) {
            maiorMedia = mediaAtual;
            indiceMaiorMedia = i;
        }
        if (mediaAtual < menorMedia) {
            menorMedia = mediaAtual;
            indiceMenorMedia = i;
        }
    }

    // Saída de resultados
    printf("Aluno com maior nota na primeira prova:\n");
    printf("Nome: %s\nMatricula: %d\nNota 1: %.2f\n\n", 
        alunos[indiceMaiorNota1].nome, 
        alunos[indiceMaiorNota1].matricula, 
        alunos[indiceMaiorNota1].nota1);

    printf("Aluno com maior media geral:\n");
    printf("Nome: %s\nMatricula: %d\nMedia: %.2f\n\n", 
        alunos[indiceMaiorMedia].nome, 
        alunos[indiceMaiorMedia].matricula, 
        maiorMedia);

    printf("Aluno com menor media geral:\n");
    printf("Nome: %s\nMatricula: %d\nMedia: %.2f\n\n", 
        alunos[indiceMenorMedia].nome, 
        alunos[indiceMenorMedia].matricula, 
        menorMedia);

    printf("Situacao dos alunos:\n");
    for (int i = 0; i < NUM_ALUNOS; i++) {
        float media = calcularMedia(alunos[i]);
        printf("Nome: %s - Media: %.2f - %s\n", 
            alunos[i].nome, 
            media, 
            (media >= 6.0) ? "Aprovado" : "Reprovado");
    }

    return 0;
}
