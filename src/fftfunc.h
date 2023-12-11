#pragma once

#include "floatcomplex.h"
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef Complex cplx;

// Function declarations
void fft(Complex buf[], Complex out[], int n);
void ifft(Complex buf[], Complex out[], int n);
int get_next_pow2(int n);