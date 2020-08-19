#include <stdio.h>

int main(){

    int numAEDS;
    int numCALCULO;

    scanf("%d", &numAEDS);

    int AEDS[numAEDS];

    for(int i = 0; i < numAEDS; i++){
        scanf("%d", &AEDS[i]);
    }
    
    scanf("%d", &numCALCULO);

    int CALCULO[numCALCULO];

    for(int i = 0; i < numCALCULO; i++){
        scanf("%d", &CALCULO[i]);
    }

    for(int i = 0; i < numAEDS; i++){
        for(int j = 0; j < numCALCULO; j++){
            if(AEDS[i] == CALCULO[j]){
                printf("%d\n", AEDS[i]);
            }
        }
    }

    return 0;
}