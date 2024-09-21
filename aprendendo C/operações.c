#include <stdio.h>

int main(){
    int a,b,soma,sub,mult,div,rest;

    scanf("%d",&a);
    scanf("%d",&b);

    soma = a+b;
    sub = a-b;
    mult = a*b;
    div = a/b;
    rest = a%b;

    printf("Soma: %d\n", soma);
    printf("Sub: %d\n", sub);
    printf("Mult: %d\n", mult);
    printf("Div: %d\n", div);
    printf("Resto da div: %d\n",rest);

    return 0;

}