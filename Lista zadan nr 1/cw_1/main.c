#include <stdio.h>
#include <stdlib.h>

int bigger (int *tab, int n, int k);

int main()
{
    int t[10] = {1,4,6,7,3,9,10,12,15,20};

    printf("Liczba elementow wiekszych od %d wynosi: %d", 5, bigger(t, 10, 5));
    return 0;
}


int bigger (int *tab, int n, int k) {
    int counter = 0;

    for(int i=0; i<n; i++) {
        if(*(tab+i)>k) counter++;
    }


    return counter;
}
