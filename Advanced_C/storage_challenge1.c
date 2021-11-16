/**
 * write a small program that declares:
 * - an int var with block scope and temp storage
 * - a global double var that is only accessible inside this file
 * - a global float var that is accessable within the entire program
 * - a float local var with perm storage
 * - a function that is only accessible within the file it is defined 
*/

#include <stdio.h>

double onlyHere = 7.5;
extern float everywhere;

static void onlyHereFunc()
{
    printf("Foo");
};

int main()
{
    everywhere = 22.f;

    static float persist = 5.4;

    {
        int temp = 5;
    }
}

