#include <stdio.h>
#include <string.h>

int main(){

    char S1[10];

    scanf("%[^\n]s", S1);
    
    int size = strlen(S1);
    
    char S2[size];

    for(int i = 0; i < size; i++){
        S2[i] = S1[(size - 1) - i];
    }

    printf("%s", S2);

    return 0;
}