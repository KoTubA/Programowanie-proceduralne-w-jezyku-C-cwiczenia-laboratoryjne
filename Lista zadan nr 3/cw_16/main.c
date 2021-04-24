#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 256

void count_letter(char c_buffer[], int c_count[] ) {
    int size = strlen(c_buffer);
    for (int i = 0; i < size; i++) {
        c_count[tolower(c_buffer[i])] += 1;
    }
}

int main() {

    char buffer[MAX_LEN];
    int count[MAX_LEN] = { 0 };
    int n;
    const char *s = "abcdefghijklmnopqrstuvwxyz";

    FILE *fp = fopen("text.txt","r");

    if(fp==NULL) {
        printf("Plik nie zostal otwarty!");
        return 1;
    }

    while (fgets(buffer, MAX_LEN - 1, fp)){
        count_letter(buffer, count);
    }

    printf("Zank\tIlosc\n");

    int len = strlen(s);
    for (int j = 0; j<len; j++, s++) {
        printf("%c:\t%d\n", *s, count[*s]);
    }

    fclose(fp);

    return 0;
}
