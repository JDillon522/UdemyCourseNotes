#include <stdio.h>
#include <stdbool.h>

int greatestCommonDivisor(int a, int b);
int absoluteValue(int val);
int squareRoot(int val);

int main()
{
    int gcd = greatestCommonDivisor(462, 1071);
    printf("%d\n\n", gcd);

    // int abs1 = absoluteValue(15);
    // int abs2 = absoluteValue(-5);
    // printf("%d %d\n\n", abs1, abs2);
    return 0;
}

int greatestCommonDivisor(int a, int b)
{
    if (b > a) 
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    // Euclidean Algorithm
    int c = a % b;

    if (c != 0)
    {
        return greatestCommonDivisor(b, c);
    }

    return b;
}

int absoluteValue(int val)
{
    if (val >= 0)
    {
        return val;
    }

    return -val;
}

int squareRoot(int val) 
{
    int primes[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

    // Prime factorization

}