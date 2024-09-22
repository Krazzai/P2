#include <stdio.h>

int main(){
    int N;
    int menor= 1000;
    scanf("%d",&N);
    int posicao= 0;
    int X[N];

    for(int i=0;i<N;i++){

        scanf("%d",&X[i]);
    }
    
    for(int i=0;i<N;i++){
        if(X[i]<menor){
            menor=X[i];
            posicao=i;  
        }

    }
    printf("Menor valor: %d\n",menor);
    printf("Posição: %d\n",posicao);


    
    

}