#include <stdio.h>

void menu(){ 
    printf("Menu: \n");
    printf("1.Imprima todo o vetor.\n");
    printf("2.Consultar\n");
    printf("3.Remover elemento\n");
    printf("4.Inserir\n");
}


int main(){

    int t;
    printf("Digite o tamanho do vetor: ");
    scanf("%d",&t);

    int vetor[t];

    

    //tamanho do vetor.

    for (int i=0; i<t; i++){
        printf("Digite o valor da posição %d:", i+1);
        int valor;
        scanf("%d",&valor);
        
        int j=i;
       
        //inserção ordenada.
        while (j>0 && vetor[j-1]>valor){
            vetor[j] = vetor [j-1];
            j--;
        }
        
        vetor[j]=valor;

    }

    //inserindo opção
    
    menu();
    int opcao;
    scanf("%d",&opcao);
    
    if(opcao==1){
        for(int i=0;i<t;i++){
            printf("vetor[%d]=%d\n",i,vetor[i]);
        }
    }

    if(opcao==2){
        
    }

}