#include <stdio.h>
#include <stdlib.h>

struct s
{
    int arrSize;
    /**
     * Flexible array arr[]
     * - must be the last member of a struct
     * - a struct can contain only one flexible array member
     * - cannot be the only member of a struct
     * - any struct containing a flexible array member cannot be a member of another struct
     * - cannot be statically initialized and must be dynamic
    */
    int arr[]; // specify the array with empty brackets
};


int main()
{
    int desiredSize = 5;
    struct s * ptr;

    ptr = calloc(sizeof(struct s) + desiredSize, sizeof(int));


    return 0;
}