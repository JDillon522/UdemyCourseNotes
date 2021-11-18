/**
 * Char Functions
 * 
 * putc() - write a single char to a file or stdout
 * putchar() - only write to stdout
 * fputc()
*/

#include <stdio.h>


int main()
{
    // putc() EXAMPLE
    // int ch;
    // FILE *pFile = NULL;

    // pFile = fopen("somefile.txt", "rw");
    // if (pFile) 
    // {
    //     ch = getc(pFile);
    //     while (ch != EOF)
    //     {
    //         putc(ch, stdout); // dump the content of the file to stdout. Could also use a file
    //         ch = getc(pFile);
    //     }
    // }

    // putchar() EXAMPLE
    char string[] = "Heres a string to \ndump to stout";
    int i = 0;
    while (string[i] != '\0')
    {
        if (string[i] != '\n') 
        {
            putchar(string[i]);
        }
        i++;
    }

    printf("\n");
    return 0;
}