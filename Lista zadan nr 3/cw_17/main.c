#include <stdio.h>
#include <string.h>

#define MAX_LEN 256

int main(void)
{
    FILE* fp;
    fp = fopen("text.txt", "r");

    if(fp==NULL) {
        printf("Plik nie zostal otwarty!");
        return 1;
    }

    char buffer[MAX_LEN];
    char korektor[]= " ";
    int counter = 0;

    while (fgets(buffer, MAX_LEN - 1, fp))
    {
        char *schowek = strtok(buffer, korektor);

        while(schowek != NULL)
        {
            counter++;
            schowek = strtok( NULL, korektor );
        }
    }

    printf("Ilosc slow w pliku to: %d", counter);

    fclose(fp);
    return 0;
}
