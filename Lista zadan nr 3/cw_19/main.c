#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[50];
    
    printf("Podaj nazwe pliku z rozszerzeniem: \n");
    scanf("%s", name);
    
    FILE* fp;
    fp = fopen(name, "r");

    if(fp==NULL) {
        printf("Plik nie zostal otwarty!");
        return 1;
    }

    long int size=-1;
    fseek (fp, 0, SEEK_END);
    size = ftell(fp)+1;
    rewind(fp);
    
    long int size_part1;
    printf("Podaj rozmiar pierwszej czesci: \n");
    scanf("%ld", &size_part1);
    
    if(size_part1>size) {
        printf("Podana wartosc jest wieksza niz rozmiar pliku!");
        return 1;
    }
    
    long int size_part2 = size - size_part1 + 1;
    
    FILE* fp1;
    FILE* fp2;
    char part1[size_part1+1];
    char part2[size_part2+1];
    
    fgets(part1, size_part1, fp);
    fp1 = fopen("part1.txt", "w");
    fprintf(fp1, part1);
    
    fgets(part2, size_part2, fp);
    fp2 = fopen("part2.txt", "w");
    fprintf(fp2, part2);

    
    
    fclose(fp);
    fclose(fp1);
    fclose(fp2);

    return 0;
}
