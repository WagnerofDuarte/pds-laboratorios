#include <stdio.h>
#include <string.h>


void media(double vet[], int n){

    double mediaGeral = 0;

    for(int i = 0; i < n; i++){
        mediaGeral = mediaGeral + vet[i];
    }

    mediaGeral = mediaGeral / n;
    
    float maisProximo = vet[0];
    int maisProxIndex;

    for(int i = 0; i < n; i++){
        if(mediaGeral - vet[i] < 0){
            if((mediaGeral - vet[i])*(-1) < (mediaGeral - maisProximo)){
                maisProximo = vet[i];
                maisProxIndex = i;
            }
        } else {
            if((mediaGeral - vet[i]) < (mediaGeral - maisProximo)){
                maisProximo = vet[i];
                maisProxIndex = i;
            }
        }
    }

    printf("%d", maisProxIndex);

}

int main(){
    
    int n;

    scanf("%d", &n);
    
    double vet[n];

    for(int i = 0; i < n; i++){
        scanf("%lf", &vet[i]);
    }

    media(vet, n);

    return 0;
}