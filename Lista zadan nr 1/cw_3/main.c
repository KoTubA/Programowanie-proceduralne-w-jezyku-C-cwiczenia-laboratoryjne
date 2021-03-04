#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *x, int *y);
void sort(int *t1, int *t2);
int *createArray(int size);
void print_array(int *p, int size);

int main(void)
{
    for (int i = 0; i<5; i++) {
        printf("Podaj dl tablicy: ");

        int s;
        scanf("%d",&s);

        int *w = createArray(s);
        print_array(w, s);
        sort(w, w+s-1);
        printf("\n");
        print_array(w, s);
        printf("\n");

        free(w);
    }

    return 0;
}

void sort(int *t1, int *t2) {

    while (t1!=t2) {
        int *z = t1;
        int *z2 = t1+1;

        while (z!=t2) {
            if(*z>*z2) swap(z, z2);
            z++;
            z2++;
        }
        t2--;
    }



}

void swap(int *x, int *y) {
    int copy = *x;
    *x = *y;
    *y = copy;
}

int *createArray(int size) {
    int *p = malloc(size*sizeof(int));

    srand(time(NULL));

    for (int i=0; i<size; i++) {
        *(p+i) = rand()%201-100;
    }

    return p;
}

void print_array(int *p, int size) {
    for (int j=0; j<size; j++) {
        printf("%d ", *(p+j));
    }
}
