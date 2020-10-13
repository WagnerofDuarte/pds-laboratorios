#include <stdio.h>
#include <string.h>
#include <math.h>

struct Iris {

    double comprimento_sepala, largura_sepala, comprimento_petala, largura_petala;
    char tipo[50];
        
    };

int main(){

    int n;

    scanf("%d", &n);

    struct Iris iris[n];

    for(int i = 0; i < n; i++){
        scanf("%lf", &iris[i].comprimento_sepala);
        scanf("%lf", &iris[i].largura_sepala);
        scanf("%lf", &iris[i].comprimento_petala);
        scanf("%lf", &iris[i].largura_petala);
        scanf("%s", iris[i].tipo);
    }

    struct Iris irisDesconhecida;

    scanf("%lf", &irisDesconhecida.comprimento_sepala);
    scanf("%lf", &irisDesconhecida.largura_sepala);
    scanf("%lf", &irisDesconhecida.comprimento_petala);
    scanf("%lf", &irisDesconhecida.largura_petala);

    double menorDistanciaEuclidiana = 0;
    double distanciaEuclidiana = 0;
    int index = 0;

    for(int i = 0; i < n; i++){
        
        distanciaEuclidiana += (irisDesconhecida.comprimento_sepala - iris[i].comprimento_sepala)*(irisDesconhecida.comprimento_sepala - iris[i].comprimento_sepala);
        distanciaEuclidiana += (irisDesconhecida.largura_sepala - iris[i].largura_sepala)*(irisDesconhecida.largura_sepala - iris[i].largura_sepala);
        distanciaEuclidiana += (irisDesconhecida.comprimento_petala - iris[i].comprimento_petala)*(irisDesconhecida.comprimento_petala - iris[i].comprimento_petala);
        distanciaEuclidiana += (irisDesconhecida.largura_petala - iris[i].largura_petala)*(irisDesconhecida.largura_petala - iris[i].largura_petala);

        distanciaEuclidiana = sqrt(distanciaEuclidiana);

        if(i == 0){

            menorDistanciaEuclidiana = distanciaEuclidiana;

        } else {

            if(distanciaEuclidiana < menorDistanciaEuclidiana){
                menorDistanciaEuclidiana = distanciaEuclidiana;
                index = i;
            }
        }
    }

    printf("%s", iris[index].tipo);

    return 0;
}