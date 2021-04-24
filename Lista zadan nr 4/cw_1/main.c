#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

Node *first = NULL;

void printStack() {
    Node *q = first;

    printf("Zawartosc stosu:\n");

    while(q != NULL)
    {
        printf("%d\n", q->value);
        q = q->next;
    }
    printf("\n");

}

void push() {
    int new_value;
    printf("Podaj warosc wezla: ");
    scanf("%d", &new_value);

    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->value = new_value;
    new_node->next = first;
    first = new_node;
}

int pop() {
    int number;

    if(first != NULL)
	{
	    number = first->value;
		Node *temp = first->next;
		free(first);
		first = temp;
	}
	else {
        number = NULL;
	}

    return number;
}

int main()
{
    int choice, number;
    do {
        printStack();
        printf("Menu glowne stosu:\n");
        printf("1. Push (dodaje element na szczyt stosu)\n");
        printf("2. Pop (usuwa element na szczyt stosu)\n");
        printf("3. Koniec programu\n");
        printf("Wybor: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                system("cls");
                push();
                break;
            case 2:
                system("cls");
                number = pop();
                if(number!=NULL) {
                    printf("Usunieta wartosc to: %d\n", number);
                }
                else {
                    printf("Stos jest pusty!\n");
                }
                break;
            case 3:
				system("cls");
				break;
            default:
				system("cls");
				printf("Wybierz dostepna opcje!\n");
				break;
        }

    }while(choice!=3);

    return 0;
}
