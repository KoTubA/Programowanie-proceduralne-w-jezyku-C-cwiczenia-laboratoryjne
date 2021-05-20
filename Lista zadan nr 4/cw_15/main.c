#include <stdio.h>
#include <stdlib.h>

void f1()
{
    printf("FUNKCJA 1\n\n");
}

void f2()
{
    printf("FUNKCJA 2\n\n");
}

void f3()
{
    printf("FUNKCJA 3\n\n");
}

void f4()
{
    printf("FUNKCJA 4\n\n");
}

int main()
{
    void (*(wsk[4]))();

    wsk[0] = f1;
    wsk[1] = f2;
    wsk[2] = f3;
    wsk[3] = f4;

    int option = 1;

    while (option != 0)
    {
        printf("MENU:\n");
        printf("1) WYKONAJ FUNKCJE 1\n");
        printf("2) WYKONAJ FUNKCJE 2\n");
        printf("3) WYKONAJ FUNKCJE 3\n");
        printf("4) WYKONAJ FUNKCJE 4\n");
        printf("0) KONIEC\n");

        printf("WYBIERZ OPCJE: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            system("cls");
            wsk[0]();
            break;
        case 2:
            system("cls");
            wsk[1]();
            break;
        case 3:
            system("cls");
            wsk[2]();
            break;
        case 4:
            system("cls");
            wsk[3]();
            break;

        case 0:
            system("cls");
            printf("Koniec\n");
            break;
        default:
            system("cls");
            printf("Wybierz poprawna opcje!\n");
            break;
        }
    }
    return 0;
}
