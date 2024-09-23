#include <stdio.h>

int impares(int l, int c, int matriz[l][c]){
    int contagem=0;

    for(int i=0;i<l;i++){
        for(int j=0;j<c;j++){
           if(matriz[l][c]%2!=0){
            contagem++;
           }
        }
    }
    return contagem;
}

int busca(int l, int c, int matriz[l][c],int numero){
    int encontrado=0;

    for(int i=0;i<l;i++){
        for(int j=0;j<c;j++){
            if(matriz[l][c]==numero){
                printf("Numero %d procurado foi encontrado da colunda %d, linha %d", numero,l,c);
                encontrado=1;
                break;
            }
        }
    }
    if(! encontrado){
        printf("Numero não encontrado :(");
    }
}

int somatorio(int l, int c, int matriz[l][c]){
    int soma=0;

    for(int i=0;i<l;i++){
        for(int j=0;j<c;j++){
            soma+=matriz[i][j];
        }
    }
    return soma;
}

float media_elementos(int l, int c, int soma){
    int elementos;
    int elementos= l*c;
    float media= soma/elementos;
    return media;

}

float media_linha(int l, int c, int matriz[l][c]){
    int elementos_linha;
    for(int i=0;i<l;i++ ){
        int s;
        for(int j=0;j<c;j++){
            s+=matriz[i][j];
        }
        float media_linha= (float) s/c;
        printf("Media da linha %d: %2.f\n",i,media_linha);
    }


}


int main(){
    int l,c,numero;
    printf("Digite o número de linhas: ");
    scanf("%d", &l);
    printf("Digite o número de colunas: ");
    scanf("%d", &c);

    int matriz[l][c];

    printf("Digite os elementos da matriz:");
    for(int i=0;i<l;i++){
        for(int j=0;i<c;j++){
            scanf("%d",matriz[i][j]);

        }
    }
//Quantidade de impares
    int imp= impares(l,c,matriz);
    printf("Quantidade de numeros impares na matriz: %d\n",imp);
//Busca de numeros
    printf("Digite o numero que deseja buscar:");
    scanf("%d",&numero);
    busca(l,c,matriz,numero);
//Somatorio dos elementos
int som = somatorio(l,c,matriz);
printf("Somatorio dos elementos da matriz: %d\n");
//Media de todos os numeros
float med= media_elementos(l,c,som);
printf("A media dia dos elementos da matriz é: %2.f\n",med);
//Media de cada linha
media_linha(l,c,matriz);


}