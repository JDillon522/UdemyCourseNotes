
/**
 * Pragma. Allows you to turn on features of the compiler (or other systems?)
 * 
 * pragma GCC dependency - allows you to check the relative dates of the current file and another file. 
 *                         if the other file is more recent a worning is issued
 *                         usefule if the current file is derived from a previous and you need to update
 * 
 * pragma GCC poision <identifer> - remove an identifier remove it completly. 
 *                      exe: pragma GCC poision printf <-- this will throw an error any time printf is used
 *                      probably useful to prevent deprecated functions
 * 
 * pragma GCC system_header - tells the compiler to consider the rest of the current file as a system header
 *                            code that comes before the #pragma is not affected. Takes no args
 *                            systems headers are files that come with the OS or compiler
 *                            as a system header warnings are supporessed
 * 
 * pragma once - specifies the header file containing this directive is included only once even if the 
 *               programmer includes it multiple times
 * 
 * pragma GCC warning/error <message> - prints the relevent message when compiled
 * pragma message <message> - same as previous
 * 
 * #error <message without quotes> - good for thowing errors but it wont prevent the compiler from compiling. 
 *                                   like throwing an error message if its the wrong compiler. Or if code is 
 *                                   incomplete and you wanted to let others know
 * 
 * 
 * PREDEFINED MACROS
 * 
 * __FILE__ - represents the current file name and path (string)
 * 
 * __LINE__ - the current line umber of the current source code (int const)
 * 
 * __func__ - the name of any function when placed inside a function of the current file. Not part of the standard
 * 
 * __DATE__ - the date the source file was compiled ("Mmm dd yyy" "Jan 19 2002")
 * 
 * __TIME__ - the time the source file was compiled ("hh:mm:ss")
 * 
 * __STDC__ - used to indicate if the compiler supports standard C by returning the value 1
*/

#include <stdio.h>

#define JUST_CHECKING 0 // without a value it should initialize to 0
#define LIMIT 4

int main()
{
    int total = 0;

    for (int i = 0; i < LIMIT; i++)
    {
        total += 2*i*i + 1;

        // Only checks if it is defined, not if it has a value
        // You can pass deffinitions to the compiler with -D TERM Val
        // The system also passes in various args
        #ifdef JUST_CHECKING 
            printf("i = %d, running total = %d\n", i, total);
        #endif

        #if LIMIT == 4 && JUST_CHECKING == 2
            printf("this wont print unless we change LIMIT");
        #elif LIMIT == 5 
            printf("This wont print either");
        #elif LIMIT == 4 
            printf("This should print");            
        #endif
        // if not defined. since "AN_UNDEFINED" is not defined then this is true
        #ifndef AN_UNDEFINED 
            printf("This is not defined");
        #endif
    }

    printf("Grand total: %d", total);
    return 0;
}