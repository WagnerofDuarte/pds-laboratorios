#include <stdio.h>
#include <string.h>

int main(){

    struct Person {
        char nome[50];
        int idade;
        float salario;    
    };

    struct Person p[4];

    int qtdResgistros = 0;
    char busca[50];

    while(qtdResgistros != 4){

        char comando[10];

        scanf("%s", comando);
        if(strcmp("inserir", comando) == 0){

            if(qtdResgistros < 4){
                scanf("%s %d %f", p[qtdResgistros].nome, &p[qtdResgistros].idade, &p[qtdResgistros].salario);
                printf("Registro %s %d %.2f inserido\n", p[qtdResgistros].nome, p[qtdResgistros].idade, p[qtdResgistros].salario);
                qtdResgistros++;
            } else {
                printf("Espaco insuficiente\n");
            }
            
        } else if(strcmp("mostrar", comando) == 0){

            scanf("%s", busca);

            for(int i = 0; i <= qtdResgistros; i++){

                if(strcmp(p[i].nome, busca) == 0){
                    printf("Registro %s %d %.2f\n", p[i].nome, p[i].idade, p[i].salario);
                    break;

                } else if(strcmp(p[i].nome, busca) != 0 && i == qtdResgistros){
                    printf("Registro ausente\n");
                }
            }
        }
    }

    return 0;
}