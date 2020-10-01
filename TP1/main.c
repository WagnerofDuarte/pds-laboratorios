#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    int qtdJogos;
    int tamanhoTabuleiro;
    int numJogadas;
    int qtdBombas;

    scanf(" %d", &qtdJogos);

    while(qtdJogos != 0){

        qtdBombas = 0;

        scanf(" %d", &tamanhoTabuleiro);
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

        scanf(" %d", &numJogadas);

        //---------------------------------

        int resultadoFinal = 1;

        while(numJogadas != 0){

            int posicaoEscolhida[2];
            int contagemDeRevelados = 0;

            scanf(" %d %d", &posicaoEscolhida[0], &posicaoEscolhida[1]);

            if(tabuleiro[posicaoEscolhida[0]][posicaoEscolhida[1]] == 'b'){
                resultadoFinal = 0;
            } else {
                tabuleiroDeChecagem[posicaoEscolhida[0]][posicaoEscolhida[1]] = 'x';
            }

            int podeRevelar = 1;

            for(int i = -1; i < 2; i++){
                for(int j = -1; j < 2; j++){
                    if(posicaoEscolhida[0] + i >= 0 && posicaoEscolhida[0] + i < tamanhoTabuleiro && posicaoEscolhida[1] + j >= 0 && posicaoEscolhida[1] + j < tamanhoTabuleiro){
                        if(tabuleiroDeChecagem[posicaoEscolhida[0] + i][posicaoEscolhida[1] + j] == 'b'){
                            podeRevelar = 0;
                        }
                    }
                }
            }
                
            for(int i = -1; i < 2; i++){
                for(int j = -1; j < 2; j++){
                    if(posicaoEscolhida[0] + i >= 0 && posicaoEscolhida[0] + i < tamanhoTabuleiro && posicaoEscolhida[1] + j >= 0 && posicaoEscolhida[1] + j < tamanhoTabuleiro && podeRevelar == 1){
                        tabuleiroDeChecagem[posicaoEscolhida[0] + i][posicaoEscolhida[1] + j] = 'x';
                    }
                }
            } 

            numJogadas--;

            if(numJogadas == 0){
                for(int i = 0; i < tamanhoTabuleiro; i++){
                    for(int j = 0; j < tamanhoTabuleiro; j++){
                        if(tabuleiroDeChecagem[i][j] == 'x'){
                            contagemDeRevelados++;
                        }
                    }
                }
            }

            if(contagemDeRevelados == (tamanhoTabuleiro*tamanhoTabuleiro) - qtdBombas && resultadoFinal == 1 && numJogadas == 0){
                printf("GANHOU\n");
            } else if(contagemDeRevelados < (tamanhoTabuleiro*tamanhoTabuleiro) - qtdBombas && resultadoFinal == 1 && numJogadas == 0){
                printf("FALTOU TERMINAR\n");
            } else if(resultadoFinal == 0 && numJogadas == 0){
                printf("PERDEU\n");
            }
        }
        qtdJogos--;
    }

    return 0;
}