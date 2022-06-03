﻿
#include <iostream>
#include "SoftQA.h"
#include <fstream>

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

/*!	Создать частную матрицу для вычисления ее определителя */
void createPersonalMatrix(complex<double>(*matrix)[MAXSIZE_STR], complex<double>* Z, float U, int num, int branchCount)
{
	if (branchCount == 3)
	{
		if (num == 0)
		{
			matrix[0][0] = complex<double>(0, 0);
			matrix[0][1] = complex<double>(1, 0);
			matrix[0][2] = complex<double>(-1, 0);

			matrix[1][0] = complex<double>(U, 0);
			matrix[1][1] = Z[1];
			matrix[1][2] = complex<double>(0, 0);

			matrix[2][0] = complex<double>(0, 0);
			matrix[2][1] = Z[1];
			matrix[2][2] = Z[2];
		}
		else if (num == 1)
		{
			matrix[0][0] = complex<double>(1, 0);
			matrix[0][1] = complex<double>(0, 0);
			matrix[0][2] = complex<double>(-1, 0);

			matrix[1][0] = Z[0];
			matrix[1][1] = complex<double>(U, 0);
			matrix[1][2] = complex<double>(0, 0);

			matrix[2][0] = complex<double>(0, 0);
			matrix[2][1] = complex<double>(0, 0);
			matrix[2][2] = Z[2];
		}
		else if (num == 2)
		{
			matrix[0][0] = complex<double>(1, 0);
			matrix[0][1] = complex<double>(1, 0);
			matrix[0][2] = complex<double>(0, 0);

			matrix[1][0] = Z[0];
			matrix[1][1] = Z[1];
			matrix[1][2] = complex<double>(U, 0);

			matrix[2][0] = complex<double>(0, 0);
			matrix[2][1] = Z[1];
			matrix[2][2] = complex<double>(0, 0);
		}
	}
	else if (branchCount == 2)
	{
		if (num == 0)
		{
			matrix[0][0] = complex<double>(0, 0);
			matrix[0][1] = complex<double>(1, 0);

			matrix[1][0] = complex<double>(U, 0);
			matrix[1][1] = Z[1];

		}
		else if (num == 1)
		{
			matrix[0][0] = complex<double>(1, 0);
			matrix[0][1] = complex<double>(0, 0);

			matrix[1][0] = Z[0];
			matrix[1][1] = complex<double>(U, 0);

		}
	}

}


/*!	Вычислить определитель переданной матрицы */
void determinantOfMatrix(complex<double>* determinant, complex<double>(*matrix)[MAXSIZE_STR], int num, int branchCount)
{

	if (branchCount == 3)
	{
		complex<double>firstMinor = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]);
		complex<double>secondMinor = matrix[1][0] * (matrix[0][1] * matrix[2][2] - matrix[0][2] * matrix[2][1]);
		complex<double>thirdMinor = matrix[2][0] * (matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1]);

		determinant[num] = firstMinor - secondMinor + thirdMinor;
	}

	if (branchCount == 2)
	{
		determinant[num] = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}
}


/*!	Функция для подсчета тока в ветви */
void currentValue(complex<double>* determinant, complex<double>* currentValue, int branchCount)
{
	int k = 1;
	for (int i = 0; i < branchCount; i++)
	{
		currentValue[i] = determinant[k] / determinant[0];
		cout << currentValue[i] << endl;
		k++;
	}
}

/*!	Осуществить считывание входных данных из файла */
void inputData(char(*buff)[MAXSIZE_STR], size_t n) {
	ifstream fin("input1.csv");
	if (fin.is_open())
	{
		for (int i = 0; i < 20; i++)
		{
			fin.getline(buff[i], 81);
		}
		fin.close();
	}
	else
	{
		cout << ("whoops");
	}
}

/*!	Упорядочить полученные на входе значения, т.е присвоить переменным нужные значения в нужном формате */
void orderingInputData(char(*buff)[MAXSIZE_STR], size_t n, float* R, float* L, float* C, int* V, int* U, int* resistCount,
	int* condenCount, int* coilCount, char(*chain)[MAXSIZE_STR], int* Rk, int* Lk, int* Ck, int* branchCount) {

	//Преобразование данных
	char buffer[20];
	*V = atof(&buff[0][2]);
	*U = atof(&buff[1][2]);
	strcpy_s(buffer, &buff[2][12]);
	*resistCount = atoi(buffer);
	strcpy_s(buffer, &buff[3][12]);
	*condenCount = atoi(buffer);
	strcpy_s(buffer, &buff[4][10]);
	*coilCount = atoi(buffer);
	*Rk = atoi(&buff[5][1]);
	n = *Rk;
	for (int i = 5; i < 5 + *resistCount; i++)
	{
		R[n - 1] = atof(&buff[i][3]);
		n++;
	}
	*Ck = atoi(&buff[*resistCount + 5][1]);
	n = *Ck;
	for (int i = *resistCount + 5; i < 5 + *resistCount + *condenCount; i++)
	{
		C[n - 1] = atof(&buff[i][3]);
		n++;
	}
	*Lk = atoi(&buff[*resistCount + *condenCount + 5][1]);
	n = *Lk;
	for (int i = *resistCount + *condenCount + 5; i < 5 + *resistCount + *condenCount + *coilCount; i++)
	{
		L[n - 1] = atof(&buff[i][3]);
		n++;
	}

	int k = 0;
	for (int i = *resistCount + *condenCount + *coilCount + 5; i < 20; i++)
	{
		strcpy_s(chain[k], buff[i]);
		k++;

	}

	if (strlen(chain[0]) < 4)
		*branchCount = 1;
	else if (strlen(chain[0]) == 5)
		*branchCount = 2;
	else if (strlen(chain[0]) == 8)
		*branchCount = 3;
}


/*!	Записать величины полученных токов в выходной файл */
void outputCurrentValues(complex<double>* currentValue, int branchCount)
{
	ofstream myfile("D:/4 term/knpo/knpo/knpo/output.txt");

	if (!myfile)  //если файл не открылся
	{
		cout << "Sorry" << endl;
	}
	else
		for (int i = 0; i < branchCount; i++)
		{
			myfile << currentValue[i] << endl;
		}
	myfile.close();
}