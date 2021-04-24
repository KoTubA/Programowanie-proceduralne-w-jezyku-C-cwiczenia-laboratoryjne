#include <stdio.h>
#include <string.h>

void print_sentence(char search_ptr[], char word[], int *a) {
    if(strstr(search_ptr, word)!= NULL) {
        *a = *a+1;
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
    char word[] = "Lorem";
    while(fscanf(plik,"%s",&str)==1)
    {
        print_sentence(str, word, &counter);
    }


    printf("Ilosc slowa \"%s\" w pliku wynosi: %d", word, counter);

    fclose(plik);

    return 0;
}
