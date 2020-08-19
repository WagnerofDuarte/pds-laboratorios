#include <stdio.h>

int main(){

    int linhas, colunas;

    scanf("%d %d", &linhas, &colunas);

    int matriz[linhas][colunas];

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            scanf("%d", &matriz[i][j]);
        }
        printf("\n");
    }

    int matrizOposta[linhas][colunas];

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            matrizOposta[i][j] = (matriz[i][j] * (-1));
        }
    }

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%d ", matrizOposta[i][j]);
        }
        printf("\n");
    }

    return 0;
}