#include <stdio.h>
#include <string.h>
#define SIZE 80

char *strcat2(char *first, char const *last);

int main()
{

    char str1[SIZE+1] = "Fabryki geniuszow sa, ";
    char *s =  "tylko surowca brak.";

    strcat2(str1, s);
    printf("Zmienna str1 zawiera teraz lancuch:\n");
    printf("%s",str1);

    return 0;
}

char *strcat2(char *first, char const *last){

    char *start = first;

    int len = strlen(first);
    first += len;

    while(*last!='\0'){
        *first = *last;
        first++;
        last++;
    }
    *first = '\0';
    return start;

}
