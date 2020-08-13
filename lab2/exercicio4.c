#include <stdio.h>

int main(){

    int num, m2 = 0, m3 = 0, m5 = 0, mt = 0;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    int i = num;

    while(i != 0){

        if(i % 2 == 0){
            m2++;
        }

        if(i % 3 == 0){
            m3++;
        }

        if(i % 5 == 0){
            m5++;
        }

        if(i % 2 == 0 && i % 3 == 0 && i % 5 == 0){
            mt++;
        }

        i--;
    }

    printf("Múltiplos de 2: %d\n", m2);
    printf("Múltiplos de 3: %d\n", m3);
    printf("Múltiplos de 5: %d\n", m5);
    printf("Múltiplos de todos: %d\n", mt);

    return 0;

}