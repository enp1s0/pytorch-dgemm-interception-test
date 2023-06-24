#include <cblas.h>
#include <cstdio>

// PyTorch:
//
// extern "C" void dgemm_(char *transa, char *transb, int *m, int *n, int *k, double *alpha, const double *a, int *lda, const double *b, int *ldb, double *beta, double *c, int *ldc);

void dgemm_core(
		char *transa, char *transb, int *m, int *n, int *k, double *alpha, const double *a, int *lda, const double *b, int *ldb, double *beta, double *c, int *ldc
		) {
	std::printf("DGEMM(%d, %d, %d) is called\n", *m, *n, *k);
}

extern "C" void dgemm_(char *transa, char *transb, int *m, int *n, int *k, double *alpha, const double *a, int *lda, const double *b, int *ldb, double *beta, double *c, int *ldc) {
	dgemm_core(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
}
