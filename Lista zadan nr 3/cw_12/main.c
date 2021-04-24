#include <stdio.h>
#include <string.h>

void reverseTokens( char *sentence)
  {
     char *pointers[50], *temp;
     int count = 0, i;

     temp=strtok(sentence, " ");

     while ( temp ) {
        pointers[ count++ ] = temp;
        temp = strtok( NULL, " " );
     }

     printf("\nOwdrocona kolejnosc:\n" );

     for ( i = count - 1; i >= 0; i-- )
        printf("%s ", pointers[ i ] );
  }

int main()
{
    char text[80];

    printf("Wpisz przykladowe zdanie:\n" );
    gets( text );
    reverseTokens( text );

 return 0;
}

