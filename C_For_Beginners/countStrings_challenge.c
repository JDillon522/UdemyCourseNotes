#include <stdio.h>

int customStrLen(const char * str);

int main()
{
    // Unnecessary
    // char str[] = "Some random string"; // 18
    // const char * pStr = NULL;
    // pStr = str;

    // int len = customStrLen(str);
    printf("length of \"%s\" is %d\n\n", "Some random string", customStrLen("Some random string"));
    return 0;
}

int customStrLen(const char * str)
{
    const char * lastAddress = str;

    while (*lastAddress)
    {
        lastAddress++;
    }
    
    return lastAddress - str;
}