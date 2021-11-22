/**
 * Create a static lib
 * 
 * to compile without linking
 * `gcc -c <libname>.c -o lib_<libname>.o` 
 * 
 * create the archive file:
 * `ar rcs lib_<libname>.a lib_<libname>.o`
 * 
 * to see what files are added into an archive:
 * `ar -t <archive file>.a`
 * 
 * compile program using lib:
 * `gcc -I <lib dir> -c <filename>.c`
*/

#include "lib.foo/lib.foo.h"

void fun(void);

int main()
{
    fun();

    return 0;
}