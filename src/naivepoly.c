/*
  Team Members:
  - Muzhou Wu (muzhou.wu@etu.sorbonne-universite.fr)
  - Md Shadnan Azwad Khan (md_shadnan_azwad.khan@etu.sorbonne-universite.fr)
  - Erekle Shatirishvili (erekle.shatirishvili@etu.sorbonne-universite.fr)
*/

#include "naivepoly.h"

// Function to multiply two polynomials
void naive_poly_mul(int poly1[], int m, int poly2[], int n, int result[])
{
    // Initialize the result polynomial with all coefficients as 0
    memset(result, 0, (m + n - 1) * sizeof(int));

    // Multiply each term of the first polynomial with each term of the second polynomial
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i + j] += poly1[i] * poly2[j];
        }
    }
}