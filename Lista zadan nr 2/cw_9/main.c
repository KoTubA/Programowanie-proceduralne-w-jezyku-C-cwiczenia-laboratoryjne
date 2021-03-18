#include<stdio.h>
#include <stdlib.h>
#include<time.h>

int main(void)
{
    int n, m;
    FILE *plik = fopen("numbers.txt","w");

    if(plik==NULL) {
        printf("Plik nie zostal otwarty!");
        return 1;
    }

    srand(time(NULL));
    n = rand()%451+50;
    fprintf(plik, "%d\n", n);

    for(int i=0; i<n; i++) {
        m = rand()%78+2;
        fprintf(plik, "%d\n", m);
        for(int j=0; j<m; j++) {
            fprintf(plik, "%d ", rand()%1001-500);
        }
        fprintf(plik, "\n");
    }

    fclose(plik);

    return 0;
}
