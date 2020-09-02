#include <stdio.h>
#include <string.h>

int main(){

    char S1[10], S2[10], O[20];

    scanf("%s", S1);
    scanf("%s", S2);

    strcpy(O, S1);
    strcat(O, S2);

    printf("%s", O);

    return 0;
}