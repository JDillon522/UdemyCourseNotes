/**
 * Variadic Functions - functions with a variable number of arguments
 * - Must have at least one mandatory args and then optional 
 * - common practice is to have the num of args as the first arg
 * 
 * stdarg.h
 * - va_list - used when we need to access option parameters. used to a data object used to hold the 
 *             parameters corresponding to the ellipsis part of the param list
 * - va_start - will connect our arg list with some argument pointer. 
 * - va_arg - will fetch the current arg connected to the arg list
 * - va_end - when we would like to stop using a var arg list (for cleanup)
 * - va_copy - used when we want to save our location
*/

#include <stdio.h>
#include <stdarg.h>

// step 1: signature
void f1(int n, ...); // single mandatory arg
void f2(int n, char c, ...);

// step 2: implement
void f1(int n,...)
{
    va_list pArgList; // pointer for variable arg list
    //...
    va_start(pArgList, n); // start at the last mandatory arg. would be c in f2
    //...


    va_end(pArgList); // Cleanup
}

// EXAMPLE
double average(double v1, double v2, ...);

int main()
{
    double v1 = 10.5, v2 = 12.32;
    int num1 = 4, num2 = 31;
    long num3 = 12L, num4 = 456L;

    printf("Average: %.2lf\n", average(v1, v2));
    printf("Average: %.2lf\n", average(v1, v2, (double)num1, (double)num4, (double)2, (double)29, (double)22.4));
    printf("Average: %.2lf\n", average(v1, v2, (double)num1, (double)num2, (double)num3, (double)num4));
    printf("Average: %.2lf\n", average((double)5, (double)190L, (double)0.4));
}

double average(double v1, double v2, ...)
{
    va_list pArgList;       // point for arg list
    
    // in case we needed to run through the args again we can make a copy
    va_list pArgListCopy;
    va_copy(pArgListCopy, pArgList);
    // /end copy. You can now extract args from the copy independent of the main

    double sum = v1 + v2;
    double value = 0.0;     // argument value

    int count = 2;          // count of arguments
    va_start(pArgList, v2); // initialize argument pointer

    /**
     * va_arg(pArgList,       double)
     *         |_the pointer  |
     *                        |_the type of argument you expect to see
     * after being called it will update the pArgList pointer to point to the next argument
    */
    while ((value = va_arg(pArgList, double)) != 0.0) // assign to value the current arg. Assumes a non zero arg
    {
        sum += value;
        ++count;
    }

    va_end(pArgList);   // end variable assignment. if omitted program may not perform properly
    va_end(pArgListCopy); // do not reassign to the copy pointer until va_end is called

    return sum/count;
}