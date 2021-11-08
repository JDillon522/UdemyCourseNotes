#include <stdio.h>
#include <stdbool.h>

int main()
{

    int primes[100] = {1, 2, 3};
    int primeIndex = 3;

    // Iterate up to 100. Start at 3 because 1 and 2 are obvious
    for (int i = 5; i <= 100; i += 2)
    {
        bool isPrime = true;

        // Iterate through the current list of primes
        // If it can be divisible by a previous prime then it is not a prime itself
        // ie Prime Factorization
        for (int j = 2; j < primeIndex; j++)
        {
            if (i % primes[j] == 0) {
                isPrime = false;
                break;
            }
        }
        
        if (isPrime) {
            primes[primeIndex++] = i;
        }
    }
    
    printf("There are %d primes from 0 to 100\n", primeIndex);
    
    for (int i = 0; primes[i] != 0; i++)
    {
        printf("%d ", primes[i]);
    }
    
    printf("\n");

    return 0;
}