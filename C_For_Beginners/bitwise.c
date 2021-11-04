#include <stdio.h>

int main()
{
    unsigned int a = 60; //  0011 1100
    unsigned int b = 13; //  0000 1101
    int result = 0;

    // If BOTH bits are 1, then it stays 1. Otherwise its 0
    int and = a & b; // 0000 1100 = 12
    printf("60 AND 13 = %d\n", and);
    
    // If EITHER bit is 1, it stays 1. Otherwise zero
    int or = a | b; // 0011 0001 = 61
    printf("60 OR 13 = %d\n", or);
    
    // If ONLY one bit is 1 then its a 1. Else, 0
    int exclusiveOR = a ^ b; // 0011 0001 = 49
    printf("60 Exclusive OR 13 = %d\n", exclusiveOR);

    // On a complemnt all the 1s become 0s and vis versa.
    int complementA = ~a; // 0011 1100 becomes 1100 0011 -61
    int complementB = ~b; // -14
    printf("Complement A = %d\n", complementA); 
    printf("Complement B = %d\n", complementB);

    int shiftRight = a >> 2; // 0011 1100 should be 0000 1111 = 15
    printf("Shirft 60 right 2 = %d\n", shiftRight);
    int shiftLeft = a << 2; // 0011 1100 should be 1111 0000 = 240
    printf("Shirft 60 left 2 = %d\n", shiftLeft);
    return 0;
}