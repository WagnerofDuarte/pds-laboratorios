#include <stdio.h>

int main(){

    int x = 233;

    do{

        if(x >= 300 && x <= 400){
            x = x + 3;
        } else {
            x = x + 5;
        }

        printf("%d\n", x);

    }while(x < 457);

    return 0;
}