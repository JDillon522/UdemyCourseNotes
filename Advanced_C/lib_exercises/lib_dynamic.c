/**
 * Dynamic Linking
 * 
 * slightly slower but more maintainable
 * naming convention: lib.<lib name>.so (or .dll on windows and .dylib on mac)
 * 
 * List all external deps of a program
 * `ldd name-of-exe`
 * 
 * Compile
 * `gcc -g -fPIC <libname>.c -shared -o lib.<libname>.so`
 * 
 *
 * `gcc -I <libdir> -c <filename>.c -o <output name>.o`
 * `gcc -I lib.foo/ -c lib_dynamic.c -o lib_dynamic.o`
 * shit doesnt work for me right now. TODO
*/

#include "lib.foo.h"

void funDynamic(void);

int main()
{
    funDynamic();

    return 0;
}