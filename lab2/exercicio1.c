#include <stdio.h>

int main(){

    //Xn = 4*Xn-1 - 2*Xn-2

    int n, x0, x1;

    printf("Digite tres numeros inteiros: ");
    scanf("%d %d %d", &n, &x0, &x1);

    int seq[n+1];

    for(int i = 0; i <= n; i++){
        if(i == 0){
            seq[i] = x0;
        } else if(i == 1){
            seq[i] = x1;
        } else {
            seq[i] = (4*seq[i-1]) - (2*seq[i-2]);
        }
        printf("X%d: %d\n", i, seq[i]);
    }

    return 0;
}