#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    char value;
    struct node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

int size = 0;

void printQueue() {
    Node *q = head;

    printf("Zawartosc kolejki:\n");

    while(q != NULL)
    {
        printf("%c ", q->value);
        q = q->next;
    }
    printf("\n");

}

void enqueue() {
    char character;
    printf("Podaj znak wezla: ");
    scanf(" %c", &character);

    Node *temp = (Node *) malloc(sizeof(Node));
    temp->value = character;
    temp->next = NULL;

    if(head==NULL) {
        head = temp;
        tail = temp;
    }
    else {
        if(head->next==NULL) head->next = temp;
        tail->next=temp;
        tail=temp;
    }
}

int dequeue() {
    char character;

    if(head != NULL)
	{
	    character = head->value;
	    Node *temp = head->next;
	    free(head);
	    head = temp;
	}
	else {
        character = NULL;
	}

    return character;
}

int main()
{
    int choice;
    char character;
    do {
        printQueue();
        printf("Menu glowne stosu:\n");
        printf("1. Dodaj do kolejki\n");
		printf("2. Usun z kolejki\n");
        printf("3. Koniec programu\n");
        printf("Wybor: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                system("cls");
                enqueue();
                break;
            case 2:
                system("cls");
                character = dequeue();
                if(character!=NULL) {
                    printf("Usuniety znak to: %c\n", character);
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
