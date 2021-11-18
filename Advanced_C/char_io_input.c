#include <stdio.h>
#include <ctype.h>

int main()
{
    /**
     * Char Functions
     * 
     * getc() - reads a single char at a time from a file stream. 
     *          Returns an int that can be easially converted to ascii char. Also returns EOF
     * getchar() - ONLY reads from stdin. requires no args and returns just like getc()
     * fgetc() - reads a char from a file. Moves a file pointer location to the next char
     * ungetc() - replaces a char from a stream with a different character
     * putc()
     * putchar()
     * fputc()
    */
    
    char ch = '\0'; // or NULL
    FILE *pFile = NULL;
    pFile = fopen("somefile.txt", "rw");

    // getc() EXAMPLE

    if (pFile) 
    {
        ch = getc(pFile);
        while (ch != EOF)
        {
            ch = getc(pFile);
        }
        fclose(pFile);
    }
    // or using stdin
    ch = getc(stdin); // stdin is technecially just a FILE pointer

    // getchar() EXAMPLE
    printf("type something\n");
    // essentially does the same as scanf without formatting. Only gets a single char at a time
    printf("getchar() %c\n", getchar());
    
    int chInt; // store it in an int because char can be unpredictable with getchar
    while ((chInt = getchar()) != EOF) // ctl+d/c will trigger EOF
    {
        // If you typed a multi char string on the first input then the stream is still active and will be picked up here
        printf("%c", chInt); 
    }

    // fgetc() EXAMPLE
    char fgetC = '\0';
    while (1) // infinate loop
    {
        fgetC = fgetc(pFile);

        if (fgetC == EOF)
        {
            break; // kill the loop
        }

        printf("%c", fgetC);
    }

    // ungetc() EXAMPLE
    printf("Type something with a few leading spaces\n");
    // Function that ignores spaces and tabs from the input stream
    while (isspace(chInt = (char)getchar()));
    ungetc(chInt, stdin);

    printf("char is %c\n\n", getchar());
    



    return 0;
}