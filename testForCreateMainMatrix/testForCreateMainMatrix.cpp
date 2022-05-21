#include "pch.h"
#include "CppUnitTest.h"
#include "../SoftQA/SoftQA.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testForCreateMainMatrix
{
	TEST_CLASS(testForCreateMainMatrix)
	{
	public:
		
		TEST_METHOD(threeBranches)
		{
			complex<double> m1[MAXNUM_STR][MAXSIZE_STR];
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

			complex <double> z[MAXNUM_STR];

			z[0].real(15);       z[0].imag(0);
			z[1].real(75.7796);  z[1].imag(74.2802);
			z[2].real(15.2);     z[2].imag(2.9);

			int bc = 3;
			createMainMatrix(m1, MAXNUM_STR, z, bc);
			for (int i = 0; i < bc; i++)
			{
				for (int j = 0; j < bc; j++)
				{
					Assert::AreEqual(m2[i][j].real(), m1[i][j].real());
				}
			}
			for (int i = 0; i < bc; i++)
			{
				for (int j = 0; j < bc; j++)
				{
					Assert::AreEqual(m2[i][j].imag(), m1[i][j].imag());
				}
			}

		};

		TEST_METHOD(twoBranches)
		{
			complex<double> m1[MAXNUM_STR][MAXSIZE_STR];
			complex<double> m2[MAXNUM_STR][MAXSIZE_STR];

			m2[0][0].real(1.0);      m2[0][0].imag(0);
			m2[0][1].real(1.0);		 m2[0][1].imag(0);
			m2[1][0].real(15.0);     m2[1][0].imag(0);
			m2[1][1].real(75.7796);  m2[1][1].imag(74.2802);

			complex <double> z[MAXNUM_STR];

			z[0].real(15);       z[0].imag(0);
			z[1].real(75.7796);  z[1].imag(74.2802);

			int bc = 2;
			createMainMatrix(m1, MAXNUM_STR, z, bc);
			for (int i = 0; i < bc; i++)
			{
				for (int j = 0; j < bc; j++)
				{
					Assert::AreEqual(m2[i][j].real(), m1[i][j].real());
				}
			}
			for (int i = 0; i < bc; i++)
			{
				for (int j = 0; j < bc; j++)
				{
					Assert::AreEqual(m2[i][j].imag(), m1[i][j].imag());
				}
			}

		};
	};
}
