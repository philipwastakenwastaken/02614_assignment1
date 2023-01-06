#include <string.h>
#include "matrix_math.h"
#include <string.h>
#include <stdlib.h>

#define min(x,y) (x<y ? x:y)

/*
*****************
EXERCISE 1
*****************
*/

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

/*
*****************
EXERCISE 2
*****************
*/

// mkn is the fastest

int matmult_mnk(int m, int n, int k, double** a, double** b, double** c)
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


int matmult_nmk(int m, int n, int k, double** a, double** b, double** c)
{
    for (int j = 0; j < n; j++)
        for (int i = 0; i < m; i++)
        {
            c[i][j] = 0;
            for (int l = 0; l < k; l++)
                c[i][j] += a[i][l] * b[l][j];
        }

    return 0;
}


int matmult_nkm(int m, int n, int k, double** a, double** b, double** c)
{
    memset(*c, 0, m*n*sizeof(double));
    for (int j = 0; j < n; j++)
        for (int l = 0; l < k; l++)
            for (int i = 0; i < m; i++){
                c[i][j] += a[i][l] * b[l][j];
            }

    return 0;
}


int matmult_mkn(int m, int n, int k, double** a, double** b, double** c)
{
    memset(*c, 0, m*n*sizeof(double));
    for (int i = 0; i < m; i++)
        for (int l = 0; l < k; l++)
            for (int j = 0; j < n; j++){
                c[i][j] += a[i][l] * b[l][j];
            }

    return 0;
}

int matmult_kmn(int m, int n, int k, double** a, double** b, double** c)
{
    memset(*c, 0, m*n*sizeof(double));
    for (int l = 0; l < k; l++)
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++){
                c[i][j] += a[i][l] * b[l][j];
            }

    return 0;
}

int matmult_knm(int m, int n, int k, double** a, double** b, double** c)
{
    memset(*c, 0, m*n*sizeof(double));
    for (int l = 0; l < k; l++)
        for (int j = 0; j < n; j++)
            for (int i = 0; i < m; i++){
                c[i][j] += a[i][l] * b[l][j];
            }

    return 0;
}


/*
*****************
EXERCISE 4
*****************
*/

int matmult_blk(int m, int n, int k, double** a, double** b, double** c, int bs)
{
    memset(*c, 0, sizeof(double) * m * n);
    for (int start_m = 0; start_m < m; start_m += bs){
        int min_m = min(m, start_m + bs);
        for (int start_k = 0; start_k < k; start_k += bs){
            int min_k = min(k, start_k + bs);
            for (int start_n = 0; start_n < n; start_n += bs){
                int min_n = min(n, start_n + bs);
                for (int now_m = start_m; now_m < min_m; now_m++){
                    for (int now_k = start_k; now_k < min_k; now_k++){
                        for (int now_n = start_n; now_n < min_n; now_n++){
                         c[now_m][now_n] += a[now_m][now_k] * b[now_k][now_n];
                        }
                    }
                }
            }
        }
    }
 return 0;
}