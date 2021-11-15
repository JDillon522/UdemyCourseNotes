#include <stdio.h>


int main()
{
    int c;
    char fileContents[60];
    int firstArg;
    float secondArg;
    char thirdArg[20];

    FILE *pFile = NULL;
    char *fileName = "testFile.txt";
    pFile = fopen(fileName, "r");


    if (!pFile) 
    {
        printf("Failed to open %s\n", fileName);
        return -1;
    } 
    else 
    {
        printf("Opened %s successfuly\n", fileName);
    }

    // Read individual chars
    printf("Reading with fgetc()\n");
    while ((c = fgetc(pFile)) != EOF)
    {
        printf("%c", c);
    }
    printf("\n");

    rewind(pFile);

    // Read the whole contents of the file
    printf("Readint with fgets()\n");
    if (fgets(fileContents, 20, pFile) != NULL)
    {
        printf("Contents of file: %s\n", fileContents);
    }
    else 
    {
        printf("The rest of the contents? %s\n", fileContents);
    }

    rewind(pFile);

    // Read formatted data
    fscanf(pFile, "%d %f %s", &firstArg, &secondArg, thirdArg);

    printf("First: %d\nSecond: %f\nThird: %s\n", firstArg, secondArg, thirdArg);

    if (fclose(pFile) != 0)
    {
        printf("Could not close %s\n", fileName);
        return -1;
    } 
    else 
    {
        printf("Closed %s successfuly\n", fileName);
    };

    pFile = NULL;
    printf("\n\n");
    return 0;
}