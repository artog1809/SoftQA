#include "pch.h"
#include "CppUnitTest.h"
#include "../SoftQA/SoftQA.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testForDeterminantOfMatrix
{
	TEST_CLASS(testForDeterminantOfMatrix)
	{
	public:
		
		TEST_METHOD(matrix3x3)
		{
			complex<double> m2[MAXNUM_STR][MAXSIZE_STR];

			m2[0][0].real(1.0);      m2[0][0].imag(0);
			m2[0][1].real(1.0);		 m2[0][1].imag(0);
			m2[0][2].real(-1.0);	 m2[0][2].imag(0);
			m2[1][0].real(15.0);     m2[1][0].imag(0);
			m2[1][1].real(75.7796);  m2[1][1].imag(74.2802);
			m2[1][2].real(0.0);      m2[1][2].imag(0);
			m2[2][0].real(0.0);      m2[2][0].imag(0);
			m2[2][1].real(75.7796);  m2[2][1].imag(74.2802);
			m2[2][2].real(15.2);     m2[2][2].imag(2.9);

			complex <double> d[MAXNUM_STR];
			d[0].real(-428.257);
			d[0].imag(191.117);
			complex <double> a[MAXNUM_STR];

			int n = 0;
			int bc = 3;

			determinantOfMatrix(a, m2, n, bc);
			float tmp = abs(a[0].real() - d[0].real());
			Assert::IsTrue(tmp < 0.1);
			tmp = abs(a[0].imag() - d[0].imag());
			Assert::IsTrue(tmp < 0.1);

		};

		TEST_METHOD(matrix2x2)
		{
			complex<double> m2[MAXNUM_STR][MAXSIZE_STR];

			m2[0][0].real(1.0);      m2[0][0].imag(0);
			m2[0][1].real(1.0);		 m2[0][1].imag(0);
			m2[1][0].real(15.0);     m2[1][0].imag(0);
			m2[1][1].real(75.7796);  m2[1][1].imag(74.2802);

			complex <double> d[MAXNUM_STR];
			d[0].real(60.7796);
			d[0].imag(74.2802);
			complex <double> a[MAXNUM_STR];

			int n = 0;
			int bc = 2;

			determinantOfMatrix(a, m2, n, bc);

			Assert::AreEqual(d[0].real(), a[0].real());
			Assert::AreEqual(d[0].imag(), a[0].imag());
			/*float tmp = abs(a[0].real() - d[0].real());
			Assert::IsTrue(tmp < 0.1);
			tmp = abs(a[0].imag() - d[0].imag());
			Assert::IsTrue(tmp < 0.1);*/

		};
	};
}
