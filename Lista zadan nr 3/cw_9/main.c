#include <stdio.h>
#include <string.h>
#include <time.h>

void random_sentences(char **tab1, char **tab2, char **tab3, char **tab4)
{
    char text[1000];

    srand(time(NULL));

    for(int i=0; i<20; i++) {
        strcat(text, tab1[rand()%6]);
        strcat(text, " ");
        strcat(text, tab2[rand()%9]);
        strcat(text, " ");
        strcat(text, tab3[rand()%9]);
        strcat(text, " ");
        strcat(text, tab4[rand()%9]);
        strcat(text, ". ");
    }

    printf("%s", text);
}

int main(void){
    char *article[] = {"Ten", "Ta", "To", "Tego","Tej","Temu"};
    char *noun[] = {"chlopak", "dziewczyna", "pies", "miasto", "samochod", "robotnik", "mezczyzna", "kobieta", "kot"};
    char *verb[] = {"prowadzil", "skoczyl", "uciekl", "szedl","przeskoczyl","wyszedl", "poszedl", "zapukal","zadzwonil"};
    char *preposition[] = {"do", "z", "na", "nad", "pod", "na", "obok", "przy", "za"};

    random_sentences(article, noun, verb, preposition);

    return 0;
}
