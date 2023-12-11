/*
  Team Members:
  - Muzhou Wu (muzhou.wu@etu.sorbonne-universite.fr)
  - Md Shadnan Azwad Khan (md_shadnan_azwad.khan@etu.sorbonne-universite.fr)
  - Erekle Shatirishvili (erekle.shatirishvili@etu.sorbonne-universite.fr)
*/

#include "fftpoly.h"

// Function to multiply two polynomials using FFT
void fft_poly_mul(int *poly1, int m, int *poly2, int n, int *result, int size)
{
    // Ensure the input size is a power of 2
    int fft_size = get_next_pow2(2 * size);

    // Create complex arrays for FFT
    Complex *fft_poly1 = malloc(fft_size * sizeof(Complex));
    Complex *fft_poly2 = malloc(fft_size * sizeof(Complex));
    Complex *fft_result = malloc(fft_size * sizeof(Complex));

    // Initialize complex arrays with polynomial coefficients and pad with zeros
    for (int i = 0; i < fft_size; ++i)
    {
        fft_poly1[i] = (i < m) ? (Complex){(double)poly1[i], 0} : (Complex){0, 0};
        fft_poly2[i] = (i < n) ? (Complex){(double)poly2[i], 0} : (Complex){0, 0};
    }

    // Apply FFT to both polynomials
    fft(fft_poly1, fft_poly1, fft_size);
    fft(fft_poly2, fft_poly2, fft_size);

    // Point-wise multiplication in the frequency domain
    for (int i = 0; i < fft_size; ++i)
    {
        fft_result[i] = c_mul(fft_poly1[i], fft_poly2[i]);
    }

    // Apply IFFT to get the product polynomial in the time domain
    ifft(fft_result, fft_result, fft_size);

    // Extract the real parts and store them in the result array
    for (int i = 0; i < (m+n)-1; ++i)
    {
        result[i] = (int)round(fft_result[i].real); // Round to the nearest integer
    }

    // Free allocated memory
    free(fft_poly1);
    free(fft_poly2);
    free(fft_result);
}