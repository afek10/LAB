#include "complex.h"


void read_comp(complex *c, float r, float i) 
{
    c->real = r;
    c->imag = i;
}

void print_comp(complex c) 
{
    printf("%f + (%f)i", c.real, c.imag);
}

void add_comp(complex c1, complex c2) {
    complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    print_comp(result);
}

void sub_comp(complex c1, complex c2)
{
    complex result;
    result.real = c1.real - c2.real;
    result.imag = c1.imag - c2.imag;
    print_comp(result);
}

void mult_comp_real(complex c1, float m)
{
    complex result;
    result.real = c1.real * m;
    result.imag = c1.imag * m;
    print_comp(result);
}

void mult_comp_img(complex c1, float m)
{
    complex result;
    result.real = -1 * c1.imag * m;
    result.imag = c1.real * m;
    print_comp(result);
}

void mult_comp_comp(complex c1, complex c2)
{
    complex result;
    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c2.real * c1.imag;
    print_comp(result);
}

void abs_comp(complex c1)
{
    float result = sqrt((c1.real * c1.real) + (c1.imag * c1.imag));
    printf("%f",result);
}

void stop()
{
    exit(0);
}