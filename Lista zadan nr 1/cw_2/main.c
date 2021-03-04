#include<stdio.h>
double *max(double *, int );
int main(void)
{
	double t[10] = {1,2,3,4,565,6,7,856,9,10};
    double *m = max(t, 10);
    printf("Maksymalny elemnt tablicy t wynosi: %f", *m);

    return 0;
}

double *max(double *t, int size)
{
    double *m = t;
    for(int i = 0; i < size; i++) {
        if (*(t+i) > *m)
            m = t+i;
    }
    return m;
}
