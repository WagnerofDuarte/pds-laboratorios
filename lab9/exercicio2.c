#include <stdio.h>
#include <string.h>

int main(){

    int tamanhoVetor;

    scanf("%d", &tamanhoVetor);

    int vetor[tamanhoVetor];

    for(int i = 0; i < tamanhoVetor; i++){
        scanf("%d", &vetor[i]);
    }

    int multiplicador;

    scanf("%d", &multiplicador);

    for(int i = 0; i < tamanhoVetor; i++){
        printf("%d ", vetor[i]);
    }

    printf("\n");

    for(int i = 0; i < tamanhoVetor; i++){
        vetor[i] = vetor[i]*multiplicador;
        printf("%d ", vetor[i]);
    }

    printf("\n");

    for(int i = 0; i < tamanhoVetor; i++){
        vetor[i] = vetor[i]/multiplicador;
        printf("%d ", vetor[i]);
    }

    return 0;
}