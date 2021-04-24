#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

int count_line(FILE *fp);
void c_array_strings(FILE *fp);
void sort_array(char **tab, int tab_size);
void print_array(char **tab, int tab_size);

int main(void)
{
    FILE* fp;
    fp = fopen("text.txt", "r");

    if(fp==NULL) {
        printf("Plik nie zostal otwarty!");
        return 1;
    }

    c_array_strings(fp);

    fclose(fp);
    return 0;
}

int count_line(FILE *fp) {
    int counter;
    char buffer[MAX_LEN];

    while (fgets(buffer, MAX_LEN - 1, fp))
    {
        counter++;
    }

    rewind(fp);

    return counter;
}

void c_array_strings(FILE *fp) {
    char buffer[MAX_LEN];

    int size = count_line(fp);
    char *locality[size];
    int i = 0;

    while(fgets(buffer, MAX_LEN - 1, fp))
    {
        //Usuwanie koncowego znaku nowej linii
        buffer[strcspn(buffer, "\n")] = 0;

        int len = strlen(buffer);
        locality[i] = malloc(len+1);
        strcpy(locality[i], buffer);
        i++;
    }

    sort_array(locality, size);
    print_array(locality, size);
}

void sort_array(char **tab, int tab_size) {
    char temp[50];

    for(int i=0; i<tab_size; i++) {
        for(int j=i+1; j<tab_size; j++) {
            if(strcmp(tab[i], tab[j])>0) {
                strcpy(temp, tab[i]);
                strcpy(tab[i], tab[j]);
                strcpy(tab[j], temp);
            }
        }
    }
}

void print_array(char **tab, int tab_size) {

    for(int j=0; j<tab_size; j++) {
        printf("%s\n", tab[j]);
    }

}
