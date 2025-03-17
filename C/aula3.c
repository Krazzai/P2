    #include <stdio.h>

    int main(){
        float imposto,salario;
        printf("Digite o seu salário:\n");
        scanf("%f", &salario);
        
        if (salario <= 1500.00) {
            imposto = 0.0;
            printf("Você está isento de Imposto de Renda.\n");
        } 
        else if (salario <= 3000.00) {
            imposto = salario * 0.10;
            printf("Seu imposto de Renda é de 10%%: %.2f\n", imposto);
        } 
        else if (salario <= 5000.00) {
            imposto = salario * 0.15;
            printf("Seu imposto de Renda é de 15%%: %.2f\n", imposto);
        } 
        else {
            imposto = salario * 0.20;
            printf("Seu imposto de Renda é de 20%%: %.2f\n", imposto);
        }
        return 0;
        
    }   