#include<cblas.h>   // <strong>由于cblas.h文件已经拷贝到工作目录中，只需用双引号 </strong>
#include<iostream>
using namespace std;
int main(void) {
	const enum CBLAS_ORDER Order = CblasRowMajor;
	const enum CBLAS_TRANSPOSE TransA = CblasNoTrans;
	const enum CBLAS_TRANSPOSE TransB = CblasNoTrans;
	const int M = 4;//A的行数，C的行数
	const int N = 2;//B的列数，C的列数
	const int K = 3;//A的列数，B的行数
	const float alpha = 1;
	const float beta = 0;
	const int lda = K;//A的列
	const int ldb = N;//B的列
	const int ldc = N;//C的列
	const float A[K*M] = { 1,2,3,4,5,6,7,8,9,8,7,6 };
	const float B[K*N] = { 5,4,3,2,1,0 };
	float C[M*N];

	cblas_sgemm(Order, TransA, TransB, M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << C[i*N + j] << "/t" << endl;
		}
	}
	system("pause");

	return EXIT_SUCCESS;
}