#include <stdio.h>

int main(){

    int vetor1[10];
    int vetor2[10];

    for(int i = 0; i < 10; i++){
        scanf("%d", &vetor1[i]);
        printf("\n");
    }

    int p1 = 0, p2 = 9;

    while(p1 < 10){
        vetor2[p1] = vetor1[p2];
        p1++;
        p2--;
    }

    for(int i = 0; i < 10; i++){
        printf("%d\n", vetor2[i]);
    }

    return 0;
}