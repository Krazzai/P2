#include <stdio.h>

#define TAM 200

typedef struct{
    int horas;
    int minutos;
    int segundos;
} Hora;

typedef struct{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct{
    Data data;
    Hora hora;
    char descricao[TAM];
} Compromisso;

int main(){
    
    Compromisso compromisso;
    
    printf("Que horas será seu compromisso?\n");
    printf("hora:");
    scanf("%d",&compromisso.hora.horas);
    printf("minutos:");
    scanf("%d",&compromisso.hora.minutos);
    printf("segundos:");
    scanf("%d",&compromisso.hora.segundos);

    printf("Qual a data do seu compromisso?\n");
    printf("dia:");
    scanf("%d",&compromisso.data.dia);
    printf("mês:");
    scanf("%d",&compromisso.data.mes);
    printf("ano:");
    scanf("%d",&compromisso.data.ano);
    
    getchar();

    printf("Qual será seu compromisso?\n");
    fgets(compromisso.descricao, TAM ,stdin);
    
    printf("\n a data que será seu %s é no dia %d/%d/%d às %d:%d:%d \n",compromisso.descricao, compromisso.data.dia, compromisso.data.mes, compromisso.data.ano,compromisso.hora.horas,compromisso.hora.minutos,compromisso.hora.segundos );

    return 0;
}



