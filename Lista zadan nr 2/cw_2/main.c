#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y);

int main()
{

    printf("%d", gcd(36, 128));

    return 0;
}


int gcd(int x, int y) {
    if(x==0)
        return y;

    return gcd(y%x,x);
}
