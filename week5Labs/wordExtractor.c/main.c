#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char * removeSpacesFromStr(char *words)
{
    int non_space_count = 0;

    for (int i = 0; words[i] != '\0'; i++)
    {
        if (words[i] != ' ')
        {
            words[non_space_count] = words[i];
            non_space_count++;
        }
    }

    words[non_space_count] = '\0';
    return words;
}


int main() {
    char words[2000];
    printf("Enter your words seperated by commas:\n");

    fgets(words, 2000, stdin);

    *words = *removeSpacesFromStr(words);

    char * ptr = strtok(words, ",");

    while( ptr != NULL ) {
        printf( "%s\n", ptr ); 
        ptr = strtok(NULL, ",");
    }

    return 0;
}












