#include <stdio.h>
#include <string.h>

void better_strcmp(char s1[], char s2[])
{
    int result = strcmp(s1,s2);
    if(result<0) {
        printf("Pierwszy ciag jest dluzszy\n");
    }
    else if(result>0) {
        printf("Drugi ciag jest dluzszy\n");
    }
    else {
        printf("Ciagi sa rowne\n");
    }
}

int main(void){
    char tab1[50],tab2[50];
    printf("Podaj pierwszy ciag:\n");
    scanf("%s", tab1);
    printf("Podaj drugi ciag:\n");
    scanf("%s",tab2);

    better_strcmp(tab1, tab2);

    return 0;
}
