#include <stdio.h>
int main(void)
{
    int c;

    //wpisz ciπg tekstowy i wprowadü Ctrl + Z
    if((c = getchar()) != EOF )
    {
        main();
        printf("%c" , c);
    }

    return 0;
}
