#include<stdio.h>
#include<stdlib.h>

int index = 0;
int size = 2;

void printStack(int t[]) {

    printf("Zawartosc stosu:\n");

    for(int i = index-1; i>=0; i--)
    {
        printf("%d\n", t[i]);
    }
    printf("\n");

}

void push(int t[]) {
    int new_value;
    printf("Podaj warosc wezla: ");
    scanf("%d", &new_value);
    if(index==size) {
        t = realloc(t, 2*size * sizeof(int));
        size*=2;
    }
    t[index] = new_value;
    index++;
}

int pop(int *t) {
    int number;

    if(index!=0)
	{
	    if(size/4>=index) {
            t = realloc(t, size/2 * sizeof(int));
            size/=2;
        }

	    number = t[index-1];
        t[index-1] = 0;
        index--;
	}
	else {
        number = NULL;
	}

    return number;
}

int main()
{
    int choice, number;
    int *tab = malloc(3* sizeof(int));

    do {
        printStack(tab);
        printf("Menu glowne stosu:\n");
        printf("1. Push (dodaje element na szczyt stosu)\n");
        printf("2. Pop (usuwa element na szczyt stosu)\n");
        printf("3. Koniec programu\n");
        printf("Wybor: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                system("cls");
                push(tab);
                break;
            case 2:
                system("cls");
                number = pop(tab);
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

    free(tab);

    return 0;
}
