#include <stdio.h>
#include <string.h>

char *fun(char *nazwa, char znak){

    char *wskaz = NULL;
    while(*nazwa!='\0'){
        if (*nazwa==znak){
            wskaz=nazwa;
            return wskaz;
        }
        nazwa++;
    }

    return wskaz;
}

int main(void){

    char tab[]= "Siema";
    char s = 'a';
    char *result = fun(tab,s);
    printf("%p", result);

    return 0;
}
