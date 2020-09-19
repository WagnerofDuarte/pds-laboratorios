#include <stdio.h>
#include <string.h>

int primo(int numOficial){

    int multiplos = 1;
    int num = numOficial;

    for(int i = 2; i <= num; i++){
        if(num % i == 0){
            multiplos++;
        }
    }

    if(multiplos == 2){

        return num;

    } else {

        return 0;

    }
}

int soma_Primos(int num, int somaOficial){

    int soma;

    soma = somaOficial + num;

    return soma;

}

int main(){

    int num;
    int soma = 0;
    int ultimoPrimo = 0;

    scanf("%d", &num);

    /*for(int i = 2; i <= num; i++){
        if(primo(i) != 0){
            soma = soma_Primos(i, soma);
        }
    }*/

    int i = 1;

    while(i <= num){
        
    }

    printf("%d", soma);

    return 0;
}