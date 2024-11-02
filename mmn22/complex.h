#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct {
    double real;
    double imag;
} complex;

complex add_complex(complex c1, complex c2);
complex sub_complex(complex c1, complex c2);
complex mul_real(complex c, double m);
complex mul_imag(complex c, double mi);
complex mul_complex(complex c1, complex c2);
double abs_complex(complex c);

#endif 
