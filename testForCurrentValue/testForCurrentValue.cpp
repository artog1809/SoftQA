#include "pch.h"
#include "CppUnitTest.h"
#include "../SoftQA/SoftQA.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testForCurrentValue
{
	TEST_CLASS(testForCurrentValue)
	{
	public:
		
		TEST_METHOD(matrix3x3)
		{
			complex <double> d[MAXNUM_STR];
			d[0].real(-222.77);
			d[0].imag(1.82);
			d[1].real(-19954);
			d[1].imag(16317.4);
			d[2].real(3300.0);
			d[2].imag(6.6);
			d[3].real(-16654);
			d[3].imag(16324);
			complex <double> a[MAXNUM_STR];
			a[0].real(90.1646);
			a[0].imag(-72.5111);
			a[1].real(-14.8123);
			a[1].imag(-0.150641);
			a[2].real(75.3524);
			a[2].imag(-72.6618);
			complex <double> cv[MAXNUM_STR];
			int bc = 3;
			currentValue(d, cv, bc);

			float tmp = abs(cv[0].real() - a[0].real());
			Assert::IsTrue(tmp < 0.1);
			tmp = abs(cv[1].real() - a[1].real());
			Assert::IsTrue(tmp < 0.1);
			tmp = abs(cv[2].real() - a[2].real());
			Assert::IsTrue(tmp < 0.1);
			tmp = abs(cv[0].imag() - a[0].imag());
			Assert::IsTrue(tmp < 0.1);
			tmp = abs(cv[1].imag() - a[1].imag());
			Assert::IsTrue(tmp < 0.1);
			tmp = abs(cv[2].imag() - a[2].imag());
			Assert::IsTrue(tmp < 0.1);

		}

		TEST_METHOD(matrix2x2)
		{
			complex <double> d[MAXNUM_STR];
			d[0].real(60.7);
			d[0].imag(-74.2);
			d[1].real(-220);
			d[1].imag(0);
			d[2].real(220.0);
			d[2].imag(0);
			complex <double> a[MAXNUM_STR];
			a[0].real(-1.45);
			a[0].imag(-1.77);
			a[1].real(1.45);
			a[1].imag(1.77);
			complex <double> cv[MAXNUM_STR];
			int bc = 2;
			currentValue(d, cv, bc);

			float tmp = abs(cv[0].real() - a[0].real());
			Assert::IsTrue(tmp < 0.1);
			tmp = abs(cv[1].real() - a[1].real());
			Assert::IsTrue(tmp < 0.1);
			tmp = abs(cv[0].imag() - a[0].imag());
			Assert::IsTrue(tmp < 0.1);
			tmp = abs(cv[1].imag() - a[1].imag());
			Assert::IsTrue(tmp < 0.1);

		}
	};
}
