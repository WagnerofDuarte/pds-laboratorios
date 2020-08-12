#include <stdio.h>

int main(){

    int x, y, z;

    printf("Digite tres numeros: ");
    scanf("%d %d %d", &x, &y, &z);

    if(x % y == 0 && x % z == 0){
        printf("O número é divisível");
    } else {
        printf("O número não é divisível");
    }

    return 0;
}