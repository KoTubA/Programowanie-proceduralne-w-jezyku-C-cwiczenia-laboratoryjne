#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    int **right;
}Node;


int main()
{
    Node *structur1 = malloc(sizeof(Node));
    Node *structur2 = malloc(sizeof(Node));

    int **p1, **p2;
    int tab5[] = {5,6,7};
    int tab4[] = {1,2,3,4};
    int *tab3[] = {NULL,tab4,tab5};
    int *tab2[] = {NULL,NULL};
    int *tab1[] = {&structur1, NULL, &structur2};

    structur1->data = 7;
    structur1->right = tab2;
    structur2->data = 4;
    structur2->right = tab3;

    printf("%d",structur2->right);

    p1 = tab1;
    p2 = tab3;

    return 0;
}
