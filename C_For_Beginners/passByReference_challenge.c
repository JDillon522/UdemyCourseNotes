#include <stdio.h>

void square(int * val);

int main()
{
    int a = 3;
    int * pA = &a;
    square(pA);
    square(pA);
    printf("3 squared is %d\n", a);
    return 0;
}

void square(int * val)
{
    *val *= *val;
}