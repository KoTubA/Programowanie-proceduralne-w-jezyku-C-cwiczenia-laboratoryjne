#include <stdio.h>
#include <stdlib.h>

typedef struct Struktura
{
    struct Struktura *next;
    int *tablica;
    int **tablica_w;

}Struktura;

int main()
{
    Struktura *p1 = (Struktura *)malloc(sizeof(Struktura));

    p1->next = (Struktura *)malloc(sizeof(Struktura));

    p1->tablica = (int *)malloc(sizeof(int) * 4);

    for (int i = 0; i < 4; i++)
    {
        p1->tablica[i] = i + 3;
    }

    p1->tablica_w = (int **)malloc(sizeof(int *) * 4);

    int *temp = p1->tablica;
    for (int i = 0; i < 4; i++)
    {
        p1->tablica_w[i] = temp++;
    }

    p1->next->next = NULL;
    p1->next->tablica = (int *)malloc(sizeof(int) * 3);

    for (int i = 0; i < 3; i++)
    {
        p1->next->tablica[i] = 6 - i;
    }

    p1->next->tablica_w = (int **)malloc(sizeof(int *) * 4);

    temp = p1->next->tablica;

    p1->next->tablica_w[0] = NULL;

    for (int i = 1; i < 4; i++)
    {
        p1->next->tablica_w[i] = temp++;
    }

    int **q = p1->next->tablica_w + 3;
    int **p2 = q;

    temp = p1->next->tablica;
    int *p3 = temp + 2;

    return 0;
}
