
#include <iostream>
#include "SoftQA.h"


int main()
{
    std::cout << "Hello World!\n";
}



/*! Получить полные сопротивления каждой ветви */
void fullResistanceOfBranch(complex<double>* Z, float* R, float* C, float* L, int V, int Rk, int Ck, int Lk, int branchCount) {
	float Xl[MAXSIZE_STR];
	float Xc[MAXSIZE_STR];
	float Xlc[MAXSIZE_STR];
	for (int i = 0; i < branchCount; i++)
	{
		Xl[i] = L[i] * 2 * PI * V;
	}
	for (int i = 0; i < branchCount; i++)
	{
		if (C[i] != 0)
		{
			Xc[i] = 1 / (C[i] * 2 * PI * V);
		}
		else
		{
			Xc[i] = 0;
		}

	}

	for (int i = 0; i < branchCount; i++)
	{
		Xlc[i] = pow((Xl[i] - Xc[i]), 2);
	}

	for (int i = 0; i < branchCount; i++)
	{
		Z[i] = sqrt(complex<double>(pow(R[i], 2), Xlc[i]));
		if (Z[i].real() - Z[i].imag() < 0.001)
		{
			Z[i].real(0);
		}
		cout << Z[i] << endl;
	}

}


/*!	Создать основную матрицу для вычисления ее определителя */
void createMainMatrix(complex<double>(*matrix)[MAXSIZE_STR], size_t n, complex<double>* Z, int branchCount)
{
	if (branchCount == 3)
	{
		matrix[0][0] = complex<double>(1, 0);
		matrix[0][1] = complex<double>(1, 0);
		matrix[0][2] = complex<double>(-1, 0);

		matrix[1][0] = Z[0];
		matrix[1][1] = Z[1];
		matrix[1][2] = complex<double>(0, 0);

		matrix[2][0] = complex<double>(0, 0);
		matrix[2][1] = Z[1];
		matrix[2][2] = Z[2];
	}
	else if (branchCount == 2)
	{
		matrix[0][0] = complex<double>(1, 0);
		matrix[0][1] = complex<double>(1, 0);

		matrix[1][0] = Z[0];
		matrix[1][1] = Z[1];
	}
}

