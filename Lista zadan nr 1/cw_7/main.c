#include <stdio.h>
#include <stdlib.h>

int count_numbers(FILE *plik);
int *create_array(int tab_size);
void complete_array(int *tab, FILE *file, int size);
void print_array(int *tab,int size);

int main()
{
    FILE *plik = fopen("numbers2.txt","r");

    int size = count_numbers(plik);

    int *w = create_array(size);
    plik = fopen("numbers2.txt","r");

    complete_array(w,plik,size);

    print_array(w,size);

    return 0;
}

int count_numbers(FILE * plik)
{
    int counter = 0;
    int temp;
    while(fscanf(plik,"%d",&temp)!=EOF)
    {
        counter++;
    }
    fclose(plik);
    return counter;
}

int *create_array(int tab_size)
{
    int *ptr = (int*) malloc(tab_size * sizeof(int));

    return ptr;
}

void complete_array(int *tab, FILE *file, int size)
{
    int i = 0;

    while(fscanf(file,"%d",&tab[i++])!=EOF );

    fclose(file);
}

void print_array(int * tab,int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d\n",tab[i]);
    }
}
