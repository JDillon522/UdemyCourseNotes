#include <stdio.h>

long long decToBinMath(int decimal);

int main()
{
    int a, b;

    printf("Give me two integers:\n");
    scanf("%d %d", &a, &b);

    printf("The result of applying the following operators on %d (%lld) and %d (%lld):\n", a, decToBinMath(a), b, decToBinMath(b));
    printf("The & operator: %d (%lld) \n", a & b, decToBinMath(a & b));
    printf("The | operator: %d (%lld)\n", a | b, decToBinMath(a | b));
    printf("The ^ operator: %d (%lld)\n", a ^ b, decToBinMath(a ^ b));
    printf("The ~ operator: on A: %d (%lld), B:%d (%lld)\n", ~a, decToBinMath(~a), ~b, decToBinMath(~b));
    printf("The << operator on A: %d moved by 2: %d (%lld)\n", a, a << 2, decToBinMath(a << 2));
    printf("The >> operator on A: %d moved by 2: %d (%lld)\n", a, a >> 2, decToBinMath(a >> 2));



    printf("\n\n");
    return 0;
}

long long decToBinMath(int decimal)
{
    long long binary = 0;
    int remainder, i = 1; // Start i at 1 because we need to be able to set the lest sig bit

    while (decimal != 0)
    {
        // Essentially the same as above but now accounting for base 2
        remainder = decimal % 2;
        decimal = decimal / 2;
        binary += remainder * i;
        i *= 10; // This will move i to the next bit location.
        // Mind = Blown
    }

    return binary;
}