#include<stdio.h>
#include<time.h>

int main(void)
{

    FILE *plik = fopen("numbers.txt","r");
    FILE *plik2 = fopen("numbers2.txt","w");

    if(plik==NULL||plik2==NULL) {
        printf("Plik nie zostal otwarty!");
        return 1;
    }

    int tab[500];
    while(fscanf(plik,"%d",&tab)==1)
    {
        printf("%d\n",*tab);
        if(*tab % 3==0)fprintf(plik2,"%d\n",*tab);
    }

    fclose(plik);
    fclose(plik2);

    return 0;
}
