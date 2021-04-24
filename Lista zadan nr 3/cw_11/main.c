#include<stdio.h>
#include <stdlib.h>

void print_latin_word(char word[], int *c, long int *n, int i) {
    if(i==0) {
        *c = atoi(word);
    }
    else if(i==1){
        *n = atoi(word);
    }
    else {
        *n = 10000 * *n + atoi(word);
    }
}

int main(void){

    int code;
    long int number;
    char str[] = "(555)555-5555";
    char korektor[]= "()-";
    char *schowek = strtok(str, korektor);
    int i = 0;
    while(schowek != NULL)
    {
        print_latin_word(schowek, &code, &number, i);
        schowek = strtok( NULL, korektor );
        i++;
    }

    printf("Numer kierunkowy: %d, numer: %d", code, number);

    return 0;
}
