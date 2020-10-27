#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int qtd_funcionarios = 0;

struct Data {

    int dia;
    int mes;
    int ano;

};

struct Funcionario {

   char nome[50];
   char salario[50];
   char data_de_admissao[50];
   char departamento[50];
   struct Data data;

} funcionario[100], aux;

void ler_arquivo(char nome_arquivo[20]){

    FILE *fPtr = NULL;
    fPtr = fopen(nome_arquivo, "r");
    char c[50];

    int j = 0;
    int i = 0;

    while (fgets(c, sizeof(c), fPtr)){

        char te[sizeof(c)];
        
        strcpy(te, c);

        if(i == 0){
            i = 1;
        } else if(i == 1){
            strcpy(funcionario[j].nome, te);
            i++;
        } else if(i == 2){
            strcpy(funcionario[j].salario, te);
            i++;
        } else if(i == 3){
            strcpy(funcionario[j].data_de_admissao, te);
            funcionario[j].data.dia = (("%c",funcionario[j].data_de_admissao[0]) - '0')*10 + (("%c",funcionario[j].data_de_admissao[1]) - '0');
            funcionario[j].data.mes = (("%c",funcionario[j].data_de_admissao[3]) - '0')*10 + (("%c",funcionario[j].data_de_admissao[4]) - '0');
            funcionario[j].data.ano = (("%c",funcionario[j].data_de_admissao[6]) - '0')*1000 + (("%c",funcionario[j].data_de_admissao[7]) - '0')*100 + (("%c",funcionario[j].data_de_admissao[8]) - '0')*10 + (("%c",funcionario[j].data_de_admissao[9]) - '0');
            i++;
        } else if(i == 4){
            strcpy(funcionario[j].departamento, te);
            i = 1;
            j++;
            qtd_funcionarios++;
        }
    }
    
    fclose(fPtr);
}

int exportar_lista_de_funcionarios(char nome_arquivo2[20]){

    FILE *fexp = NULL;
    fexp = fopen(nome_arquivo2, "w");

    for (int i = 1; i < qtd_funcionarios; i++) {
        for (int j = 1; j < qtd_funcionarios; j++) {
            if (strcmp(funcionario[j - 1].nome, funcionario[j].nome) > 0) {
                aux = funcionario[j - 1];
                funcionario[j - 1] = funcionario[j];
                funcionario[j] = aux;
            }
        }
    }

    for(int i = 0; i < qtd_funcionarios; i++){
        fprintf(fexp,"%s",funcionario[i].nome);
        fprintf(fexp,"%s",funcionario[i].salario);
        fprintf(fexp,"%s",funcionario[i].data_de_admissao);
        fprintf(fexp,"%s",funcionario[i].departamento);
    }

    fclose(fexp);

    return 0;
}

/*******************************/

int listar_funcionarios_por_departamento(char departamento[50], int size){

    char departamentoT[50];
    strcpy(departamentoT, departamento);

    for (int i = 1; i < qtd_funcionarios; i++) {
        for (int j = 1; j < qtd_funcionarios; j++) {
            if (strcmp(funcionario[j - 1].nome, funcionario[j].nome) > 0) {
                aux = funcionario[j - 1];
                funcionario[j - 1] = funcionario[j];
                funcionario[j] = aux;
            }
        }
    }

    for(int i = 0; i < qtd_funcionarios; i++){
        if(strncmp(funcionario[i].departamento, departamentoT, size) == 0){
            printf("%s", funcionario[i].nome);
            printf("%s", funcionario[i].salario);
            printf("%s", funcionario[i].data_de_admissao);
            printf("%s", funcionario[i].departamento);
        }
    }

    return 0;
}

/*******************************/

int encontrar_funcionario_mais_antigo(){

    int menor_index = 0;

    for(int i = 1; i < qtd_funcionarios; i++){
        if(funcionario[menor_index].data.ano > funcionario[i].data.ano){
            menor_index = i;
        } else if(funcionario[menor_index].data.ano == funcionario[i].data.ano && funcionario[menor_index].data.mes > funcionario[i].data.mes) {
            menor_index = i;
        } else if(funcionario[menor_index].data.ano == funcionario[i].data.ano && funcionario[menor_index].data.mes == funcionario[i].data.mes && funcionario[menor_index].data.dia > funcionario[i].data.dia){
            menor_index = i;
        }
    }

    printf("%s", funcionario[menor_index].nome);
    printf("%s", funcionario[menor_index].salario);
    printf("%s", funcionario[menor_index].data_de_admissao);
    printf("%s", funcionario[menor_index].departamento);

    return 0;
}

/*******************************/

int encontrar_funcionario_mais_antigo_do_departamento(char departamento[50], int size){
    

    int menor_index;

    for(int i = 0; i < qtd_funcionarios; i++){
        if(strncmp(departamento, funcionario[i].departamento, size) == 0){
            menor_index = i;
            break;
        }
    }

    for(int i = 1; i < qtd_funcionarios; i++){
        if(funcionario[menor_index].data.ano > funcionario[i].data.ano && strncmp(departamento, funcionario[i].departamento, size) == 0){
            menor_index = i;
        } else if(funcionario[menor_index].data.ano == funcionario[i].data.ano && funcionario[menor_index].data.mes > funcionario[i].data.mes && strncmp(departamento, funcionario[i].departamento, size) == 0) {
            menor_index = i;
        } else if(funcionario[menor_index].data.ano == funcionario[i].data.ano && funcionario[menor_index].data.mes == funcionario[i].data.mes && funcionario[menor_index].data.dia > funcionario[i].data.dia && strncmp(departamento, funcionario[i].departamento, size) == 0){
            menor_index = i;
        }
    }

    printf("%s", funcionario[menor_index].nome);
    printf("%s", funcionario[menor_index].salario);
    printf("%s", funcionario[menor_index].data_de_admissao);
    printf("%s", funcionario[menor_index].departamento);

    return 0;
}

/*******************************/

int calcular_media_salarial(){

    float media_salarial = 0;

         for(int i = 0; i < qtd_funcionarios; i++){
             media_salarial = media_salarial + atof(funcionario[i].salario);
        }

    printf("%.2f", (media_salarial/qtd_funcionarios));

    return 0;
}

/*******************************/

int calcular_media_salarial_por_departamento(char departamento[50], int size){

    float media_salarial = 0;
    int qtd_funcionarios_departamento = 0;
         for(int i = 0; i < qtd_funcionarios; i++){
             if(strncmp(departamento, funcionario[i].departamento, size) == 0){
                 media_salarial = media_salarial + atof(funcionario[i].salario);
                 qtd_funcionarios_departamento++;
             }
        }

    printf("%.2f", (media_salarial/qtd_funcionarios_departamento));

    return 0;
}

/*******************************/

int main(int argc, char *argv[]){

    ler_arquivo(argv[1]);

    if(argc == 3){

        if(strcmp(argv[2], "3") == 0){
            encontrar_funcionario_mais_antigo();
        } else if(strcmp(argv[2], "5") == 0){
            calcular_media_salarial();
        }

    } else if(argc == 4){

        if(strcmp(argv[2], "1") == 0){
            exportar_lista_de_funcionarios(argv[3]);
        } else if(strcmp(argv[2], "2") == 0){
            int size = sizeof(argv[3]);
            listar_funcionarios_por_departamento(argv[3], size);
        } else if(strcmp(argv[2], "4") == 0){
            char departamento[50];
            strcpy(departamento, argv[3]);
            int size = sizeof(argv[3]);
            encontrar_funcionario_mais_antigo_do_departamento(departamento, size);
        } else if(strcmp(argv[2], "6") == 0){
            int size = sizeof(argv[3]);
            calcular_media_salarial_por_departamento(argv[3], size);
        }

    }

    return 0;

}