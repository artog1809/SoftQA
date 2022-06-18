#pragma once
#include <complex>
using namespace std;

const double  PI = 3.1416;
const int MAXNUM_STR = 20;		//������������ ���������� �����		
const int MAXSIZE_STR = 81;		//������������ ����� ������

/*���� ���������� ������������ ��������*/


/*!	����������� ���������� ������� ������ �� �����
	\param[in/out] buff - ������ �� �������� �����
*/
void inputData(char(*buff)[MAXSIZE_STR], size_t n, string inputFile);



/*!	����������� ���������� �� ����� ��������, �.� ��������� ���������� ������ �������� � ������ �������
	\param[in] buff - ������ �� �������� �����
	\param[in/out] R - ������ ������������� ���������� ���� ����
	\param[in/out]	L - ������ �������������� ������� ���� ����
	\param[in/out] C - ������ �������� ������������� ���� ����
	\param[in/out] V - ������� ����������� ����
	\param[in/out] U - ���������� ���������
	\param[in/out] resistCount - ���������� ����������
	\param[in/out] condenCount - ���������� �������������
	\param[in/out] coilCount - ���������� �������
	\param[in/out] chain - ������������������ ��������� ����
	\param[in/out] Rk - ����� ������ ����� � ������� ���������� ��������
	\param[in/out] Lk - ����� ������ ����� � ������� ����������� �������
	\param[in/out] Ck - ����� ������ ����� � ������� ���������� �����������
	\param[in/out] branchCount - ���������� ������ � ����
*/
void orderingInputData(char(*buff)[MAXSIZE_STR], size_t n, float* R, float* L, float* C, int* V, int* U, int* resistCount,
	int* condenCount, int* coilCount, char(*chain)[MAXSIZE_STR], int* Rk, int* Lk, int* Ck, int* branchCount);


/*! �������� ������ ������������� ������ �����
	\param[in] V - ������� ����������� ����
	\param[in] R - ������ ������������� ���������� ���� ����
	\param[in] L - ������ �������������� ������� ���� ����
	\param[in] C - ������ �������� ������������� ���� ����
	\param[in] Rk - ����� ������ ����� � ������� ���������� ��������
	\param[in] Lk - ����� ������ ����� � ������� ����������� �������
	\param[in] Ck - ����� ������ ����� � ������� ���������� �����������
	\param[in] Z - ������ ������ ������������� ����
*/
void fullResistanceOfBranch(complex <double>* Z, float* R, float* C, float* L, int V, int Rk, int Ck, int Lk, int branchCount);


/*!	������� �������� ������� ��� ���������� �� ������������
	\param[in] Z - ������ ������ ������������� ����

	\param[in/out] matrix - �������� �������
*/
void createMainMatrix(complex<double>(*matrix)[MAXSIZE_STR], size_t n, complex<double>* Z, int branchCount);


/*!	������� ������� ������� ��� ���������� �� ������������
	\param[in] Z - ������ ������ ������������� ����
	\param[in] num - ����� �������
	\param[in] U - ���������� ���������
	\param[in/out] personalMatrix - ������� �������
*/
void createPersonalMatrix(complex<double>(*matrix)[MAXSIZE_STR], complex<double>* Z, float U, int num, int branchCount);


/*!	��������� ������������ ���������� �������
	\param[in] matrix - ������������ �������
	\param[in] num - ����� �������
	\param[in/out] determinant - ������ ������������� ������
*/
void determinantOfMatrix(complex<double>* determinant, complex<double>(*matrix)[MAXSIZE_STR], int num, int branchCount);


/*!	������� ��� �������� ���� � �����
	\param[in] determinant - ������ ������������� ������
	\param[in/out] currentValue - ������ �������� ����� � ������
*/
void currentValue(complex<double>* determinant, complex<double>* currentValue, int branchCount);


/*!	�������� �������� ���������� ����� � �������� ����
	\param[in] currentValue - ������ �������� ����� � ������
*/
void outputCurrentValues(complex<double>* currentValue, int branchCount, string outputFile);