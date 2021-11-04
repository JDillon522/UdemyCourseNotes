#include <stdio.h>

int main()
{
    enum Company { GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT };
    enum Company first = XEROX;
    enum Company second = GOOGLE;
    enum Company third = EBAY;

    printf("%d %d %d", first, second, third);
}
