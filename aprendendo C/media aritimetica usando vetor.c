#include <stdio.h>

/*Fazer a media aritmetica de 3 valores
ultilizando vetor.*/

int main(){
    int v[3];

    v[0]=0;
    v[1]=2;
    v[2]=3;
    v[3]=10;
    v[4]=90;

    printf("Primeiro valor:");
    scanf("%f", &v[0]);
    
    printf("Seguno valor:");
    scanf("%f",&v[1]);
    
    printf("Terceiro valor:");
    scanf("%f",&v[2]);
    
    printf("Valores implantados: %f, %f, %f", v[0],v[1],v[2]);

    return 0;
}