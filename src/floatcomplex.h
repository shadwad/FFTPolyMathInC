#pragma once

#include <stdio.h>
#include <math.h>

typedef struct
{
    double real;
    double imag;
} Complex;

// Function declarations
Complex c_add(Complex a, Complex b);
Complex c_sub(Complex a, Complex b);
Complex c_mul(Complex a, Complex b);
Complex c_div(Complex a, Complex b);
Complex c_exp(Complex c);
Complex c_conj(Complex c);