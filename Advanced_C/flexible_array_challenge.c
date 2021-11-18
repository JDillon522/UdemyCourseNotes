/**
 * write a program that uses a flexible array member inside a structure
 * - struct myArray with member array
 * - read in from the user the size at runtime
 * - allocate memory based on size from the user
 * - fill it with dummy data
 * - print out dummy data
*/

#include <stdlib.h>
#include <stdio.h>

struct myArray {
    int arrSize;
    int array[];
};

int main()
{   
    int size;
    struct myArray *arr;

    printf("Enter the size\n");
    scanf("%d", &size);

    arr = calloc(sizeof(struct myArray) + size, sizeof(int));
    arr->arrSize = size;

    int counter = 50;

    for (int i = 0; i < size; i++)
    {
        arr->array[i] = counter;
        counter += counter;
    }
    
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr->array[i]);
    }
    
    printf("\n");
    return 0;
}