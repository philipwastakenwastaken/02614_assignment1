#ifndef MATRIX_MATH_H
#define MATRIX_MATH_H

#include <cblas.h>

int matmult_nat(int m, int n, int k, double** a, double** b, double** c);
int matmult_lib(int m, int n, int k, double** a, double** b, double** c);
int matmult_blk(int m, int n, int k, double** a, double** b, double** c, int bs);

#endif
