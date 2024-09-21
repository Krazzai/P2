#include <stdio.h>

/*Os numeros de 1 a 100 separado por virgula*/

void imprimir_numero1() {
    for (int i = 1; i <= 100; i++){
        if (i<=100){
           printf("%d\n",i); 
        }
        else {
            break;
        }
    }
}
/*O somatório de todos os números ímpares entre 10 e 1000*/

void imprimir_numero2(){
    int i=10,soma;
    while (i<=1000){
        
        if (i%2!=0){
            soma+=i;
        }
        i++;

        }
    printf("%d\n",soma);
    }

/*Todos os números múltiplos de 3 que não terminem em 3 entre 1 e 200 (separados por vírgula)*/

void multiplos (){
   int i=3;
   int p=1;

    while( i<200){
        if (i%10 != 3){
            if(p){
                printf("%d",i);
                p = 0;
            }
        else {
            printf(",%d",i);
        }
        }
        
        i+=3;
    }
}


int main(){
    imprimir_numero1();
    imprimir_numero2();
    multiplos();
    return 0;
}