#include<cblas.h>   // <strong>����cblas.h�ļ��Ѿ�����������Ŀ¼�У�ֻ����˫���� </strong>
#include<iostream>
using namespace std;
int main(void) {
	const enum CBLAS_ORDER Order = CblasRowMajor;
	const enum CBLAS_TRANSPOSE TransA = CblasNoTrans;
	const enum CBLAS_TRANSPOSE TransB = CblasNoTrans;
	const int M = 4;//A��������C������
	const int N = 2;//B��������C������
	const int K = 3;//A��������B������
	const float alpha = 1;
	const float beta = 0;
	const int lda = K;//A����
	const int ldb = N;//B����
	const int ldc = N;//C����
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