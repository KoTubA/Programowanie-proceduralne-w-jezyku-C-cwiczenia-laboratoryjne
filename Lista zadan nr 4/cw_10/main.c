#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void liczba_calkowita(int first, FILE *p)
{
    int second = rand() % 5001;
    fprintf(p, "%d %d\n", first, second);
}

void losowy_znak(int first, FILE *p)
{
    int x = (rand() % 69) + 58;
    fprintf(p, "%d %c\n", first, x);
}

void losowa_liczba_zmiennoprzecinkowa(int first, FILE *p)
{
    double a = (rand() % 100) + 1;
    double b = (rand() % 100) + 1;

    double x = (a / b) / 0.1;

    fprintf(p, "%d %.3lf\n", first, x);
}

void wypelnij_plik(FILE *p)
{
    for (int i = 0; i < 1000; i++)
    {
        int first = rand() % 3;

        if (first == 0)
        {
            losowy_znak(first, p);
        }

        if (first == 1)
        {
            liczba_calkowita(first, p);
        }

        if (first == 2)
        {
            losowa_liczba_zmiennoprzecinkowa(first, p);
        }
    }
}

int main()
{
    FILE *plik = fopen("data.txt", "w");

    if (plik == NULL)
    {
        printf("Plik nie zostal otwarty");
        return 1;
    }

    srand(time(NULL));

    wypelnij_plik(plik);

    fclose(plik);
    return 0;
}
