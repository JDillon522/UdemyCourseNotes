#include <stdio.h>

// Print the contents of a file in reverse order
int main()
{
    int ch;
    char *pFileName = "testFile.txt";
    FILE *pFile = NULL;
    long fPosition;

    pFile = fopen(pFileName, "r");
    if (!pFile) 
    {
        printf("Error opening %s", pFileName);
        return 1;
    }

    // use fseek to seek to the end of the file
    // fseek only moves the file pointer to the end
    fseek(pFile, 0, SEEK_END);

    // use ftell to get the position of the file pointer
    // ftell gets the current position of the pointer
    fPosition = ftell(pFile);

    // display output in reverse order
    // start at 1 because its the offset. Otherwise it'll try to output the EOF
    for (int i = 1; i < fPosition; i++)
    {
        // move the pointer to a negative offset based on the end of the file
        fseek(pFile, -i, SEEK_END);
        ch = fgetc(pFile);
        printf("%c", ch);
    }
    
    fclose(pFile);
    pFile = NULL;

    printf("\n");
    return 0;
}