#include <stdio.h>
#include <string.h>

int main()
{
    int i;

    char multiple[] = "a string";
    char * pMultiple = multiple;

    for (i = 0; i < strlen(multiple); i++)
    {
        printf("multiple[%d] = %c *(pMultiple + %d) = %c &multiple[%d] = %p pMultiple + %d = %p\n",
            i, multiple[i], i, *(pMultiple+i), i, &multiple[i], i, pMultiple+i);
    }
    
    /*
    Neat way to show how dereferencing the index of an array or using a pointer returns the same address
    multiple[0] = a *(pMultiple + 0) = a &multiple[0] = 0x7fffffffdc4f pMultiple + 0 = 0x7fffffffdc4f
    multiple[1] =   *(pMultiple + 1) =   &multiple[1] = 0x7fffffffdc50 pMultiple + 1 = 0x7fffffffdc50
    multiple[2] = s *(pMultiple + 2) = s &multiple[2] = 0x7fffffffdc51 pMultiple + 2 = 0x7fffffffdc51
    multiple[3] = t *(pMultiple + 3) = t &multiple[3] = 0x7fffffffdc52 pMultiple + 3 = 0x7fffffffdc52
    multiple[4] = r *(pMultiple + 4) = r &multiple[4] = 0x7fffffffdc53 pMultiple + 4 = 0x7fffffffdc53
    multiple[5] = i *(pMultiple + 5) = i &multiple[5] = 0x7fffffffdc54 pMultiple + 5 = 0x7fffffffdc54
    multiple[6] = n *(pMultiple + 6) = n &multiple[6] = 0x7fffffffdc55 pMultiple + 6 = 0x7fffffffdc55
    multiple[7] = g *(pMultiple + 7) = g &multiple[7] = 0x7fffffffdc56 pMultiple + 7 = 0x7fffffffdc56
    */

    return 0;
}