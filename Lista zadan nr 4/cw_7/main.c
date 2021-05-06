#include <stdio.h>
#include <stdlib.h>
typedef struct structure{
	int data;
	int **array;
} Structure;

int main()
{
    int **p2;
    Structure **p1;
    p2 = malloc(sizeof(int*)*3);
    p2[0] = NULL;
    p2[1] = malloc(sizeof(int)*4);
    p2[2] = malloc(sizeof(int)*3);

    for(int i=0; i<4; i++) {
        p2[1][i]=i+1;
    }

    for(int j=0; j<3; j++) {
        p2[1][j]=j+5;
    }

    p1 = malloc(sizeof(Structure*)*3);
    p1[0] = malloc(sizeof(Structure));
    p1[2] = malloc(sizeof(Structure));

    p1[0]->data = 7;
    p1[0]->array = malloc(sizeof(int*)*2);
    p1[0]->array[0] = NULL;
    p1[0]->array[1] = NULL;
    p1[1] = NULL;
    p1[2]->data = 4;
    p1[2]->array = p2;

	return 0;
}
