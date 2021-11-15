#include <stdio.h>

// Count how many lines a file has
int main()
{
    FILE *pFile = NULL;
    char *fileName = "testFile.txt";
    pFile = fopen(fileName, "r");
    int lineCount = 1;
    int ch;

    if (!pFile) 
    {
        printf("Failed to open %s\n", fileName);
        return -1;
    } 
    else 
    {
        printf("Opened %s successfuly\n", fileName);
    }

    while ((ch = fgetc(pFile)) != EOF)
    {
        // increment if the char == 10, which is the code for newline
        // or just compare the string constant
        if (ch == '\n') 
        {
            lineCount++;
        }
    }

    fclose(pFile);
    pFile = NULL; // close it out

    printf("The file \"%s\" has %d lines\n", fileName, lineCount);
    printf("\n\n");
    return 0;
}