#include <stdio.h>

// a 32 bit structure storing multiple flags and chunks of data contigiously. 
// the digit past the : is how many individual bits are reserved for each flag
struct packedData {
    // you can have other non bit fields
    int count;
    char name;
    // then add the bit fields
    // it has to be an unsigned int -- no idea why <-- i guess it CAN be signed, but it can create unexpected results 
    // apparently can also be an unsigned char
    unsigned int :3; // unnamed bits, used for padding
    unsigned int f1:1;
    unsigned int f2:1;
    unsigned int f3:1;
    unsigned int type:8;
    unsigned int index:18;
};

int main()
{
    struct packedData data;
    data.type = 7;
}