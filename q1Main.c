#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "q1BinaryTree.c"

#define isAcceptedChar(c) (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')) || (c == ' ' || c == '\n' || c == '\t' || c == '_'))
#define MAX_LINE_SIZE 255

int main(int argc, char *argv[])
{
    // open file and initialise variables
    FILE *f = fopen("file.txt", "r");
    char *word = malloc(255 * sizeof(char));
    char *line = malloc(MAX_LINE_SIZE * sizeof(char));

    while (fgets(line, MAX_LINE_SIZE, f))
    {
        // check if line is accepted
        int i = 0;
        int len = strlen(line);
        int wordLen = 0;
        for (i = 0; i < len; i++)
        {
            if (line[i] == ' ' || line[i] == '\n')
            {
                // if space or new line, new word
                // word last char = \0, to mark ond of string
                word[wordLen] = '\0';
                // add word to tree
                insertNode(word);
                wordLen = 0;
            }
            if (isAcceptedChar(line[i]))
            {
                // if not ilegal character, add to word
                word[wordLen] = line[i];
                wordLen++;
            }
        }
    }

    printAlphabeticalOrder();

    free(line);
    free(word);
    fclose(f);
}