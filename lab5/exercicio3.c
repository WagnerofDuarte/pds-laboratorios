#include <stdio.h>
#include <string.h>

int main(){

    struct Produto{
        char nome[50];
        char marca[50];
        float preco;
    };

    struct Produto produtos[8];
    int produtosAdicionados = 0;
    int marcadorMarcas = 0;
    char marcas[8][50];
    int qtdMarcas[8] = { 0 };
    float precoMarca[8] = { 0.00 };

    for(int i = 0; i < 8; i++){
        scanf("%s %s %f", produtos[i].nome, produtos[i].marca, &produtos[i].preco);
        produtosAdicionados++;
        for(int j = 0; j <= produtosAdicionados; j++){
            if(strcmp(marcas[j], produtos[i].marca) == 0){
                break;
            } else if(j == produtosAdicionados){
                strcpy(marcas[marcadorMarcas], produtos[i].marca);
                marcadorMarcas++;
            }
        }
    }

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(strcmp(produtos[j].marca, marcas[i]) == 0){
                qtdMarcas[i]++;
                precoMarca[i] += produtos[j].preco;
                //adicionar 1 a quantidade da marca
                //adicionar 1 ao preco total da marca
            }
        }
    }

    for(int i = 0; i < marcadorMarcas; i++){
        printf("%s %s\n", marcas[i], qtdMarcas[i]);
    }

    float precoTotal = 0;

    for(int i = 0; i < 8; i++){
        precoTotal += produtos[i].preco;
    }

    printf("media total %.2f\n", (precoTotal/8));

    for(int i = 0; i < marcadorMarcas; i++){
        printf("media %s %.2f\n", marcas[i], (precoMarca[i] / qtdMarcas[i]));
    }

    return 0;
}