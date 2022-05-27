#include "pch.h"
#include "CppUnitTest.h"
#include "../SoftQA/SoftQA.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testsForFullResistanceOfbranch
{
	TEST_CLASS(testsForFullResistanceOfbranch)
	{
	public:
		
		TEST_METHOD(oneBranchWithOneResistor)
		{
			complex <double> z[MAXSIZE_STR];
			int bc = 2;
			float r[2] = { 15,0 };
			float c[2] = { 0,0.00003 };
			float l[2] = { 0,0.03 };
			int v = 50;
			int rk = 1;
			int ck = 2;
			int lk = 2;
			fullResistanceOfBranch(z, r, c, l, v, rk, ck, lk, bc);

			complex <double> x[MAXSIZE_STR];
			x[0].real(15.0);
			x[0].imag(0.0);
			x[1].real(0.0);
			x[1].imag(68.3618);


			Assert::AreEqual(x[0].real(), z[0].real());
			Assert::AreEqual(x[1].real(), z[1].real());
			Assert::AreEqual(x[0].imag(), z[0].imag());
			float tmp = abs(z[1].imag() - x[1].imag());
			Assert::IsTrue(tmp < 0.1);
		};



		TEST_METHOD(onlyResistors)
		{
			complex <double> z[MAXSIZE_STR];
			int bc = 2;
			float r[2] = { 15,15 };
			float c[2] = { 0,0 };
			float l[2] = { 0,0 };
			int v = 50;
			int rk = 1;
			int ck = 0;
			int lk = 0;
			fullResistanceOfBranch(z, r, c, l, v, rk, ck, lk, bc);

			complex <double> x[MAXSIZE_STR];
			x[0].real(15.0);
			x[0].imag(0.0);
			x[1].real(15.0);
			x[1].imag(0.0);


			Assert::AreEqual(x[0].real(), z[0].real());
			Assert::AreEqual(x[1].real(), z[1].real());
			Assert::AreEqual(x[0].imag(), z[0].imag());
			Assert::AreEqual(x[1].imag(), z[1].imag());
		};

		TEST_METHOD(condenAndResistorCoilAndResistor)
		{
			complex <double> z[MAXSIZE_STR];
			int bc = 2;
			float r[2] = { 15,15 };
			float c[2] = { 0.00003,0 };
			float l[2] = { 0,0.03 };
			int v = 50;
			int rk = 1;
			int ck = 1;
			int lk = 2;
			fullResistanceOfBranch(z, r, c, l, v, rk, ck, lk, bc);

			complex <double> x[MAXSIZE_STR];
			x[0].real(75.7796);
			x[0].imag(74.2802);
			x[1].real(15.2);
			x[1].imag(2.9);


			float tmp = abs(z[0].real() - x[0].real());
			Assert::IsTrue(tmp < 0.1);
			tmp = abs(z[0].imag() - x[0].imag());
			Assert::IsTrue(tmp < 0.1);
			tmp = abs(z[1].real() - x[1].real());
			Assert::IsTrue(tmp < 0.1);
			tmp = abs(z[1].imag() - x[1].imag());
			Assert::IsTrue(tmp < 0.1);
		};

		TEST_METHOD(noResistors)
		{
			complex <double> z[MAXSIZE_STR];
			int bc = 2;
			float r[2] = { 0,0 };
			float c[2] = { 0.00003,0.00007 };
			float l[2] = { 0.06,0.03 };
			int v = 50;
			int rk = 0;
			int ck = 1;
			int lk = 1;
			fullResistanceOfBranch(z, r, c, l, v, rk, ck, lk, bc);

			complex <double> x[MAXSIZE_STR];
			x[0].real(0.0);
			x[0].imag(61.69);
			x[1].real(0.0);
			x[1].imag(25.48);


			Assert::AreEqual(x[0].real(), z[0].real());
			Assert::AreEqual(x[1].real(), z[1].real());
			float tmp = abs(z[0].imag() - x[0].imag());
			Assert::IsTrue(tmp < 0.1);
			tmp = abs(z[1].imag() - x[1].imag());
			Assert::IsTrue(tmp < 0.1);
		};

		TEST_METHOD(allTypesOfElements)
		{
			complex <double> z[MAXSIZE_STR];
			int bc = 2;
			float r[2] = { 10,15 };
			float c[2] = { 0.00003,0.00007 };
			float l[2] = { 0.06,0.03 };
			int v = 50;
			int rk = 1;
			int ck = 1;
			int lk = 1;
			fullResistanceOfBranch(z, r, c, l, v, rk, ck, lk, bc);

			complex <double> x[MAXSIZE_STR];
			x[0].real(62.10);
			x[0].imag(61.29);
			x[1].real(27.78);
			x[1].imag(23.38);


			float tmp = abs(z[0].real() - x[0].real());
			Assert::IsTrue(tmp < 0.1);
			tmp = abs(z[0].imag() - x[0].imag());
			Assert::IsTrue(tmp < 0.1);
			tmp = abs(z[1].real() - x[1].real());
			Assert::IsTrue(tmp < 0.1);
			tmp = abs(z[1].imag() - x[1].imag());
			Assert::IsTrue(tmp < 0.1);
		};
	};
}
