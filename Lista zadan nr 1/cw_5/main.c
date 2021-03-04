#include<stdio.h>
#include<time.h>

int main(void)
{

    FILE *plik = fopen("numbers.txt","w");

    if(plik==NULL) {
        printf("Plik nie zostal otwarty!");
        return 1;
    }

    srand(time(NULL));
    for(int i=0; i<500; i++) {
        fprintf(plik, "%d\n", rand()%999+1);
    }

    fclose(plik);

    return 0;
}
