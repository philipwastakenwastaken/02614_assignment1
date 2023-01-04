#include "matrix_math.h"

int matmult_nat(int m, int n, int k, double** a, double** b, double** c)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (int l = 0; l < k; l++)
                c[i][j] += a[i][l] * b[l][j];
        }

    return 0;
}


int matmult_lib(int m, int n, int k, double** a, double** b, double** c)
{
    // The leading dimension is the second dimension of the matrix since
    // we are converting from column major to row major order.
    int lda = k;
    int ldb = n;
    int ldc = n;

    cblas_dgemm(
        CblasRowMajor,
        CblasNoTrans,
        CblasNoTrans,
        m,
        n,
        k,
        1, // Alpha
        &a[0][0],
        lda,
        &b[0][0],
        ldb,
        0, // Beta
        &c[0][0],
        ldc
    );

    return 0;
}