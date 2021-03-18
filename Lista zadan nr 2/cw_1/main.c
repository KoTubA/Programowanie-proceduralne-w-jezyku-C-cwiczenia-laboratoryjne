#include <stdio.h>
#include <stdlib.h>

int power(int base, int exponent);

int main()
{

    printf("%d", power(3,4));

    return 0;
}


int power(int base, int exponent) {
    if(exponent==1)
        return base;

    return base * power(base,exponent-1);
}
