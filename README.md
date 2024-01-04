## Contributors
This project was developed by the following group members:

**Muzhou Wu** - muzhou.wu@etu.sorbonne-universite.fr

**Md Shadnan Azwad Khan** - md_shadnan_azwad.khan@etu.sorbonne-universite.fr

**Erekle Shatirishvili** - erekle.shatirishvili@etu.sorbonne-universite.fr

# Project: FFTPolyMath in C

> *"The shortest path between two truths in the real domain passes through the complex domain."*
**Jacques Hadamard**

## Introduction
This C-based project aims to implement complex arithmetic, Fast Fourier Transform (FFT), inverse FFT, and polynomial multiplication using naive and FFT-based methods. The project includes a comparative analysis of the efficiency between naive and FFT-based polynomial multiplication algorithms.

## Project Structure
The project is structured into the following C source files and accompanying header files:
- **functions.c** and **functions.h**: Defines a `Complex` structure and implements addition (`c_add`), subtraction (`c_sub`), multiplication (`c_mul`), division (`c_div`), exponentiation (`c_exp`), and conjugation (`c_conj`) functions for complex arithmetic. Implements the Cooley-Tukey radix-2 DIT algorithm for `fft` and `ifft` functions using the `Complex` structure and other complex number operations. Implements a FFT-based algorithm for polynomial multiplication (`fft_poly_mul`) using the `fft` and `ifft` functions. Implements a naive polynomial multiplication algorithm `naive_poly_mul`. Facilitates print operations of complex numbers (`c_print`), complex vectors (`c_vec_print`), and polynomials (`poly_print`).
- **testing.c** and **testing.h**: Construct test functions evaluating polynomial multiplication efficiency for `naive_poly_mul` and `fft_poly_mul` functions.
- **main.c**: Serve as the execution script organizing all functionalities.

## Building the Project
The project includes a Makefile for effective compilation. Use the following command to compile the project:
```bash
make
```
This command compiles all source files, linking them into an executable.

## Running the Project
After compilation, execute the following command to run the project:
```bash
make run
```
This command initiates operations such as complex arithmetic, FFT, and inverse FFT on complex vectors, polynomial multiplication using naive and FFT-based methods. It concludes with an efficiency assessment of polynomial multiplication.

## Cleaning Up
To remove compiled artifacts and the executable, use the following command:
```bash
make clean
```
This command removes object files, preserving only the source files.

## Important Notes
To set up the project, ensure that the `gcc` **(GNU Compiler Collection)** is installed on your system.
```bash
sudo apt-get install -y gcc
```
In any case, the Makefile is intended to be compiler-independent. To use a specific compiler, set the CC environment variable. For instance:
```bash
make CC=clang
```
The default compile-time flags include `-Wall` and `-g`, which can also be customized by setting the `CFLAGS` environment variable.
