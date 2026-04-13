#include "pch.h"
#include "CppUnitTest.h"
#include "../user/user.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDriver
{
	TEST_CLASS(CalculateRentalCostFunctionalTests)
	{
	public:

		TEST_METHOD(Valid_Test_One)
		{
			int months = 12;
			double price = 1200.00;
			double taxRate = 1.13;
			Assert::AreEqual(16272, calculateCost(months, price, taxRate));
		}
		TEST_METHOD(Valid_Test_Two)
		{
			int months = 24;
			double price = 4021.69;
			double taxRate = 1.13;
			Assert::AreEqual(109068.2328, calculateCost(months, price, taxRate));
		}
	};
	TEST_CLASS(CalculateRentalCostExceptionTests)
	{
	public:

		TEST_METHOD(Time_Is_Negative)
		{
			int months = -24;
			double price = 4021.69;
			double taxRate = 1.13;
			Assert::AreEqual(-1, calculateCost(months, price, taxRate));
		}
		TEST_METHOD(Cost_Is_Negative)
		{
			int months = 24;
			double price = -4021.69;
			double taxRate = 1.13;
			Assert::AreEqual(-1, calculateCost(months, price, taxRate));
		}
		TEST_METHOD(Time_And_Cost_Are_Negative)
		{
			int months = -24;
			double price = -4021.69;
			double taxRate = 1.13;
			Assert::AreEqual(-1, calculateCost(months, price, taxRate));
		}
	};
	TEST_CLASS(CalculateRentalCostBoundaryTests)
	{
	public:

		TEST_METHOD(Time_Is_Zero)
		{
			int months = 0;
			double price = 4021.69;
			double taxRate = 1.13;
			Assert::AreEqual(-1, calculateCost(months, price, taxRate));
		}
		TEST_METHOD(Cost_Is_Zero)
		{
			int months = 24;
			double price = 0.00;
			double taxRate = 1.13;
			Assert::AreEqual(-1, calculateCost(months, price, taxRate));
		}
		TEST_METHOD(Time_And_Cost_Are_Zero)
		{
			int months = 0;
			double price = 0;
			double taxRate = 1.13;
			Assert::AreEqual(-1, calculateCost(months, price, taxRate));
		}
	};
}