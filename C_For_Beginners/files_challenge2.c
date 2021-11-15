#include <stdio.h>
#include <ctype.h>

int main()
{
    // Convert lowercase letters in a file to upper case by
    // writing them to a new file, removing the original, then renaming the temp
    int ch;
    char *pFileName = "testFile.txt";
    char *pNewFileName = "tempFile.txt";
    FILE *pReadFile = NULL;
    FILE *pNewFile = NULL;

    pReadFile = fopen(pFileName, "r");
    if (!pReadFile) 
    {
        printf("Error opening up %s", pFileName);
        return 1;
    }

    pNewFile = fopen(pNewFileName, "w");
    if (!pNewFile)
    { 
        printf("Error opening up %s", pNewFileName);
        return 2;
    }

    printf("Reading and uppercasing file contents...\nOld content:\n");
    
    while ((ch = fgetc(pReadFile)) != EOF)
    {
        printf("%c", ch);
        if (ch >= 'a' && ch <= 'z') 
        {
            ch -= 32;
        }
        fputc(ch, pNewFile);
    }
    printf("\n");

    fclose(pReadFile);
    pReadFile = NULL;
    fclose(pNewFile);
    pNewFile = NULL;

    remove(pFileName);
    rename(pNewFileName, pFileName);

    pReadFile = fopen(pFileName, "r");
    if (!pReadFile)
    { 
        printf("Error opening up %s", pFileName);
        return 3;
    }

    printf("New contents: \n");
    while ((ch = fgetc(pReadFile)) != EOF)
    {
        printf("%c", ch);
    }

    printf("\n");
    return 0;
}