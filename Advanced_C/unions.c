/**
 * Unions are a data structure that share the same space in memory. You can hold different data types in the same location
 * - only one member can have a value at a time
 * - used in situations where space is paramount
 * - does not waste space with unused variables. 
 * - created with enough space for its largest field
 * - use when a construct can be multiple different things but only one thing at a time
 * - only the first member can be initialized 
*/

// Its hard to think of a good real life use case. Maybe if a data source doesnt always return consistent data types
union UnknownDbData {
    int i;
    float f;
    char str[100];
};

// Struct with an anomous union
struct SomeStruct {
    char *name;
    int price;
    union {
        int i;
        float i;
        char c;
    } data;
};

int main()
{
    struct SomeStruct myStruct;

    myStruct.data.c;
    
}