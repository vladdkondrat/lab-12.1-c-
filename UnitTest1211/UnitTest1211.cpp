#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 12.1 c++/labb 12.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1211
{
	TEST_CLASS(UnitTest1211)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const string fileName = "test_numbers.txt";

			ofstream file(fileName);
			file << "5 10 -3 8 0\n";
			file.close();

			double minVal, maxVal;
			FindMinMax(fileName, minVal, maxVal);

			Assert::AreEqual(-3.0, minVal, L"Minimum value is incorrect.");
			Assert::AreEqual(10.0, maxVal, L"Maximum value is incorrect.");
		}
	};
}
