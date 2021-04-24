#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

Node *tail = NULL;

int size = 0;

void printQueue() {
    Node *q = tail;

    printf("Zawartosc kolejki:\n");

    while(q != NULL)
    {
        printf("%d ", q->value);
        q = q->next;
    }
    printf("\n");

}

void enqueue() {
    int new_value;
    printf("Podaj warosc wezla: ");
    scanf("%d", &new_value);


    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->value = new_value;
    new_node->next = tail;
    tail = new_node;
    size++;
}

int dequeue() {
    int number;

    if(size != 0)
	{
	    Node *temp = tail;
	    for(int i = 0; i < size - 2; i++)
		{
			temp = temp->next;
		}
        if(size==1) {
            number = temp->value;
            tail = NULL;
        }
        else {
            number = temp->next->value;
            free(temp->next);
            temp->next = NULL;
        }
		size--;
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
                number = dequeue();
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
