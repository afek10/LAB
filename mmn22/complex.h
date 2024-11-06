#ifndef COMPLEX_H
#define COMPLEX_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INPUT_SIZE 100

typedef struct {
    float real;
    float imag;
} complex;

void read_comp(complex *c, float r, float i);
void print_comp(complex c);
void add_comp(complex c1, complex c2);
void sub_comp(complex c1, complex c2);
void mult_comp_real(complex c1, float m);
void mult_comp_img(complex c1, float m);
void mult_comp_comp(complex c1, complex c2);
void abs_comp(complex c);
void stop();

#endif
