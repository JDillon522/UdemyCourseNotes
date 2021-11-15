#include <stdio.h>

int main()
{
    FILE *pFile = NULL;
    int ch = 33;

    pFile = fopen("testFile.txt", "w+");

    // Write a single character at a time
    for (  ; ch <= 100; ch++)
    {
        fputc(ch, pFile);
    }
    // Insert a new line
    fputc(10, pFile);
    // rewind(pFile);

    // write a string to a file
    fputs("This is the first line\n", pFile);
    fputs("This is a second string\n", pFile);

    // Write formatted data
    fprintf(pFile, "%d %f %s\n", 10, 20.5, "String input"); 

    fclose(pFile);
    printf("\n\n");
    return 0;
}