#include <cblas.h>
#include <cstdio>

// PyTorch:
//
// extern "C" void dgemm_(char *transa, char *transb, int *m, int *n, int *k, double *alpha, const double *a, int *lda, const double *b, int *ldb, double *beta, double *c, int *ldc);

extern "C" void dgemm_(char *transa, char *transb, int *m, int *n, int *k, double *alpha, const double *a, int *lda, const double *b, int *ldb, double *beta, double *c, int *ldc) {
	std::printf("DGEMM(%d, %d, %d) is called\n", *m, *n, *k);
}
