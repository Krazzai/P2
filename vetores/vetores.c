#include<stdio.h>

int main(){
    int num = 2134579287;
    while(num != 0){
        printf("%d",num % 10);
        num /= 10;
    }
    printf("\n");
    return 0;
}