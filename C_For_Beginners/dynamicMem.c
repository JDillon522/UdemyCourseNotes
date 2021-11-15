#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
        Dynamic memory with Malloc

        malloc() returns a void pointer

        Not a good practice to hardcode it like this.
        this equates to only 100 bytes of memory. Since an int is 4 bytes
        this will only hold 25 ints
        also not cross platform reliable / portable because different systems can compilers 
        can allocate different amount of memory
    */
    int *pNum = (int*)malloc(100); 

    // better to use the sizeof
    // this will guarentee enough space for 25 ints
    int *pNum2 = (int*)malloc(25 * sizeof(int));

    // Its good practice to double check that the new pointer is not null
    if (!pNum2) 
    {
        // handle errors if it cant allocate memory
        // probably exit/abort the program in this case
    }

    // Free / release memory as soon as you're done with it
    free(pNum);
    pNum = NULL; // set to null after to signify that its not pointing to anything
    free(pNum2);
    pNum2 = NULL;

    /*
        Dynamic memory with calloc()

        better than malloc because it initializes the memory that is allocated so that 
        all bytes are set to zero. With malloc() you're likely to get whatever value was 
        previously stored
    */

    // Similar to malloc but more deliberate and clean
    int *pNum3 = (int*)calloc(75, sizeof(int));
    // still double check if it was allocated
    if (!pNum3)
    {
        // bad
    }
    
    /*
        Dynamic memory with realloc()

        enables you to reuse or extend memory that was previously allocated with malloc() or calloc()

    */
    pNum3 = (int*)realloc(pNum3, 50);


    return 0;
}