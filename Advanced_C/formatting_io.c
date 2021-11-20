

/** 
 * Formatting Functions
 * 
 * sprintf() - "string print formatted". allows you to format a string like printf() but it doesnt output to stdout
 *              It returns a char buffer. UNSAFE because it doesnt check the len of the destination buffer.
 * fprintf() - same as printf() but on a file
 * fflush()
 * fscanf()
 * sscanf()
*/
#include <stdio.h>


int main()
{
    int a = 10;
    char b[] = "some string";
    char str[100];
    sprintf(str, "Here is something %d and %s\n\n", a, b);

    printf("%s", str);

    return 0;
}