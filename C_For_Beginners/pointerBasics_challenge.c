#include <stdio.h>

int main()
{
    int num = 15;
    int * pNum = NULL;
    pNum = &num; // Somewhat redundant but apparently good practice

    printf("Address of pNum %p\n", (void *)&pNum);
    printf("Value of pNum %p\n", pNum);
    printf("Value of what pNum is pointing to %d\n\n", *pNum);
    return 0;
}