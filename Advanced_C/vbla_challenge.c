#include <stdio.h>

int main()
{
    int arrLen;

    printf("How long of an array?\n");
    scanf("%d", &arrLen);

    int arr[arrLen];
    int count = 50;

    for (int i = 0; i < arrLen; i++)
    {
        arr[i] = count;
        count += count; 
    }

    for (int i = 0; i < arrLen; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
    
}