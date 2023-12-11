/*
  Team Members:
  - Muzhou Wu (muzhou.wu@etu.sorbonne-universite.fr)
  - Md Shadnan Azwad Khan (md_shadnan_azwad.khan@etu.sorbonne-universite.fr)
  - Erekle Shatirishvili (erekle.shatirishvili@etu.sorbonne-universite.fr)
*/

#include "printoper.h"

// Function to print a complex number
void c_print(Complex c)
{
    // Check the sign of the imaginary part
    if (c.imag >= 0)
    {
        // For positive imaginary part, print a+bi
        printf("%.15lf + %.15lfi\n", c.real, c.imag);
    }
    else
    {
        // For negative imaginary part, print a-bi
        printf("%.15lf - %.15lfi\n", c.real, -c.imag);
    }
}

// Function to print a polynomial with lower powers to higher powers
void poly_print(int poly[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if(poly[i]==0){
            printf("0");
        }else{
        if (i == 0)
        {
            printf("%s", poly[i] < 0 ? " - " : " ");
            printf("%d", abs(poly[i]));
        }
        else
        {
            printf("%dx^%d", abs(poly[i]), i);
        }
        
        if (i < n - 1)
        {
            printf(" %c ",(poly[i+1] < 0) ? '-' : '+');
        }
    }}
    printf("\n");
}

void c_vec_print(cplx *vector, int size)
{
    for (int i = 0; i < size; ++i)
    {
        c_print(vector[i]);
    }
}