/**
 * write a program that find the sum of various nums
 * - you cannot pass any var representing the running total to the sum() func
 * - exe:
 * 
 * int sum(int sum) {
 *  ...
 * } 
 * 
 * sum(25);
 * sum(15);
 * sum(30);
 * 
 * output: 25 40 70
 * it must add the previous sum to the new arg
*/

#include <stdio.h>

static int sum(int val)
{
    static int total = 0;
    total += val;
    return total;
}

int main()
{
    printf("Sum: %d\n", sum(25));
    printf("Sum: %d\n", sum(15));
    printf("Sum: %d\n", sum(30));

    return 0;
}