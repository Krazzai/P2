#include <stdio.h>

#define TAM 500

typedef struct{
    char nome [TAM];
    int matricula;
    char curso[TAM];
} Aluno;



int main(){

    Aluno alunos[5];

    for (int i=0; i<5; i++){
        printf("Qual o nome de aluno?\n");
        
        fgets(alunos[i].nome, TAM, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        printf("Qual a matricula?\n");
        scanf("%d",&alunos[i].matricula);
    
        getchar();

        printf("Qual o curso?\n");
        fgets(alunos[i].curso, TAM, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';
    }
    for (int i=0; i<5;i++){
        
        printf("Nome: %s\nMatricula: %d\nCurso: %s\n",alunos[i].nome,alunos[i].matricula,alunos[i].curso);

    }
    
    return 0;
}


    
