#include <stdio.h>
#include <string.h>

void reverse(char str[]) {
    int a = strlen(str);

    for (int i = 0; i <= a; i++, a--) {
        char c = str[i];
        str[i] = str[a - 1];
        str[a - 1] = c;
    }

    printf("%s", str);
}

int main(void){

    char tab[]= "Siema";
    reverse(tab);

    return 0;
}
