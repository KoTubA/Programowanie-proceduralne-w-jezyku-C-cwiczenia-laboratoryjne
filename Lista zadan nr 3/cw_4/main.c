#include <stdio.h>
#include <string.h>

void trim(char str[]) {
    int a = strlen(str);

    for (int i = 0; i < a; i++) {
        if(str[i]==' ') {
            int j = i;
            while(j<a-1) {
                str[j]=str[j+1];
                j++;
            }
            str[j] = '\0';
            a--;
        }
    }
    printf("%s", str);
}

int main(void){

    char tab[]= "Siema elo piona";
    trim(tab);

    return 0;
}
