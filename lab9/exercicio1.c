#include <stdio.h>
#include <string.h>

struct Data {

    int dia, ano, mes;
        
    };

struct Evento {

    char nome[100], local[100];
    struct Data data;
    
    };

int main(){

    int n;
    scanf("%d", &n);

    struct Evento evento[n];

    for(int i = 0; i < n; i++){
        scanf(" %s", evento[i].nome);
        scanf(" %s", evento[i].local);
        scanf(" %d", &evento[i].data.dia);
        scanf(" %d", &evento[i].data.mes);
        scanf(" %d", &evento[i].data.ano);
    }

    struct Data dataDePesquisa;

    scanf(" %d %d %d", &dataDePesquisa.dia, &dataDePesquisa.mes, &dataDePesquisa.ano);

    for(int i = 0; i < n; i++){
        if(evento[i].data.dia == dataDePesquisa.dia && evento[i].data.mes == dataDePesquisa.mes && evento[i].data.ano == dataDePesquisa.ano){
            printf("%s %s\n", evento[i].nome, evento[i].local);
        }
    }

    return 0;
}