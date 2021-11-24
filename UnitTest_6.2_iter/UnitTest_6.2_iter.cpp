#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_6.2/lab_6.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62iter
{
	TEST_CLASS(UnitTest62iter)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 10;
			int a[n] = { -1, 0, -4, 5, 6, 2, 10,7, 9, -10 };

			int Sorted[n] = { 10, 9, 7, 6, 5, 2, 0, -1, -4, -10 };

			Sort(a,n);

			for (int i = 0; i < n; i++)
				Assert::AreEqual(Sorted[i], a[i]);
		}
	};
}
