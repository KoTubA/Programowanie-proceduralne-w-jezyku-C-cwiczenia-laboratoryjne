#include <stdio.h>
int main(void)
{
    int c;

    //wpisz ci�g tekstowy i wprowad� Ctrl + Z
    if((c = getchar()) != EOF )
    {
        main();
        printf("%c" , c);
    }

    return 0;
}
