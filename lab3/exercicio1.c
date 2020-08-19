#include <stdio.h>

int main(){

    int num1, num2;

    scanf("%d %d", &num1, &num2);

    for(int i = num1; i <= num2; i++){
        int qtdDivisores = 0;
        for(int j = 1; j <= i; j++){
            if(i % j == 0){
                qtdDivisores++;
            }
            if(qtdDivisores > 2){
                break;
            }
            if(qtdDivisores == 2 && i == j){
                printf("%d\n", i);
            }
        }
    }

    return 0;
}