/*
  Team Members:
  - Muzhou Wu (muzhou.wu@etu.sorbonne-universite.fr)
  - Md Shadnan Azwad Khan (md_shadnan_azwad.khan@etu.sorbonne-universite.fr)
  - Erekle Shatirishvili (erekle.shatirishvili@etu.sorbonne-universite.fr)
*/

#include "testing.h"

void print_section_header(const char *section_name)
{
    printf("\n--------------------------------------------------------------------\n");
    printf("\n%s\n", section_name);
}

void perform_complex_arithmetic()
{
    Complex num1;
    Complex num2;

    char choicecomplex;

    printf("Do you want to use random numbers? (y/n): ");
    scanf(" %c", &choicecomplex);

    printf("\n");

    if (choicecomplex == 'y' || choicecomplex == 'Y')
    {
        // Generate random complex numbers
        // Seed the random number generator with the current time
        srand(time(NULL));

        // Generate random values for the real and imaginary parts
        num1.real = ((double)rand() / RAND_MAX) * 200 - 100; // Random real part
        num1.imag = ((double)rand() / RAND_MAX) * 200 - 100; // Random imaginary part
        num2.real = ((double)rand() / RAND_MAX) * 200 - 100; // Random real part
        num2.imag = ((double)rand() / RAND_MAX) * 200 - 100; // Random imaginary part
    }
    else
    {
        // Taking user input for real part
        printf("Enter the real part for Complex Number 1: ");
        scanf("%lf", &num1.real);

        // Taking user input for imaginary part
        printf("Enter the imaginary part for Complex Number 1: ");
        scanf("%lf", &num1.imag);

        // Taking user input for real part
        printf("Enter the real part for Complex Number 2: ");
        scanf("%lf", &num2.real);

        // Taking user input for imaginary part
        printf("Enter the imaginary part for Complex Number 2: ");
        scanf("%lf", &num2.imag);

        printf("\n");
    }

    Complex sum = c_add(num1, num2);
    Complex difference = c_sub(num1, num2);
    Complex product = c_mul(num1, num2);
    Complex quotient = c_div(num1, num2);
    Complex exp_num1 = c_exp(num1);
    Complex exp_num2 = c_exp(num2);
    Complex conj_num1 = c_conj(num1);
    Complex conj_num2 = c_conj(num2);

    printf("Complex Number 1: ");
    c_print(num1);

    printf("Complex Number 2: ");
    c_print(num2);

    printf("Sum: ");
    c_print(sum);

    printf("Difference: ");
    c_print(difference);

    printf("Product: ");
    c_print(product);

    printf("Quotient: ");
    c_print(quotient);

    printf("Exponential of Complex Number 1: ");
    c_print(exp_num1);

    printf("Exponential of Complex Number 2: ");
    c_print(exp_num2);

    printf("Conjugate of Complex Number 1: ");
    c_print(conj_num1);

    printf("Conjugate of Complex Number 2: ");
    c_print(conj_num2);
}

void perform_fft_and_ifft()
{
    int size;

    printf("Enter the size of the array to be generated for FFT and IFFT: ");
    scanf("%d", &size);

    printf("%s\n", "Using random double precision floting point numbers for the array elements...");

    int fftSize = get_next_pow2(size);

    Complex *input = (Complex *)malloc(fftSize * sizeof(Complex));
    Complex *output_fft = (Complex *)malloc(fftSize * sizeof(Complex));
    Complex *output_ifft = (Complex *)malloc(fftSize * sizeof(Complex));

    for (int i = 0; i < size; ++i)
    {
        input[i] = (Complex){((double)rand() / RAND_MAX) * 200 - 100, ((double)rand() / RAND_MAX) * 200 - 100};
    }

    printf("\nInput Vector:\n");
    c_vec_print(input, size);

    fft(input, output_fft, fftSize);

    printf("\nFFT:\n");
    c_vec_print(output_fft, fftSize);

    ifft(output_fft, output_ifft, fftSize);

    printf("\nIFFT:\n");
    c_vec_print(output_ifft, fftSize);

    free(input);
    free(output_fft);
    free(output_ifft);
}

void perform_poly_multiplication(const char *method_name, int *poly1, int m, int *poly2, int n)
{
    int result_size = m + n - 1;
    int input_size_max = get_next_pow2((m >= n) ? m : n);

    int result[result_size];

    printf("\n%s Polynomial Multiplication:\n", method_name);

    printf("Polynomial 1: ");
    poly_print(poly1, m);

    printf("Polynomial 2: ");
    poly_print(poly2, n);

    if (strcmp(method_name, "Naive") == 0)
    {
        naive_poly_mul(poly1, m, poly2, n, result);
    }
    else if (strcmp(method_name, "FFT") == 0)
    {
        fft_poly_mul(poly1, m, poly2, n, result, input_size_max);
    }

    printf("Result of multiplication: ");
    poly_print(result, result_size);
}

void perform_testing(int size, bool printPolynomials)
{
    printf("\nSize of polynomial: %d\n", size);
    test_poly_mul(size, printPolynomials);
}

int main()
{
    char choice;

    print_section_header("Complex Arithmetic:");

    printf("\n%s", "Do you wish to perform Complex Arithmetic? (y/n): ");
    scanf(" %c", &choice);

    while (choice == 'y' || choice == 'Y')
    {
        perform_complex_arithmetic();
        printf("\n%s", "Do you wish to continue doing Complex Arithmetic? (y/n): ");
        scanf(" %c", &choice);
    }

    print_section_header("FFT and IFFT:");

    printf("\n%s", "Do you wish to perform FFT and IFFT? (y/n): ");
    scanf(" %c", &choice);

    while (choice == 'y' || choice == 'Y')
    {
        perform_fft_and_ifft();
        printf("\n%s", "Do you wish to continue doing FFT and IFFT? (y/n): ");
        scanf(" %c", &choice);
    }

    print_section_header("Polynomial Multiplication:");

    printf("\n%s", "Do you wish to perform Polynomial Multiplication? (y/n): ");
    scanf(" %c", &choice);

    while (choice == 'y' || choice == 'Y')
    {
        int degree1;
        int degree2;

        printf("Enter the degree of Polynomial 1 to be generated: ");
        scanf("%d", &degree1);

        printf("Enter the degree of Polynomial 2 to be generated: ");
        scanf("%d", &degree2);

        printf("%s\n", "Using random integers as polynomial coefficients...");

        int *poly1 = (int *)malloc((degree1 + 1) * sizeof(int));
        int *poly2 = (int *)malloc((degree2 + 1) * sizeof(int));

        for (int i = 0; i < degree1 + 1; ++i)
        {
            poly1[i] = rand() % 201 - 100;
        }

        for (int i = 0; i < degree2 + 1; ++i)
        {
            poly2[i] = rand() % 201 - 100;
        }

        perform_poly_multiplication("Naive", poly1, degree1 + 1, poly2, degree2 + 1);
        perform_poly_multiplication("FFT", poly1, degree1 + 1, poly2, degree2 + 1);

        free(poly1);
        free(poly2);

        printf("\n%s", "Do you wish to continue doing Polynomial Multiplication? (y/n): ");
        scanf(" %c", &choice);
    }

    print_section_header("Testing Polynomial Multiplication:");

    printf("\n%s", "Do you wish to compare Naive and FFT Polynomial Multiplication? (y/n): ");
    scanf(" %c", &choice);

    int degree;
    char toprintornot;

    while (choice == 'y' || choice == 'Y')
    {
        printf("Enter the degree of polynomials to be generated: ");
        scanf("%d", &degree);
        printf("Do you wish to print the Polynomials and Result? (y/n): ");
        scanf(" %c", &toprintornot);
        bool printornot = (toprintornot == 'y' || toprintornot == 'Y');

        perform_testing(degree, printornot);

        printf("\n%s", "Do you wish to continue Testing? (y/n): ");
        scanf(" %c", &choice);
    }

    printf("\n--------------------------------------------------------------------\n");

    return 0;
}