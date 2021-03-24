#include <stdio.h>
#include <string.h>
#include <time.h>

void print_latin_word(char word[]) {
    int len = strlen(word);
    char c_word[len+3];

    for(int i=0; i<len-1; i++) {
        c_word[i] = word[i+1];
    }
    c_word[len-1] = word[0];
    c_word[len] = 'a';
    c_word[len+1] = 'y';
    c_word[len+2] = '\0';

    printf("%s ", c_word);
}

int main(void){

    char str[] = "jump the computer";
    char korektor[]= " ";
    char *schowek = strtok(str, korektor);

    while(schowek != NULL)
    {
        print_latin_word(schowek);
        schowek = strtok( NULL, korektor );
    }

    return 0;
}
