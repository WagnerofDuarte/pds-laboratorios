#include <stdio.h>
#include <string.h>

int primo(int numOficial){

    int multiplos = 1;
    int num = numOficial;

    if(num < 2){
        return -1;
    }

    for(int i = 2; i <= num; i++){
        if(num % i == 0){
            multiplos++;
        }
    }

    if(multiplos == 2){

        return 1;

    } else {

        return 0;

    }
}

int main(){

    for(int i = 0; i < 8; i++){

        int num;

        scanf("%d", &num);
        printf("%d   ", primo(num));

    }

    return 0;
}