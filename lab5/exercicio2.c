#include <stdio.h>
#include <string.h>

int main(){

    struct Endereco {
        char rua[50];
        int numero;
        char estado[50];
    };

    struct Person {
        char nome[50];
        int idade;
        float salario;
        struct Endereco end;    
    };

    struct Person p[4];

    int qtdResgistros = 0;
    char busca[50];

    while(qtdResgistros != 4){

        char comando[10];

        scanf("%s", comando);
        if(strcmp("inserir", comando) == 0){

            if(qtdResgistros < 4){
                scanf("%s %d %f %s %d %s", p[qtdResgistros].nome, &p[qtdResgistros].idade, &p[qtdResgistros].salario, p[qtdResgistros].end.rua, &p[qtdResgistros].end.numero, p[qtdResgistros].end.estado);
                printf("Registro %s %d %.2f %s %d %s inserido\n", p[qtdResgistros].nome, p[qtdResgistros].idade, p[qtdResgistros].salario, p[qtdResgistros].end.rua, p[qtdResgistros].end.numero, p[qtdResgistros].end.estado);
                qtdResgistros++;
            } else {
                printf("Espaco insuficiente\n");
            }
            
        } else if(strcmp("mostrar", comando) == 0){

            scanf("%s", busca);

            for(int i = 0; i <= qtdResgistros; i++){

                if(strcmp(p[i].nome, busca) == 0){
                    printf("Registro %s %d %.2f %s %d %s\n", p[i].nome, p[i].idade, p[i].salario, p[i].end.rua, p[i].end.numero, p[i].end.estado);
                    break;

                } else if(strcmp(p[i].nome, busca) != 0 && i == qtdResgistros){
                    printf("Registro ausente\n");
                }
            }
        } else if(strcmp("alterar", comando) == 0){
            struct Person t;
            
            scanf("%s %d %f %s %d %s", t.nome, &t.idade, &t.salario, t.end.rua, &t.end.numero, t.end.estado);

            for(int i = 0; i <= qtdResgistros; i++){

                if(strcmp(p[i].nome, t.nome) == 0){
                    p[i] = t;
                    printf("Registro %s %d %.2f %s %d %s alterado\n", p[i].nome, p[i].idade, p[i].salario, p[i].end.rua, p[i].end.numero, p[i].end.estado);
                    break;

                } else if(strcmp(p[i].nome, busca) != 0 && i == qtdResgistros){
                    printf("Registro ausente para alteracao\n");
                }
            }
        }
    }

    return 0;
}