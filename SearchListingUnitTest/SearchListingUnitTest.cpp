#include "pch.h"
#include "CppUnitTest.h"
#include "../project5/listing.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDriver
{
	TEST_CLASS(SearchListingFunctionalTests)
	{
	public:

		TEST_METHOD(Kitchener_Condo_Test)
		{
			const char filename[] = "example.txt";
			char type[] = "Condo";
			double price = 1800.00;
			int bedrooms = 3;
			char location[] = "Kitchener";
			Assert::AreEqual(1, search_listing_txt(filename, type, location, bedrooms, price));
		}
		TEST_METHOD(Cambridge_Condo_Test)
		{
			const char filename[] = "example.txt";
			char type[] = "Condo";
			double price = 1800.00;
			int bedrooms = 2;
			char location[] = "Cambridge";
			Assert::AreEqual(1, search_listing_txt(filename, type, location, bedrooms, price));
		}
		TEST_METHOD(Waterloo_Condo_Test)
		{
			const char filename[] = "example.txt";
			char type[] = "Condo";
			double price = 1800.00;
			int bedrooms = 2;
			char location[] = "Waterloo";
			Assert::AreEqual(1, search_listing_txt(filename, type, location, bedrooms, price));
		}
		TEST_METHOD(Kitchener_Apartment_Test)
		{
			const char filename[] = "example.txt";
			char type[] = "Apartment";
			double price = 1400.00;
			int bedrooms = 1;
			char location[] = "Kitchener";
			Assert::AreEqual(1, search_listing_txt(filename, type, location, bedrooms, price));
		}
		TEST_METHOD(Cambridge_Apartment_Test)
		{
			const char filename[] = "example.txt";
			char type[] = "Apartment";
			double price = 1200.00;
			int bedrooms = 1;
			char location[] = "Cambridge";
			Assert::AreEqual(1, search_listing_txt(filename, type, location, bedrooms, price));
		}
		TEST_METHOD(Waterloo_Apartment_Test)
		{
			const char filename[] = "example.txt";
			char type[] = "Apartment";
			double price = 1200.00;
			int bedrooms = 1;
			char location[] = "Waterloo";
			Assert::AreEqual(1, search_listing_txt(filename, type, location, bedrooms, price));
		}
		TEST_METHOD(Kitchener_Townhouse_Test)
		{
			const char filename[] = "example.txt";
			char type[] = "Condo";
			double price = 2200.00;
			int bedrooms = 3;
			char location[] = "Kitchener";
			Assert::AreEqual(1, search_listing_txt(filename, type, location, bedrooms, price));
		}
		TEST_METHOD(Cambridge_Townhouse_Test)
		{
			const char filename[] = "example.txt";
			char type[] = "Townhouse";
			double price = 2200.00;
			int bedrooms = 4;
			char location[] = "Cambridge";
			Assert::AreEqual(1, search_listing_txt(filename, type, location, bedrooms, price));
		}
		TEST_METHOD(Waterloo_Townhouse_Test)
		{
			const char filename[] = "example.txt";
			char type[] = "Townhouse";
			double price = 2250.00;
			int bedrooms = 3;
			char location[] = "Waterloo";
			Assert::AreEqual(1, search_listing_txt(filename, type, location, bedrooms, price));
		}
	};
	TEST_CLASS(SearchListingExceptionTests)
	{
	public:

		TEST_METHOD(Invalid_Listing_Test)
		{
			const char filename[] = "example.txt";
			char type[] = "Castle";
			double price = 1200.00;
			int bedrooms = 3;
			char location[] = "Waterloo";
			Assert::AreEqual(0, search_listing_txt(filename, type, location, bedrooms, price));
		}
		TEST_METHOD(Price_Is_Zero)
		{
			const char filename[] = "example.txt";
			char type[] = "Townhouse";
			double price = 0.00;
			int bedrooms = 3;
			char location[] = "Waterloo";
			Assert::AreEqual(0, search_listing_txt(filename, type, location, bedrooms, price));
		}
		TEST_METHOD(Price_Is_Negative)
		{
			const char filename[] = "example.txt";
			char type[] = "Townhouse";
			double price = -1200.00;
			int bedrooms = 3;
			char location[] = "Waterloo";
			Assert::AreEqual(0, search_listing_txt(filename, type, location, bedrooms, price));
		}
		TEST_METHOD(Bedroom_Count_Is_Negative)
		{
			const char filename[] = "example.txt";
			char type[] = "Townhouse";
			double price = 1200.00;
			int bedrooms = -3;
			char location[] = "Waterloo";
			Assert::AreEqual(0, search_listing_txt(filename, type, location, bedrooms, price));
		}
		TEST_METHOD(Bedroom_Count_Is_Zero)
		{
			const char filename[] = "example.txt";
			char type[] = "Townhouse";
			double price = 1200.00;
			int bedrooms = 0;
			char location[] = "Waterloo";
			Assert::AreEqual(0, search_listing_txt(filename, type, location, bedrooms, price));
		}
		TEST_METHOD(Entered_City_Is_Invalid)
		{
			const char filename[] = "example.txt";
			char type[] = "Townhouse";
			double price = 1200.00;
			int bedrooms = 3;
			char location[] = "Gotham";
			Assert::AreEqual(0, search_listing_txt(filename, type, location, bedrooms, price));
		}
	};
	TEST_CLASS(SearchListingBoundaryTests)//none needed because the funcion either passes or failes and any boundary case would be considered a failure
	{
	public:

		TEST_METHOD(TestMethod1)
		{

		}
	};
}