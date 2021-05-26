#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node * left, *right;
}Node;

void printNode(Node * p){
    if(p == NULL){
        return;
    }
    printNode(p->left);
    printf("%d\n",p->data);
    printNode(p->right);
}

int main()
{
    Node * head = (Node *) malloc(sizeof(Node));
    head->data = 9;
    head->left = (Node *) malloc(sizeof(Node));
    head->right = (Node *) malloc(sizeof(Node));
    Node * p = head->left;
    Node * q = head->right;
    p->data = 6;
    p->left = (Node *) malloc(sizeof(Node));
    p->right = (Node *) malloc(sizeof(Node));

    p->left->data = 4;
    p->left->left = (Node *) malloc(sizeof(Node));
    p->left->right = NULL;
    p->left->left->data = 2;
    p->left->left->left = NULL;
    p->left->left->right = NULL;

    p->right->data = 7;
    p->right->left = NULL;
    p->right->right = NULL;


    q->data = 11;
    q->left = NULL;
    q->right = (Node *) malloc(sizeof(Node));

    q->right->data = 15;
    q->right->left = NULL;
    q->right->right = NULL;

    Node * esa = head;
    printNode(esa);

    return 0;
}
