/**
 * Double Pointers
 * 
 * Use Cases:
 * when you need to change the value of the pointer passed to a function as the func arg. ie: change what the pointer points to
 * - if you pass a single pointer as an argument and change the pointer value, you will only be changing the local copy, 
 *   not the original pointer
 * when you want to preserve the memory-allocation or assignment even outside of the function
 * when you allocate or change memory for a pointer passed to a function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void foo(int *ptr)
{
    int a = 5;
    ptr = &a;
    printf("Foo ptr val: %d\n", *ptr);
};

void foo2(int **ptr)
{
    int a = 15;
    *ptr = &a;

    printf("Foo 2 ptr value: %d\n", **ptr);
}

void foo3(char *ptr)
{
    ptr = malloc(255); // random len
    strcpy(ptr, "Hello world");

    printf("Foo 3 ptr value: %s\n", ptr);
}

void foo4(char **ptr)
{
    *ptr = malloc(255); // random len
    strcpy(*ptr, "Hello world");

    printf("Foo 4 ptr value: %s\n", *ptr);
}

int main()
{
    // EXAMPLE 1
    // int a = 10;
    // int *p1 = NULL;
    // int **p2 = NULL;

    // p1 = &a;
    // p2 = &p1;

    // // Ignore warnings about using an unsigned int
    // printf("Address of A:  %u\n", &a);
    // printf("Address of p1: %u\n", &p1);
    // printf("Address of p2: %u\n\n", &p2);

    // printf("Value at address stored by p2 (*p2) = %u\n", *p2);
    // printf("Value at address stored by p1 (*p1) = %d\n", *p1);
    // printf("Value of **p2 = %d\n\n", **p2);
    

    // EXAMPLE 2
    int *ptr = NULL;
    ptr = (int *)malloc(sizeof(int));

    *ptr = 10;
    printf("Main ptr value %d\n", *ptr);
    foo(ptr);
    foo2(&ptr);
    printf("Main ptr value %d\n", *ptr);

    // EXAMPLE 3 : changing the memory of a ptr in a func
    char *pChar = NULL;
    foo3(pChar);

    printf("Char string val: %s\n", pChar);
    free(pChar); // it should crash with a seg fault but it doesnt

    foo4(&pChar);
    printf("Char string val: %s\n", pChar);

    free(pChar);
    return 0;
}

