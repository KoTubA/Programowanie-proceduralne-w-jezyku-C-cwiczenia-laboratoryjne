#include <stdio.h>
int A(int m, int n);

int main (void){

    A(1,1);

    return 0;
}

int A(int m, int n) {
    printf("m: %d, n: %d\n", m, n);
    if(m==0) return n+1;
    else if(m>0 && n==0) return A(m-1,1);
    else if(m>0 && n>0) return A(m-1, A(m,n-1));
}
