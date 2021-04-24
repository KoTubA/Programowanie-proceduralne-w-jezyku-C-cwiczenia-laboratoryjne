#include <stdio.h>
#include <string.h>

void print_sentence(char search_ptr[], char znak, int *a) {
    if(strchr(search_ptr, znak)!= NULL) {
        char *start = strchr(search_ptr, znak);
        *a = *a+1;
        print_sentence(start+1, znak, a);
    }
}

int main(void){

    FILE *plik = fopen("text.txt","r");

    if(plik==NULL) {
        printf("Plik nie zostal otwarty!");
        return 1;
    }

    int counter = 0;
    char str[100];
    char znak = 'l';
    while(fscanf(plik,"%s",&str)==1)
    {
        print_sentence(str, znak, &counter);
    }


    printf("Ilosc znaku \"%c\" w pliku wynosi: %d", znak, counter);

    fclose(plik);

    return 0;
}
