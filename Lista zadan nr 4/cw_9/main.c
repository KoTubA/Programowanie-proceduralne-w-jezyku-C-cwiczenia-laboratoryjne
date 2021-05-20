#include <stdio.h>

int atoi(const char *str);

int main()
{
    int num = atoi("2312321");

    printf("%d", num);
    return 0;
}

int atoi(const char *str)
{
    int liczba = 0;
    int i = 0;
    if (str[0] == '-')
    {
        i++;
    }

    while (str[i] != '\0')
    {
        liczba = liczba * 10 + str[i] - '0';
        i++;
    }

    if (str[0] == '-')
    {
        liczba *= -1;
    }

    return liczba;
}
