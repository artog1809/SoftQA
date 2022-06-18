#pragma once
#include <complex>
using namespace std;

const double  PI = 3.1416;
const int MAXNUM_STR = 20;		//Маскимальное количество строк		
const int MAXSIZE_STR = 81;		//Максимальная длина строки

/*Блок объявления используемых структур*/


/*!	Осуществить считывание входных данных из файла
	\param[in/out] buff - данные из входного файла
*/
void inputData(char(*buff)[MAXSIZE_STR], size_t n, string inputFile);



/*!	Упорядочить полученные на входе значения, т.е присвоить переменным нужные значения в нужном формате
	\param[in] buff - данные из входного файла
	\param[in/out] R - массив сопротивлений резисторов всей цепи
	\param[in/out]	L - массив индуктивностей катушек всей цепи
	\param[in/out] C - массив емкостей конденсаторов всей цепи
	\param[in/out] V - частота переменного тока
	\param[in/out] U - напряжение источника
	\param[in/out] resistCount - количество резисторов
	\param[in/out] condenCount - количество конденсаторов
	\param[in/out] coilCount - количество катушек
	\param[in/out] chain - последовательность элементов цепи
	\param[in/out] Rk - номер первой ветви в который встретился резистор
	\param[in/out] Lk - номер первой ветви в который встретилась катушка
	\param[in/out] Ck - номер первой ветви в который встретился конденсатор
	\param[in/out] branchCount - количество ветвей в цепи
*/
void orderingInputData(char(*buff)[MAXSIZE_STR], size_t n, float* R, float* L, float* C, int* V, int* U, int* resistCount,
	int* condenCount, int* coilCount, char(*chain)[MAXSIZE_STR], int* Rk, int* Lk, int* Ck, int* branchCount);


/*! Получить полные сопротивления каждой ветви
	\param[in] V - частота переменного тока
	\param[in] R - массив сопротивлений резисторов всей цепи
	\param[in] L - массив индуктивностей катушек всей цепи
	\param[in] C - массив емкостей конденсаторов всей цепи
	\param[in] Rk - номер первой ветви в который встретился резистор
	\param[in] Lk - номер первой ветви в который встретилась катушка
	\param[in] Ck - номер первой ветви в который встретился конденсатор
	\param[in] Z - массив полных сопротивлений цепи
*/
void fullResistanceOfBranch(complex <double>* Z, float* R, float* C, float* L, int V, int Rk, int Ck, int Lk, int branchCount);


/*!	Создать основную матрицу для вычисления ее определителя
	\param[in] Z - массив полных сопротивлений цепи

	\param[in/out] matrix - основная матрица
*/
void createMainMatrix(complex<double>(*matrix)[MAXSIZE_STR], size_t n, complex<double>* Z, int branchCount);


/*!	Создать частную матрицу для вычисления ее определителя
	\param[in] Z - массив полных сопротивлений цепи
	\param[in] num - номер матрицы
	\param[in] U - напряжение источника
	\param[in/out] personalMatrix - частная матрица
*/
void createPersonalMatrix(complex<double>(*matrix)[MAXSIZE_STR], complex<double>* Z, float U, int num, int branchCount);


/*!	Вычислить определитель переданной матрицы
	\param[in] matrix - передаваемая матрица
	\param[in] num - номер матрицы
	\param[in/out] determinant - массив определителей матриц
*/
void determinantOfMatrix(complex<double>* determinant, complex<double>(*matrix)[MAXSIZE_STR], int num, int branchCount);


/*!	Функция для подсчета тока в ветви
	\param[in] determinant - массив определителей матриц
	\param[in/out] currentValue - массив значений токов в ветвях
*/
void currentValue(complex<double>* determinant, complex<double>* currentValue, int branchCount);


/*!	Записать величины полученных токов в выходной файл
	\param[in] currentValue - массив значений токов в ветвях
*/
void outputCurrentValues(complex<double>* currentValue, int branchCount, string outputFile);