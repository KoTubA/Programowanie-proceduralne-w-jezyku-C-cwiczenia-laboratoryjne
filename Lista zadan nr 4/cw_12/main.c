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

void sort(Data *tab, int size)
{
    printf("Sizeof: %d", sizeof(tab));
    int liczba_int = 0;
    int liczba_char = 0;
    int liczba_float = 0;
    for (int i = 0; i < size; i++)
    {
        if (tab[i].type == INTEGER)
        {
            liczba_int++;
        }

        if (tab[i].type == CHARACTER)
        {
            liczba_char++;
        }

        if (tab[i].type == FLOATING)
        {
            liczba_float++;
        }
    }

    Data *ch = (Data *)malloc(sizeof(Data) * liczba_char);
    Data *in = (Data *)malloc(sizeof(Data) * liczba_int);
    Data *fl = (Data *)malloc(sizeof(Data) * liczba_float);

    int ch_i = 0;
    int in_i = 0;
    int fl_i = 0;

    for (int i = 0; i < size; i++)
    {
        if (tab[i].type == CHARACTER)
        {
            ch[ch_i] = tab[i];
            ch_i++;
        }

        if (tab[i].type == INTEGER)
        {
            in[in_i] = tab[i];
            in_i++;
        }

        if (tab[i].type == FLOATING)
        {
            fl[fl_i] = tab[i];
            fl_i++;
        }
    }

    for (int i = 0; i < liczba_char; i++)
    {
        for (int j = 1; j < liczba_char - i; j++)
        {
            if (ch[j - 1].character > ch[j].character)
            {
                Data temp = ch[j];
                ch[j] = ch[j - 1];
                ch[j - 1] = temp;
            }
        }
    }

    for (int i = 0; i < liczba_int; i++)
    {
        for (int j = 1; j < liczba_int - i; j++)
        {
            if (in[j - 1].number > in[j].number)
            {
                Data temp = in[j];
                in[j] = in[j - 1];
                in[j - 1] = temp;
            }
        }
    }

    for (int i = 0; i < liczba_float; i++)
    {
        for (int j = 1; j < liczba_float - i; j++)
        {
            if (fl[j - 1].f_number > fl[j].f_number)
            {
                Data temp = fl[j];
                fl[j] = fl[j - 1];
                fl[j - 1] = temp;
            }
        }
    }

    int z = 0;

    for(int i = 0; i < liczba_char; i++)
    {
        tab[z] = ch[i];
        z++;
    }

    for(int i = 0; i < liczba_int; i++)
    {
        tab[z] = in[i];
        z++;
    }

    for(int i = 0; i < liczba_float; i++)
    {
        tab[z] = fl[i];
        z++;
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
    sort(tab, size);
    printStruct(tab, size);

    fclose(plik);
    return 0;
}
