#include <stdio.h>
#include <string.h>

void print_three(char *str)
{
    int len = strlen(str);

    char copy[4];

    for (int i = 0; i<len && i<3; i++) {
        copy[i]=str[i];
    }

    printf("%s",copy);
}

int main(void){

    char tab[] = "Ala ma kota";
    print_three(tab);

    return 0;
}
