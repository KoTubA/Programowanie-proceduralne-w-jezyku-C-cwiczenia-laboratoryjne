#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
}Node;

Node *p = NULL;

void PrintTree(Node *wsk_str) {
    if(wsk_str == NULL) return;
    if(wsk_str->left!=NULL) PrintTree(wsk_str->left);
    printf("%d\n",wsk_str->data);
    if(wsk_str->right!=NULL) PrintTree(wsk_str->right);
}

Node *find(int x)
{
    Node *q = p;

    while(q!=NULL)
    {
        if(q->data == x) return q;
        if(q->data < x ) q = q->right;
        else q = q->left;
    }

    q = NULL;
    return q;
}


Node *new_node(int x)
{
    Node *new_n = (Node *) malloc(sizeof(Node));

    new_n->left = NULL;
    new_n->right = NULL;
    new_n->data = x;

    return new_n;
}


void insert(int dodawana, Node **wsk_str)
{
    if(*wsk_str == NULL)
    {
        *wsk_str = new_node(dodawana);
        return;
    }

    Node *first = *wsk_str;
    Node *second;
    int czy_w_prawo = 0;

    while(first != NULL)
    {
        if(first->data == dodawana) return;
        second = first;
        if(czy_w_prawo = (dodawana > first->data)) first = first->right;
        else first = first->left;

    }

    if(czy_w_prawo) second->right = new_node(dodawana);
    else second->left = new_node(dodawana);

}

int main()
{
    insert(9,&p);
    insert(6,&p);
    insert(4,&p);
    insert(7,&p);
    insert(2,&p);
    insert(11,&p);
    insert(15,&p);
    insert(12,&p);
    insert(25,&p);
    PrintTree(p);

    return 0;
}
