/*
  Team Members:
  - Muzhou Wu (muzhou.wu@etu.sorbonne-universite.fr)
  - Md Shadnan Azwad Khan (md_shadnan_azwad.khan@etu.sorbonne-universite.fr)
  - Erekle Shatirishvili (erekle.shatirishvili@etu.sorbonne-universite.fr)
*/

#include "floatcomplex.h"

// In floatcomplex.h
inline Complex c_add(Complex a, Complex b)
{
    return (Complex){a.real + b.real, a.imag + b.imag};
}

inline Complex c_sub(Complex a, Complex b)
{
    return (Complex){a.real - b.real, a.imag - b.imag};
}

inline Complex c_mul(Complex a, Complex b)
{
    return (Complex){
        (a.real * b.real) - (a.imag * b.imag),
        (a.real * b.imag) + (a.imag * b.real)};
}

inline Complex c_div(Complex a, Complex b)
{
    double denominator = (b.real * b.real) + (b.imag * b.imag);
    if (denominator == 0)
    {
        // Handle division by zero error
        printf("Error: Division by zero\n");
        return (Complex){0, 0};
    }
    return (Complex){
        ((a.real * b.real) + (a.imag * b.imag)) / denominator,
        ((a.imag * b.real) - (a.real * b.imag)) / denominator};
}

// Function to calculate the exponential of a complex number
Complex c_exp(Complex c)
{
    double real_part = exp(c.real);
    double cos_part = cos(c.imag);
    double sin_part = sin(c.imag);

    Complex result;
    result.real = real_part * cos_part;
    result.imag = real_part * sin_part;
    return result;
}

// Function to calculate the conjugate of a complex number
Complex c_conj(Complex c)
{
    Complex result;
    result.real = c.real;
    result.imag = -c.imag;
    return result;
}