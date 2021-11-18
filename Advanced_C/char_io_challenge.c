/**
 * Challenge 1: write a program that reads data from a file or stdin and counts the words and characters and returns to stdout
 * 
 * if one argument is passed to the program than read from a file named the argument
 * if no argument is passed read from stdin
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void countWordsAndChars(FILE *stream, int *pWordCount, int *pCharCount);

int main(int argc, char *argv[])
{
    char *fileName = NULL;
    FILE *pFile = NULL;
    int charCount = 0;
    int wordCount = 0;

    // Force the args for debugging
    // argc = 2;
    // argv[1] = "testfile.txt";

    // Get stream from filename arg
    if (argc > 1)
    {
        fileName = (char *)calloc(strlen(argv[1]), sizeof(char));
        if (!fileName)
        {  
            printf("Error allocating memory\n");
            exit(1);
        }
        sscanf(argv[1], "%s", fileName);
        pFile = fopen(fileName, "r");
        if (!pFile)
        {
            printf("Error opening file: %s\n", fileName);
            exit(2);
        }

        countWordsAndChars(pFile, &wordCount, &charCount);
        printf("\nFilename: %s\nChar Count: %d\nWord Count: %d", fileName, charCount, wordCount);
    }
    else 
    {
        printf("Give me some good text baby!\nType ctl+d to signal EOF\n");
        countWordsAndChars(stdin, &wordCount, &charCount);
        printf("\nChar Count: %d\nWord Count: %d", charCount, wordCount);
    }



    // cleanup
    free(fileName);

    if (pFile)
    {
        fclose(pFile);
        pFile = NULL;
    }
    printf("\n");
    return 0;
}

void countWordsAndChars(FILE *stream, int *pWordCount, int *pCharCount)
{
    printf("Reading file or stdin:...\n");
    int ch = getc(stream);
    while (ch != EOF)
    {
        // printf("%c", ch);
        if (!isspace(ch) && ch != '\n')
        {
            *pCharCount += 1;
        }
        else 
        {
            *pWordCount += 1;
        }
        ch = getc(stream);
    }
    // It wont have the opportunity to evaluate the final word
    if (ch > 0 && ch == EOF && *pCharCount > 0) 
    {
        *pWordCount += 1;
    }
    printf("\n");
}