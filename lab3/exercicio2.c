#include <stdio.h>

int main(){

    int num;

    scanf("%d", &num);


    while(num <= 1000 && num >= 0){

        if(num == 0){
            printf("0\n");
        } else if(num == 1){
            printf("1\n");
        } else {

            long long fibonacci[num];

            fibonacci[0] = 0;
            fibonacci[1] = 1;

            for(int i = 2; i <= num; i++){
                fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
            }

            printf("%lld\n", fibonacci[num]);

        }

        scanf("%d", &num);

    }

    return 0;
}