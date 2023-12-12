/*
  Team Members:
  - Muzhou Wu (muzhou.wu@etu.sorbonne-universite.fr)
  - Md Shadnan Azwad Khan (md_shadnan_azwad.khan@etu.sorbonne-universite.fr)
  - Erekle Shatirishvili (erekle.shatirishvili@etu.sorbonne-universite.fr)
*/

#include "testing.h"

void initialize_polynomial(int *polynomial, int size)
{
    for (int i = 0; i < size; i++)
    {
        polynomial[i] = i + 1;
    }
}

void test_poly_mul(int size, bool printornot)
{
    // Define the size of the polynomials and initialize them
  int p1[size], p2[size];

  initialize_polynomial(p1, size);
  initialize_polynomial(p2, size);

  // Declare clock variables before measurements
  clock_t start_naive, end_naive, start_fft, end_fft;

  // Measure the time taken by the naive multiplication
  start_naive = clock();
  int *result_naive = naive_poly_mul(p1, size, p2, size);
  end_naive = clock();
  double time_naive = ((double)(end_naive - start_naive)) / CLOCKS_PER_SEC;

  // Measure the time taken by the FFT-based multiplication
  start_fft = clock();
  int *result_fft = fft_poly_mul(p1, size, p2, size, size);
  end_fft = clock();
  double time_fft = ((double)(end_fft - start_fft)) / CLOCKS_PER_SEC;

  if (printornot)
    {
      printf("Polynomial 1: ");
      poly_print(p1, size);

      printf("Polynomial 2: ");
      poly_print(p2, size);

      // Naive Polynomial Multiplication
      printf("\n%s\n", "Result of Naive Polynomial Multiplication: ");

      poly_print(result_naive, (2 * size) - 1);

      // FFT-based Polynomial Multiplication
      printf("\n%s\n", "Result of FFT-based Polynomial Multiplication: ");
      poly_print(result_fft, (2 * size) - 1);
    }

  printf("\nTime taken by naive multiplication: %.17g seconds\n", time_naive);
  printf("Time taken by FFT-based multiplication: %.17g seconds\n", time_fft);
}
