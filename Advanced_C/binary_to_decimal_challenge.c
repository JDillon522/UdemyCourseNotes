/**
 * Write a function that takes an int or long base 2 representation and converts it to decimal
 * - long long bin = 01001001;
 * - int binToDec(long long bin);
 * -- return 25
 * 
 * write a function that takes an int and converts it to binary
 * - int dec = 25;
 * - long long decToBin(int dec);
 * -- return 01001001;
*/

#include <stdio.h>
#include <math.h>


// First pass
int binToDec(long long binary);
long long decToBin(int decimal);
// Only handling 8 unsigned bits because I'm a bit lazy today
// Brutes it and doesnt use any math function. Icky
int bitLocation[8] = { 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1 };
int bitValue[8] = { 128, 64, 32, 16, 8, 4, 2, 1 };


// Second pass using math functions
int binToDecMath(long long binary);
long long decToBinMath(int decimal);

int main()
{
    printf("Binary 1001 to decimal: %d\n", binToDec(1001)); // 9
    printf("Binary 101101 to decimal: %d\n", binToDec(101101)); // 45

    printf("Decimal 9 to binary binary: %lli\n", decToBin(9));
    printf("Decimal 45 to binary binary: %lli\n", decToBin(45));

    printf("\n\nMATH\n\n");
    printf("Binary 1001 to decimal: %d\n", binToDecMath(1001)); // 9
    printf("Binary 101101 to decimal: %d\n", binToDecMath(101101)); // 45
    printf("Decimal 9 to binary binary: %lli\n", decToBinMath(9));
    printf("Decimal 45 to binary binary: %lli\n", decToBinMath(45));

    printf("\n");
    return 0;
}

// Shite
int binToDec(long long binary)
{
    int decimal = 0;
    for (int i = 0; i < 8; i++)
    {
        if (binary >= bitLocation[i]) 
        {
            binary -= bitLocation[i];
            decimal += bitValue[i];
        }
    }
    
    return decimal;
}
// Shite
long long decToBin(int decimal)
{
    long long binary = 0;
    for (int i = 0; i < 8; i++)
    {
        if (decimal >= bitValue[i])
        {
            decimal -= bitValue[i];
            binary += bitLocation[i];
        }
    }
    
    return binary;
}

// NOT Shite
int binToDecMath(long long binary) 
{
    int decimalNumber = 0, i = 0, remainder = 0;

    while (binary != 0) 
    {
        // Convert from base 10 to base 2. 
        remainder = binary % 10; // get wether or not the last digit is a 1 or 0
        binary = binary / 10; // essentially remove the right most digit
        // if there is a remainder (ie of 1) then multiple it by the exponent of the iteration
        decimalNumber += remainder * pow(2, i); 
        i++;
    }

    return decimalNumber;
}

// NOT Shite
long long decToBinMath(int decimal)
{
    long long binary = 0;
    int remainder, i = 1; // Start i at 1 because we need to be able to set the lest sig bit

    while (decimal != 0)
    {
        // Essentially the same as above but now accounting for base 2
        remainder = decimal % 2;
        decimal = decimal / 2;
        binary += remainder * i;
        i *= 10; // This will move i to the next bit location.
        // Mind = Blown
    }

    return binary;
}