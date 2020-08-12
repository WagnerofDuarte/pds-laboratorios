#include <stdio.h>

int main(){

   int nota;
   int n100 = 0, n50 = 0, n20 = 0, n10 = 0, n5 = 0, n2 = 0, n1 = 0;

   printf("Digite um valor em reais (R$): ");
   scanf("%d", &nota);

    while(nota != 0){

        if(nota >= 100){

            n100 = n100 + 1;
            nota = nota - 100;

        } else if(nota >= 50){

            n50 = n50 + 1;
            nota = nota - 50;
        } else if(nota >= 20){
            
            n20 = n20 + 1;
            nota = nota - 20;
        } else if(nota >= 10){
            
            n10 = n10 + 1;
            nota = nota - 10;
        } else if(nota >= 5){
            
            n5 = n5 + 1;
            nota = nota - 5;
        } else if(nota >= 2){
            
            n2 = n2 + 1;
            nota = nota - 2;
        } else {

            n1 = n1 + 1;
            nota = nota - 1;
        }
    }

    printf("100: %d\n", n100);
    printf("50: %d\n", n50);
    printf("20: %d\n", n20);
    printf("10: %d\n", n10);
    printf("5: %d\n", n5);
    printf("2: %d\n", n2);
    printf("1: %d\n", n1);

    return 0;
}