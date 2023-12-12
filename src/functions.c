/*
  Team Members:
  - Muzhou Wu (muzhou.wu@etu.sorbonne-universite.fr)
  - Md Shadnan Azwad Khan (md_shadnan_azwad.khan@etu.sorbonne-universite.fr)
  - Erekle Shatirishvili (erekle.shatirishvili@etu.sorbonne-universite.fr)
*/

#include "functions.h"

Complex c_add(Complex a, Complex b){
  return (Complex){a.real + b.real, a.imag + b.imag};
}

Complex c_sub(Complex a, Complex b){
  return (Complex){a.real - b.real, a.imag - b.imag};
}

Complex c_mul(Complex a, Complex b){
  return (Complex){
    (a.real * b.real) - (a.imag * b.imag),
    (a.real * b.imag) + (a.imag * b.real)};
}

Complex c_div(Complex a, Complex b){
  double denominator = (b.real * b.real) + (b.imag * b.imag);
  if (denominator == 0){
    printf("Error: Division by zero\n");
    return (Complex){0, 0};
  }
  return (Complex){
    ((a.real * b.real) + (a.imag * b.imag)) / denominator,
    ((a.imag * b.real) - (a.real * b.imag)) / denominator
  };
}

Complex c_exp(Complex c){
  double real_part = exp(c.real);
  return (Complex){
    real_part * cos(c.imag),
    real_part * sin(c.imag)
  };
}

Complex c_conj(Complex c){
  return (Complex){
    c.real,
    -c.imag
  };
}

void fft(Complex *x, int n){
  if (n < 2) return;
  int half_n = n >> 1;
  Complex even[half_n], odd[half_n];
  for (int i = 0; i < half_n; ++i){
    even[i] = x[i * 2];
    odd[i] = x[i * 2 + 1];
  }
  fft(even, half_n);
  fft(odd, half_n);
  for (int k = 0; k < half_n; ++k){
    double theta = -2 * PI * k / n;
    Complex t = c_mul((Complex){cos(theta), sin(theta)},  odd[k]);
    x[k] = c_add(even[k], t);
    x[k + half_n] = c_sub(even[k], t);
  }
}

// Function to perform inverse FFT
void ifft(Complex *x, int n){
  for (int i = 0; i < n; ++i){
    x[i].imag *= -1;
  }
  fft(x, n);
  for (int i = 0; i < n; ++i){
    x[i].imag *= -1;
    x[i] = c_div(x[i], (Complex){n, 0});
  }
}

// Function to enlarge vectors to the next power of 2
unsigned int get_next_pow2(int n){
  if (n && !(n & (n - 1)))
    return n;
  unsigned int count = 0;
  while (n != 0){
    n >>= 1;
    count++;
  }
  return 1 << count;
}

int *fft_poly_mul(int *poly1, int m, int *poly2, int n, int size){
  int fft_size = get_next_pow2(2 * size);
  int *result = malloc((m + n - 1) * sizeof(int));
  Complex fft_poly1[fft_size];
  Complex fft_poly2[fft_size];
  Complex fft_result[fft_size];
  for (int i = 0; i < fft_size; ++i){
    fft_poly1[i] = (i < m) ? (Complex){poly1[i], 0} : (Complex){0, 0};
    fft_poly2[i] = (i < n) ? (Complex){poly2[i], 0} : (Complex){0, 0};
  }
  fft(fft_poly1, fft_size);
  fft(fft_poly2, fft_size);
  // Point-wise multiplication in the frequency domain
  for (int i = 0; i < fft_size; ++i){
    fft_result[i] = c_mul(fft_poly1[i], fft_poly2[i]);
  }
  // Apply IFFT to get the product polynomial in the time domain
  ifft(fft_result, fft_size);
  // Extract the real parts and store them in the result array
  for (int i = 0; i < (m+n)-1; ++i)
    result[i] = (int)round(fft_result[i].real);
  return result;
}

int *naive_poly_mul(int poly1[], int m, int poly2[], int n)
{
    // Initialize the result polynomial with all coefficients as 0
  int *result = calloc((m + n - 1), sizeof(int));
  // Multiply each term of the first polynomial with each term of the second polynomial
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
        result[i + j] += poly1[i] * poly2[j];
  return result;
}

// Function to print a complex number
void c_print(Complex c){
  // Check the sign of the imaginary part
  if (c.imag >= 0)
    printf("%.15lf + %.15lfi\n", c.real, c.imag); // For positive imaginary part, print a+bi
  else
    printf("%.15lf - %.15lfi\n", c.real, -c.imag); // For negative imaginary part, print a-bi
}

// Function to print a polynomial with lower powers to higher powers
void poly_print(int poly[], int n){
  for (int i = 0; i < n; i++){
    if(poly[i]==0) printf("0");
    else{
      if (i == 0){
        printf("%s", poly[i] < 0 ? " - " : " ");
        printf("%d", abs(poly[i]));
      }
      else
        printf("%dx^%d", abs(poly[i]), i);
      if (i < n - 1)
        printf(" %c ",(poly[i+1] < 0) ? '-' : '+');
    }
  }
  printf("\n");
}

void c_vec_print(Complex *vector, int size){
  for (int i = 0; i < size; ++i)
    c_print(vector[i]);
}
