#include <stdio.h>

int main(){

    int QTD;
    printf("Quantos testes deseja fazer?\n");
    scanf("%d", &QTD);

    if(QTD<=0){
        printf("Deve ser maior que zero!\n");
    }

    int i=0;

    int vetor[QTD];

    while(i<QTD){

        int valor;

        printf("Insira o %d valor:", i+1);
        scanf("%d", &valor);

        int j=i;

        while(j>0 && vetor [j-1] > valor){
            vetor[j] = vetor[j-1];

            j--;
        }  
        vetor[j]=valor;
        i++;

    }

    int k=0;

    while(k<QTD){

        printf("%d\n",vetor[k]);

        k++;
    }

    return 0;
}

