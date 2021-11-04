#include <stdio.h>

int main()
{
    float a = 21.51;
    float b = 26.99;
    int c = (int) a + (int) b;

    printf("Casting %f + %f to int %d\n", a, b, c);
    printf("Size of:\nint = %ld\nfloat = %ld\ndouble = %ld\n", sizeof(int), sizeof(float), sizeof(double));

    return 0;
}