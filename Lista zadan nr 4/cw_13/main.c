#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char *string;
    int value;
    struct node *left;
    struct node *right;
} Node;

Node *p = NULL;

int readWord(char *s, FILE *fptr) {
    int result = fscanf(fptr, "%s", s);
    strlwr(s);

    int len = strlen(s);
    if (ispunct(s[len - 1]))
        s[len - 1] = '\0';

    return result;
}

void fillFile(Node *wsk_str, FILE *fptr2) {
    if(wsk_str == NULL) return;
    if(wsk_str->left!=NULL) fillFile(wsk_str->left, fptr2);
    fprintf(fptr2, "%s\n", wsk_str->string);
    if(wsk_str->right!=NULL) fillFile(wsk_str->right, fptr2);
}

void printTree(Node *wsk_str) {
    if(wsk_str == NULL) return;
    if(wsk_str->left!=NULL) printTree(wsk_str->left);
    printf("%d\t%s\n",wsk_str->value, wsk_str->string);
    if(wsk_str->right!=NULL) printTree(wsk_str->right);
}

Node *find(char *s)
{
    Node *q = p;

    while(q!=NULL)
    {
        if(strcmp(s, q->string) == 0) return q;
        if(strcmp(s, q->string)>0) q = q->right;
        else q = q->left;
    }

    q = NULL;
    return q;
}

Node *new_node(char *s)
{
    Node *new_n = (Node *) malloc(sizeof(Node));

    new_n->string = malloc(strlen(s)+1);
    strcpy(new_n->string, s);

    new_n->value = 1;
    new_n->left = NULL;
    new_n->right = NULL;

    return new_n;
}

void insert(char *word)
{
    if(p == NULL)
    {
        p = new_node(word);
        return;
    }

    Node *temp = find(word);
    if(temp!=NULL){
        temp->value = temp->value + 1;
    }
    else {
        Node *first = p;
        Node *second;
        int to_right = 0;

        while(first != NULL)
        {
            second = first;
            if(to_right = (strcmp(word, first->string)>0)) first = first->right;
            else first = first->left;

        }

        if(to_right) second->right = new_node(word);
        else second->left = new_node(word);
    }
}

int main()
{
    FILE *fptr = fopen("text.txt", "r");

    if (fptr == NULL)
    {
        printf("Plik nie zostal otwarty");
        return 1;
    }

    char word[50];
    while (readWord(word, fptr) != EOF)
    {
        insert(word);
    }

    fclose(fptr);

    printTree(p);

    FILE *fptr2 = fopen("words.txt","w");

    if(fptr2==NULL) {
        printf("Plik nie zostal otwarty!");
        return 1;
    }

    fillFile(p, fptr2);
    fclose(fptr2);

    return 0;
}
