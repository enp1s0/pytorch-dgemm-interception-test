#include <cblas.h>
#include <cstdio>

// PyTorch:
//
// See https://github.com/pytorch/pytorch/blob/454f4e98a2c386bbe162b056cf8af07d0abd8bc4/aten/src/ATen/native/CPUBlas.cpp

void dgemm_core(const CBLAS_LAYOUT layout, const CBLAS_TRANSPOSE TransA,
                 const CBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const double alpha, const double  *A,
                 const int lda, const double  *B, const int ldb,
                 const double beta, double  *C, const int ldc, const char* name) {
	std::printf("DGEMM(%d, %d, %d) is called [%s]\n", M, N, K, name);
}

extern "C" void cblas_dgemm(const CBLAS_LAYOUT layout, const CBLAS_TRANSPOSE TransA,
                 const CBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const double alpha, const double  *A,
                 const int lda, const double  *B, const int ldb,
                 const double beta, double  *C, const int ldc) {
	dgemm_core(
		layout,
		TransA, TransB,
		M, N, K,
		alpha,
		A, lda,
		B, ldb,
		beta,
		C, ldc,
		__func__
		);
}

extern "C" void dgemm_(char *transa, char *transb, int *m, int *n, int *k, double *alpha, const double *a, int *lda, const double *b, int *ldb, double *beta, double *c, int *ldc) {
	dgemm_core(
		CblasColMajor,
		*transa == 'N' ? CblasNoTrans : CblasTrans,
		*transb == 'N' ? CblasNoTrans : CblasTrans,
		*m, *n, *k,
		*alpha,
		a, *lda,
		b, *ldb,
		*beta,
		c, *ldc,
		__func__
		);
}
