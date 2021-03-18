#include <stdio.h>
#include <stdlib.h>

int **create_array(int m, int n);
void complete_array(int **tab, int m, int n);
void print_array(int **tab, int m, int n);
void print_sum_rows(int **array, int row, int col);
void print_sum_columns(int **array, int row, int col);

int main()
{
    int rows;
    int columns;
    printf("Podaj ilosc rzedow: ");
    scanf("%d",&rows);

    printf("Podaj ilosc kolumn: ");
    scanf("%d",&columns);

    int **t = create_array(rows,columns);
    complete_array(t,rows,columns);
    print_array(t,rows,columns);
    print_sum_rows(t,rows,columns);
    print_sum_columns(t,rows,columns);

    free(t);

    return 0;
}

int **create_array(int m, int n)
{
    int **a = (int**) malloc(m * sizeof(int *));

    for(int i = 0; i < m; i++)
    {
        a[i] = (int*) malloc(n * sizeof(int));
    }

    return a;
}

void complete_array(int **tab, int m, int n)
{
    srand(time(NULL));

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            tab[i][j] = rand()%1001;
        }
    }
}

void print_array(int **tab, int m, int n)
{
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }
}

void print_sum_rows(int **array, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        int sum = 0;
        for(int j = 0; j < col; j++)
        {
            sum += array[i][j];
        }
        printf("Suma wiersza %d: %d\n",i+1,sum);
    }
}

void print_sum_columns(int **array, int row, int col)
{
    int *temp =(int*) malloc(col * sizeof(int));

    for(int i = 0; i < col; i++)
    {
        temp[i] = 0;
    }
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            temp[j] += array[i][j];
        }
    }

    for(int i = 0; i < col; i++)
    {
        printf("suma %d kolumny: %d",i+1,temp[i]);
        printf("\n");
    }
}
