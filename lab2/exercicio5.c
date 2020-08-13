#include <stdio.h>

int main(){

    int num, resultado = 0;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    for(int i = 1; i <= num; i++){

        resultado = resultado + i;
    }

    printf("%d", resultado);

    return 0;
}