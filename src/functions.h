#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define PI 3.14159265358979323846

typedef struct {
  double real;
  double imag;
} Complex;

Complex c_add(Complex a, Complex b);
Complex c_sub(Complex a, Complex b);
Complex c_mul(Complex a, Complex b);
Complex c_div(Complex a, Complex b);
Complex c_exp(Complex c);
Complex c_conj(Complex c);

void fft(Complex *x, int n);
void ifft(Complex *x, int n);
unsigned int get_next_pow2(int n);

int *fft_poly_mul(int *poly1, int m, int *poly2, int n, int size);
int *naive_poly_mul(int poly1[], int m, int poly2[], int n);

void c_print(Complex c);
void c_vec_print(Complex *vector, int size);
void poly_print(int poly[], int n);

void initialize_polynomial(int *polynomial, int size);
void test_poly_mul(int size, bool printPolynomials);

#endif
