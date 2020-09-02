#include <stdio.h>
#include <string.h>

int main(){

    char S1[20];
    char c1, c2;

    scanf("%[^\n]s", S1);
    
    scanf(" %c", &c1);
    scanf(" %c", &c2);

    for(int i = 0; i < strlen(S1); i ++){
        if(S1[i] == c1){
            S1[i] = c2;
            break;
        }
    }

    printf("%s", S1);

    return 0;
}