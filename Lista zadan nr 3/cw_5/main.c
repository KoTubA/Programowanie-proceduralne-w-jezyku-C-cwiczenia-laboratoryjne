#include <stdio.h>
#include <string.h>

void fword(char str[]) {
    scanf("%s",str);
    printf("%s", str);
    fflush(stdin);
}

int main(void){

    char tab[20];
    fword(tab);

    return 0;
}
