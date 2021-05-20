#include <stdio.h>
#include <stdlib.h>

enum SymbolType {CHARACTER, INTEGER, FLOATING};

typedef struct data {
    enum SymbolType type;
    union {
        char character;
        int number;
        float f_number;
    };
}Data;

int j = 0;

int get_size(FILE *p) {
    int counter = 0;

    while(!feof(p))
    {
      char ch = fgetc(p);
      if(ch == '\n')
      {
        counter++;
      }
    }

    rewind(p);

    return counter;
}

void odczytaj_dane(FILE *p, Data *tab, int size) {
    char str[1], str2[10];
    while(fscanf(p,"%s %s",str,str2)!=EOF)
    {
        switch (atoi(str))
        {
            case 0:
                tab[j].type = CHARACTER;
                tab[j].character = str2[0];
                break;
            case 1:
                tab[j].type = INTEGER;
                tab[j].number = atoi(str2);
                break;
            case 2:
                tab[j].type = FLOATING;
                tab[j].f_number = atof(str2);
                break;
        }
        j++;
    }
}

void printStruct(Data *tab, int size)
{

    for (int i = 0; i < size; i++)
    {
        if (tab[i].type == 0)
        {
            printf("TYP: CHARACTER\n");
            printf("Znak: %c\n", tab[i].character);
        }
        else if (tab[i].type == 1)
        {
            printf("TYP: INTEGER\n");
            printf("Liczba: %d\n", tab[i].number);
        }
        else if (tab[i].type == 2)
        {
            printf("TYP: FLOATING\n");
            printf("liczba: %.3lf\n", tab[i].f_number);
        }
    }
}

int main()
{
    FILE *plik = fopen("data.txt", "r");

    if (plik == NULL)
    {
        printf("Plik nie zostal otwarty");
        return 1;
    }

    int size = get_size(plik);
    Data *tab = (Data *)malloc(sizeof(Data) * size);
    odczytaj_dane(plik, tab, size);
    printStruct(tab, size);

    fclose(plik);
    return 0;
}
