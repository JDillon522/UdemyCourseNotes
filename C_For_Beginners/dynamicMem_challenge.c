#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int bytes = 0;
    printf("How many characters are in your name?\n");
    scanf("%d", &bytes);

    char * pStr = NULL; // initialize
    pStr = (char *)calloc(bytes, sizeof(char));
    if (!pStr)
    {
        return 1;
    }
    
    printf("What silly sentance would you like to input?\n");
    
    scanf("%s", pStr);
    printf("\n");
    // fflush(stdin);
    // if (fgets(pStr, 10, stdin))
    // {
        printf("You entered:\n%s\n\n", pStr);

    // };


    free(pStr);
    return 0;
}