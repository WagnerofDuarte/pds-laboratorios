#include <stdio.h>
#include <string.h>

int main(){

    char S1[20];
    char S2[20];

    scanf(" %[^\n]s", S1);
    scanf(" %[^\n]s", S2);

    if(strstr(S1, S2) != NULL) {

        printf("É substring");

    } else {

        printf("Não é substring");

    }

    return 0;
}