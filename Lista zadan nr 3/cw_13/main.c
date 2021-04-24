#include <stdio.h>
#include <string.h>

void print_sentence(char search_ptr[], char word[]) {
    if(strstr(search_ptr, word)!= NULL) {
        char *start = strstr(search_ptr, word);
        puts(start);
        print_sentence(start+1, word);
    }
}

int main(void){

    char str[] = "Czy liczby dodane do siebie do super?";
    char w[] = "do ";
    print_sentence(str, w);

    return 0;
}
