#include <stdio.h>
#include <string.h>

void better_strcmp(char s1[], char s2[], int n)
{
    char s1_copy[n], s2_copy[n];

    for(int i=0; i<n; i++){
        s1_copy[i] = s1[i];
        s2_copy[i] = s2[i];
    }

    int result = strcmp(s1, s2);

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
    int size;
    char tab1[50],tab2[50];
    printf("Podaj pierwszy ciag:\n");
    scanf("%s", tab1);
    printf("Podaj drugi ciag:\n");
    scanf("%s",tab2);
    printf("Podaj jak dlugi wyraz porownywac:\n");
    scanf("%d", &size);

    better_strcmp(tab1, tab2, size);

    return 0;
}
