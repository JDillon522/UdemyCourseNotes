#include <stdio.h>
#include <complex.h>

int main()
{

    // Neat VS Code implementation. It'll tell you ahead of time if its supported by the compiler on your box
#ifdef __STDC_NO_COMPLEX__
    printf("Complex numbers are not supported\n");
#else
    printf("Complex numbers ARE supported\n");
#endif

    double complex cx = 1.0 + 3.0*I;
    double complex cy = 1.0 - 4.0*I;

    /**
     * creal() return the real portion
     * cimag() return the imaginary part
     * conj() get the conjuicate for double, conjf() for float and conjl() for long
    */

    printf("Working with complex numbers...\n");
    printf("cx = 1.0 + 3.0*I. Real portion: %.2f. Imaginary: %.2f. \n", creal(cx), cimag(cx));

    double complex sum = cy + cx;
    printf("Sum of cy and cx: %.2f%+.2fi  \n", creal(sum), cimag(sum));
    return 0;

}   