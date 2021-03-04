#include<stdio.h>

int main(void)
{

    FILE *plik = fopen("plik.txt","w");

    if(plik==NULL) {
        printf("Plik nie zostal otwarty!");
        return 1;
    }

    fprintf(plik, "Programowanie Proceduralne 2021");

    fclose(plik);

    return 0;
}
