/*
  Team Members:
  - Muzhou Wu (muzhou.wu@etu.sorbonne-universite.fr)
  - Md Shadnan Azwad Khan (md_shadnan_azwad.khan@etu.sorbonne-universite.fr)
  - Erekle Shatirishvili (erekle.shatirishvili@etu.sorbonne-universite.fr)
*/

#include "fftfunc.h"

// Function to perform FFT
void fft(cplx buf[], cplx out[], int n)
{
    if (n <= 1)
    {
        out[0] = buf[0];
        return;
    }

    cplx *even = malloc((n / 2) * sizeof(cplx));
    cplx *odd = malloc((n / 2) * sizeof(cplx));

    for (int i = 0; i < n / 2; i++)
    {
        even[i] = buf[i * 2];
        odd[i] = buf[i * 2 + 1];
    }

    fft(even, even, n / 2);
    fft(odd, odd, n / 2);

    for (int i = 0; i < n / 2; i++)
    {
        cplx t = c_mul(c_exp((Complex){0, -2.0 * PI * i / n}), odd[i]);
        out[i] = c_add(even[i], t);
        out[i + n / 2] = c_sub(even[i], t);
    }

    free(even);
    free(odd);
}

// Function to perform inverse FFT
void ifft(cplx buf[], cplx out[], int n)
{
    cplx *temp = malloc(n * sizeof(cplx));

    for (int i = 0; i < n; i++)
    {
        buf[i] = c_conj(buf[i]);
    }

    fft(buf, temp, n);

    for (int i = 0; i < n; i++)
    {
        out[i] = c_conj(c_div(temp[i], (Complex){n, 0}));
    }

    free(temp);
}

// Function to enlarge vectors to the next power of 2
int get_next_pow2(int n)
{
    int count = 0;

    if (n && !(n & (n - 1)))
    {
        return n;
    }

    while (n != 0)
    {
        n >>= 1;
        count++;
    }

    return 1 << count;
}