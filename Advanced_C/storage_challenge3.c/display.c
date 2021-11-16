#include <stdio.h>

void display()
{
    extern int counter;
    printf("Counter: %d\n", counter);
}