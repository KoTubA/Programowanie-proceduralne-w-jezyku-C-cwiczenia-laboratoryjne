#include <stdio.h>

void hanoi(int n, char poczatkowy, char docelowy, char pomocniczy);

int main()
{
    hanoi(3,'A','C','B');

    return 0;
}

void hanoi(int n, char poczatkowy, char docelowy, char pomocniczy)
{

    if(n > 1) hanoi(n-1, poczatkowy, pomocniczy, docelowy);

    printf("%c --> %c\n", poczatkowy, docelowy);

    if(n > 1) hanoi(n-1,pomocniczy,docelowy,poczatkowy);


}
