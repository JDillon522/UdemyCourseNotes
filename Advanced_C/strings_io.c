/** 
 * String Functions
 * 
 * gets() - get string and reads a line from stdin. reads until \n or EOF
 *          takes one arg - a pointer to a char[]. return string or null on error
 *          NEVER USE THIS. DEPRECATED. UNSAFE
 * fgets() - read entire lines of data from a file/stream
 *           same as gets() with two additional args - the max num of chars to read (including final null char), and input stream
 *           retains newlines. possible to read a partial line since it will truncate up to max len
 *           Low performant. DEPRECATED. Cannot tell if a null char is included in the string it reads
 *           Only use fgets() if you are positive the data read cannot contain a null character
 * getline() - USE THIS ONE. Preferrd method for reading lines of text. Reads up to and including the next \n
 *             Same params as fgets() except the first arg is a double pointer. Automatically resizes the block of memory
 *             as needed and thats why it needs a double pointer. Does not include the final null character. 
 * 
 * puts() - write a line to the screen/stdout just like printf(). Automatically appends a newline. Automatically formatted as a string. 
 *          not that flexible since it doesnt allow formatting or vars.
 * fputs() - similar to puts() but accepts a second param of a stream. does not append a newline
 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    
    // fgets() EXEAMPLE
    // char buffer[255];
    // int ch = '\0';
    // char *p = NULL;

    // if (fgets(buffer, sizeof(buffer), stdin))
    // {   
    //     // this will discard any data after a line feed
    //     p = strchr(buffer, '\n'); // looks to see if theres a new line and moves the pointer to the first occurance;
    //     if (p)
    //     {
    //         *p = '\0'; // add a null char after the \n
    //     }
    //     else 
    //     {
    //         while (
    //             ((ch = getchar()) != '\n') && // read each char 
    //             !feof(stdin) && // until the end of stdin ie: Function End Of(stream)
    //             !ferror(stdin) // or until theres errs
    //         );
    //     }
    // }

    // getline() EXAMPLE
    // read a line of text from stdin safely

    // if you wanted to allocate mem
    char *buffer2 = NULL;
    size_t buffSize = 32; // initial size. getline will resize if needed. must be a pointer
    size_t characters;

    buffer2 = (char *)calloc(buffSize, sizeof(char));
    if (!buffer2)
    {
        exit(1);
    }

    printf("Type something: ");
    characters = getline(&buffer2, &buffSize, stdin);
    // !!!
    buffer2[characters - 1] = '\0'; // Proper way to clear the newline added by getline()
    // end !!!
    
    printf("%zu characters were read.\n", characters);
    // (*buffer2)[(int *)characters - 1] = '\0';
    printf("You typed: '%s'\n", buffer2);

    // if you dont want to allocate memory
    char buffer3[buffSize];
    char *b3 = buffer3;
    
    printf("Type something else: ");
    characters = getline(&b3, &buffSize, stdin);

    buffer3[characters - 1] = '\0'; // Same as above. Woot
    printf("%zu characters were read\n", characters);
    printf("You typed: '%s'\n", buffer3);

    free(buffer2);

    printf("\n");
    return 0;
}