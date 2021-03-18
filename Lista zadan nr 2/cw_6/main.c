#include <stdio.h>
int f (int a, int b);

int main (void){
    printf ("Podaj dwie cakowite liczby dodatnie: ");
    int x ;
    int y ;
    scanf("%d %d" ,&x ,&y );

    printf("Wynik to %d\n", f(x, y));

    return 0;
}

//parametr b musi byc dodatni,
//aby uniknac rekurencji nieskonczonej
int f(int a, int b){
    if(b < 0) return -f(a,-b);
    if(b==1) return a;
    else return a + f(a,b-1);
}
