#pragma once

#include <time.h>
#include <stdbool.h>
#include "printoper.h"

// Include your header files
#include "naivepoly.h"
#include "fftpoly.h"

// Function prototypes
void initialize_polynomial(int *polynomial, int size);
void test_poly_mul(int size, bool printPolynomials);