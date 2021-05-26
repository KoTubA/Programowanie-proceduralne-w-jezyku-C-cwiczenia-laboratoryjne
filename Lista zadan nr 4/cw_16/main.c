#include <stdio.h>
#include <math.h>
#define SIZE 10

void transform(double *source, double *target, int size, double (*wsk)(double));
double multiply(double x);
double power(double x);
int main()
{
    double tab[SIZE];
    double tab2[SIZE];
    double tab3[SIZE];
    double tab4[SIZE];
    double tab5[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        tab[i] = i;
    }

    transform(tab, tab2, SIZE, multiply);
    printf("FUNKCJA POMNOZ PRZEZ DWA:\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%.2lf\n", tab2[i]);
    }

    transform(tab, tab3, SIZE, power);
    printf("FUNKCJA LICZBA DO POTEGI DWA:\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%.2lf\n", tab3[i]);
    }

    transform(tab, tab4, SIZE, sin);
    printf("FUNKCJA SIN(math.h):\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%.2lf\n", tab4[i]);
    }


    transform(tab, tab5, SIZE, cos);
    printf("FUNKCJA COS(math.h):\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%.2lf\n", tab5[i]);
    }


    return 0;
}

void transform(double *source, double *target, int size, double (*wsk)(double))
{
    for (int i = 0; i < size; i++)
    {
        target[i] = wsk(source[i]);
    }
}

double multiply(double x)
{
    return x * 2;
}

double power(double x)
{
    return x * x;
}
