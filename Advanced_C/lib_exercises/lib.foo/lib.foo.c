#include <stdio.h>

void fun(void)
{
    printf("fun() was called in the static lib");
}

void funDynamic(void)
{
    printf("fun() was called in the dynamic lib");
}