#include <stdio.h>

int main()
{ 
    // DONT DO IT THIS WAY. EVER.
    // JUST DONT
    // JUST DO BIT FIELDS

    int flags = 15; // 0000 1111
    int mask = 182; // 1011 0110

    // turn bits on
    // flags = flags | mask; // 1011 1111

    // flags = flags & ~(mask); // 0000 1001

    // flags = flags ^ mask; // 1011 1001

    // checking value of a bit

    if ((flags & mask) == mask) {
        // true
    }
}