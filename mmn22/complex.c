#include "complex.h"

/**
 * Reads a complex number by setting its real and imaginary components.
 * 
 * @param c A pointer to the complex number.
 * @param r The real part of the complex number.
 * @param i The imaginary part of the complex number.
 */
void read_comp(complex *c, float r, float i) 
{
    c->real = r;
    c->imag = i;
}

/**
 * Prints a complex number in the format "real + (imag)i".
 * 
 * @param c The complex number to be printed.
 */
void print_comp(complex c) 
{
    printf("%f + (%f)i", c.real, c.imag);
}

/**
 * Adds two complex numbers and prints the result.
 * 
 * @param c1 The first complex number.
 * @param c2 The second complex number.
 */
void add_comp(complex c1, complex c2) {
    complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    print_comp(result);
}

/**
 * Subtracts the second complex number from the first and prints the result.
 * 
 * @param c1 The first complex number.
 * @param c2 The second complex number.
 */
void sub_comp(complex c1, complex c2)
{
    complex result;
    result.real = c1.real - c2.real;
    result.imag = c1.imag - c2.imag;
    print_comp(result);
}

/**
 * Multiplies a complex number by a real number and prints the result.
 * 
 * @param c1 The complex number to be multiplied.
 * @param m The real number multiplier.
 */
void mult_comp_real(complex c1, float m)
{
    complex result;
    result.real = c1.real * m;
    result.imag = c1.imag * m;
    print_comp(result);
}

/**
 * Multiplies a complex number by an imaginary number and prints the result.
 * 
 * @param c1 The complex number to be multiplied.
 * @param m The imaginary number multiplier.
 */
void mult_comp_img(complex c1, float m)
{
    complex result;
    result.real = -1 * c1.imag * m;
    result.imag = c1.real * m;
    print_comp(result);
}

/**
 * Multiplies two complex numbers and prints the result.
 * 
 * @param c1 The first complex number.
 * @param c2 The second complex number.
 */
void mult_comp_comp(complex c1, complex c2)
{
    complex result;
    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c2.real * c1.imag;
    print_comp(result);
}

/**
 * Calculates and prints the absolute value of a complex number.
 * 
 * @param c1 The complex number whose absolute value is to be calculated.
 */
void abs_comp(complex c1)
{
    float result = sqrt((c1.real * c1.real) + (c1.imag * c1.imag));
    printf("%f",result);
}

/**
 * Stops the program.
 */
void stop()
{
    exit(0);
}
