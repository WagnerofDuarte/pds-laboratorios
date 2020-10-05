#include <stdio.h>
#include <string.h>

void primos(int m){

    int menorPrimo;
    int maiorPrimo = m;

    for(int i = 1; i < m; i++){
        int qtdDvisores = 0;
        for(int j = 1; j <= i; j++){
            if(i % j == 0){
                qtdDvisores++;
            }
            if(qtdDvisores == 2 && j == i){
                menorPrimo = i;
            }
        }
    }

    int achou = 0;
    int i = 0;

    while(achou == 0){
        
        maiorPrimo++;

        int qtdDvisores = 0;
        for(int j = 1; j <= maiorPrimo; j++){
            if(maiorPrimo % j == 0){
                qtdDvisores++;
            }
            if(qtdDvisores == 2 && j == maiorPrimo){
                maiorPrimo = j;
                achou = 1;
            }
        }
    }

    printf("%d\n", menorPrimo);
    printf("%d", maiorPrimo);
}

int main(){

    int n;

    scanf("%d", &n);

    primos(n);

    return 0;
}