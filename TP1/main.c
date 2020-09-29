#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    int qtdJogos;
    int tamanhoTabuleiro;
    int numJogadas;
    int posicao[2] = {0, 0};
    int qtdBombas;

    scanf("%d", &qtdJogos);

    while(qtdJogos != 0){

        qtdBombas = 0;

        scanf("%d", &tamanhoTabuleiro);
        char tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro];
        char tabuleiroDeChecagem[tamanhoTabuleiro][tamanhoTabuleiro];

        for(int i = 0; i < tamanhoTabuleiro; i++){
            for(int j = 0; j < tamanhoTabuleiro; j++){
                scanf(" %c", &tabuleiro[i][j]);
                if(tabuleiro[i][j] == 'b'){
                    tabuleiroDeChecagem[i][j] = tabuleiro[i][j];
                    qtdBombas ++;
                } else {
                    tabuleiroDeChecagem[i][j] = '-';
                }
            }
        }

        //---------------------------------

        scanf("%d", &numJogadas);

        //---------------------------------

        while(numJogadas != 0){

            int posicaoEscolhida[2];
            int contagemDeRevelados = 0;

            scanf("%d%d", &posicaoEscolhida[0], &posicaoEscolhida[1]);

            if(tabuleiro[posicaoEscolhida[0]][posicaoEscolhida[1]] == 'b'){
                printf("PERDEU\n");
                break;
            } else {

                tabuleiroDeChecagem[posicaoEscolhida[0]][posicaoEscolhida[1]] = 'x';
                
                for(int i = -1; i < 2; i++){
                    for(int j = -1; j < 2; j++){
                        if(posicaoEscolhida[0] + i >= 0 && posicaoEscolhida[0] + i < tamanhoTabuleiro && posicaoEscolhida[1] + j >= 0 && posicaoEscolhida[1] + j < tamanhoTabuleiro){
                            if(tabuleiroDeChecagem[posicaoEscolhida[0] + i][posicaoEscolhida[1] + j] != 'b'){
                                tabuleiroDeChecagem[posicaoEscolhida[0] + i][posicaoEscolhida[1] + j] = 'x';
                            }
                        }
                    }
                } 
            }

            /*for(int i = 0; i < tamanhoTabuleiro; i++){
                for(int j = 0; j < tamanhoTabuleiro; j++){
                    printf(" %c", tabuleiroDeChecagem[i][j]);
                }
                printf("\n");
            }*/

            if(numJogadas == 1){
                for(int i = 0; i < tamanhoTabuleiro; i++){
                    for(int j = 0; j < tamanhoTabuleiro; j++){
                        if(tabuleiroDeChecagem[i][j] == 'x'){
                            contagemDeRevelados++;
                        }
                    }
                }
            }

            if(contagemDeRevelados == (tamanhoTabuleiro*tamanhoTabuleiro) - qtdBombas){
                printf("GANHOU\n");
                break;
            }

            numJogadas--;

            if(contagemDeRevelados < (tamanhoTabuleiro*tamanhoTabuleiro) - qtdBombas && numJogadas == 0){
                printf("FALTOU TERMINAR\n");
                break;
            }
        }
        qtdJogos--;
    }

    return 0;
}