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

int main()
{
    return 0;
}
