#include <stdlib.h>
#include <stdio.h>
//#include "q1BinaryTree.h"

#define isAcceptedChar(c) (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')) || (c == ' ' || c == '\n' || c == '\t' || c == '_'))

int main(int argc, char *argv[])
{
    FILE *f = fopen("file.txt", "r");
    char character = 'a';
    char *word = malloc(255 * sizeof(char));

    while (isAcceptedChar(character))
    {
        character = (char)fgetc(f);
        printf("current character %c \n", character);
        //fgetc will interpret \n as EOF in windows
    }
    // fgets(word, 254, f);

    // printf(word);

    free(word);
    fclose(f);
}