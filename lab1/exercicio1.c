#include <stdio.h>

int main(){

    float celsius, fahrenheit;

    celsius = 1;

    printf("Digite uma temperatura em graus celsius: ");
    scanf("%f", &celsius);

    fahrenheit = ((1.8*celsius) + 32);

    printf("%.0f", fahrenheit);

    return 0;

}