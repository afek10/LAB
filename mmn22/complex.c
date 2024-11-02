#include "complex.h"
#include <math.h>

complex add_complex(complex c1, complex c2) {
    complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

complex sub_complex(complex c1, complex c2)
{
    complex result;
    result.real = c1.real - c2.real;
    result.imag = c1.imag - c2.imag;
    return result;
}

complex multiplication_complex(complex c1, double m)
{
    complex result;
    result.real = c1.real * m;
    result.imag = c1.imag * m;
    return result;
}