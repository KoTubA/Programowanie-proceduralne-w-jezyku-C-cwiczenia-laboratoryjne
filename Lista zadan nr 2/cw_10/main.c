#include<stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    FILE *plik = fopen("numbers.txt","r");

    if(plik==NULL) {
        printf("Plik nie zostal otwarty!");
        return 1;
    }

    fscanf(plik, "%d", &n);

    int **tab=(int**) malloc(n*sizeof(int*));
    int *temp=(int*) malloc(n*sizeof(int));

    for(int i=0; i<n; i++) {

        fscanf(plik, "%d", &temp[i]);
        tab[i]=(int*) malloc(temp[i]*sizeof(int));

        for(int j=0; j<temp[i]; j++) {
            fscanf(plik, "%d", &tab[i][j]);
        }
    }

    for(int i=0; i<n; i++) {
        printf("tab[%d]:\n",i);
        for(int j=0; j<temp[i]; j++) {
            printf("%d ",tab[i][j]);
        }
        printf("\n\n");
    }


    fclose(plik);

    return 0;
}
