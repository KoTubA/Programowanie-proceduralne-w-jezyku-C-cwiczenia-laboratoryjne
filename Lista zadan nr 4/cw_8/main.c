#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    int suma = 0;
    printf("Liczby przekazane do zsumowania: ");
    for(int i = 1; i < argc; i++)
    {
        printf("%s, ", argv[i]);
        suma += atoi(argv[i]);
    }
    printf("\n");

    printf("Suma: %d", suma);

    return 0;
}