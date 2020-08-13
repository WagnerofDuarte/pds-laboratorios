#include <stdio.h>
#include <math.h>

int main(){

    double margem;
    double num = 4.0;
    double razao = 3.0;
    int somaOuSub = 1;
    int iteracoes = 1;

    printf("Digite uma margem de erro: ");
    scanf("%lf", &margem);

    while(fabs(M_PI - num) >= margem){
        if(somaOuSub == 0){
            //soma
            num = num + (4.0/razao);
            somaOuSub = 1;
        } else {
            //subtracao
            num = num - (4.0/razao);
            somaOuSub = 0;
        }
        razao = razao + 2.0;
        iteracoes++;
    }

    printf("%d", iteracoes);

    return 0;
}