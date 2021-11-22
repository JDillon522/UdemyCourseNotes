/**
 * Function Pointers
 * 
 * A function returning a pointer:
 * int *func(int a, float b);
 * 
 * A pointer to a function:
 * int (*func)(int a, float b);
 * 
 * 
 * Common Usages
 * - passing a function as an argument to another function
 * --- Like a callback!
 * --- exe: the qsort() func will sort any array, but you pass a function pointer that is used to compare each element
 * - create dispatch tables
 * --- ie: a list of functions that a user can call based on input
 * - menu driven systems
 * - replace switch/if statements
 * 
 * Delcaration
 * int(*pFunction)(int);
 *  |_rtn val  |    |_arg
 *             |_defrence
 * 
 * int lookup(int);
 * int (*pLookup)(int);
 * pLookup = &lookup;
 * 
*/

#include <stdio.h>
#include <stdlib.h>

int someDisplay();
int func1(int);
int func2(int);

typedef void VoidWithInt(int);

int main()
{
    int (*pSomeDisplay)();
    pSomeDisplay = someDisplay;

    printf("Address of the func pointer %p\n", pSomeDisplay);

    pSomeDisplay();

    VoidWithInt *pFunc1 = NULL;
    pFunc1 = func1;
    printf("Address of func 1 %p\n", pFunc1);

    pFunc1(100);
    pFunc1 = func2;
    printf("Address of func 1 again %p\n", pFunc1);
    
    pFunc1(200);

    pFunc1 = func1;
    printf("Address of func 1 final %p\n", pFunc1);


    return 0;
}

int someDisplay()
{
    printf("Displaying something\n");
}

int func1(int num)
{
    printf("Your Func 1 val %d\n", num);
}

int func2(int num)
{
    printf("Your Func 2 val %d\n", num);
}