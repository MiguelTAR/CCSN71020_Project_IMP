#include "pch.h"
#include "CppUnitTest.h"
#include "../project/listing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDriver
{
	TEST_CLASS(SearchListingFunctionalTests)
	{
	public:

		TEST_METHOD(KitchenerCondoTest)
		{
			char type[] = "Condo";
			double price = 1200.00;
			int bedrooms = 3;
			int bathrooms = 2;
			char location[] = "Kitchener";
			Assert::AreEqual(1, searchListing(type[], price, bathrooms, bedrooms, location[]));
		}
		TEST_METHOD(CambridgeCondoTest)
		{
			char type[] = "Condo";
			double price = 1200.00;
			int bedrooms = 3;
			int bathrooms = 2;
			char location[] = "Cambridge";
			Assert::AreEqual(1, searchListing(type[], price, bathrooms, bedrooms, location[]));
		}
		TEST_METHOD(WaterlooCondoTest)
		{
			char type[] = "Condo";
			double price = 1200.00;
			int bedrooms = 3;
			int bathrooms = 2;
			char location[] = "Waterloo";
			Assert::AreEqual(1, searchListing(type[], price, bathrooms, bedrooms, location[]));
		}
		TEST_METHOD(KitchenerApartmentTest)
		{
			char type[] = "Apartment";
			double price = 1200.00;
			int bedrooms = 3;
			int bathrooms = 2;
			char location[] = "Kitchener";
			Assert::AreEqual(1, searchListing(type[], price, bathrooms, bedrooms, location[]));
		}
		TEST_METHOD(CambridgeApartmentTest)
		{
			char type[] = "Apartment";
			double price = 1200.00;
			int bedrooms = 3;
			int bathrooms = 2;
			char location[] = "Cambridge";
			Assert::AreEqual(1, searchListing(type[], price, bathrooms, bedrooms, location[]));
		}
		TEST_METHOD(WaterlooApartmentTest)
		{
			char type[] = "Apartment";
			double price = 1200.00;
			int bedrooms = 3;
			int bathrooms = 2;
			char location[] = "Waterloo";
			Assert::AreEqual(1, searchListing(type[], price, bathrooms, bedrooms, location[]));
		}
		TEST_METHOD(KitchenerTownhouseTest)
		{
			char type[] = "Condo";
			double price = 1200.00;
			int bedrooms = 3;
			int bathrooms = 2;
			char location[] = "Kitchener";
			Assert::AreEqual(1, searchListing(type[], price, bathrooms, bedrooms, location[]));
		}
		TEST_METHOD(CambridgeTownhouseTest)
		{
			char type[] = "Townhouse";
			double price = 1200.00;
			int bedrooms = 3;
			int bathrooms = 2;
			char location[] = "Cambridge";
			Assert::AreEqual(1, searchListing(type[], price, bathrooms, bedrooms, location[]));
		}
		TEST_METHOD(WaterlooTownhouseTest)
		{
			char type[] = "Townhouse";
			double price = 1200.00;
			int bedrooms = 3;
			int bathrooms = 2;
			char location[] = "Waterloo";
			Assert::AreEqual(1, searchListing(type[], price, bathrooms, bedrooms, location[]));
		}
	};
	TEST_CLASS(SearchListingExceptionTests)
	{
	public:

		TEST_METHOD(InvalidListingTest)
		{
			char type[] = "Castle";
			double price = 1200.00;
			int bedrooms = 3;
			int bathrooms = 2;
			char location[] = "Waterloo";
			Assert::AreEqual(-1, searchListing(type[], price, bathrooms, bedrooms, location[]));
		}
		TEST_METHOD(PriceIsZero)
		{
			char type[] = "Townhouse";
			double price = 0.00;
			int bedrooms = 3;
			int bathrooms = 2;
			char location[] = "Waterloo";
			Assert::AreEqual(-1, searchListing(type[], price, bathrooms, bedrooms, location[]));
		}
		TEST_METHOD(PriceIsNegative)
		{
			char type[] = "Townhouse";
			double price = -1200.00;
			int bedrooms = 3;
			int bathrooms = 2;
			char location[] = "Waterloo";
			Assert::AreEqual(-1, searchListing(type[], price, bathrooms, bedrooms, location[]));
		}
		TEST_METHOD(BedroomCountIsNegative)
		{
			char type[] = "Townhouse";
			double price = 1200.00;
			int bedrooms = -3;
			int bathrooms = 2;
			char location[] = "Waterloo";
			Assert::AreEqual(-1, searchListing(type[], price, bathrooms, bedrooms, location[]));
		}
		TEST_METHOD(RoomCountIsZero)
		{
			char type[] = "Townhouse";
			double price = 1200.00;
			int bedrooms = 0;
			int bathrooms = 2;
			char location[] = "Waterloo";
			Assert::AreEqual(-1, searchListing(type[], price, bathrooms, bedrooms, location[]));
		}
		TEST_METHOD(EnteredCityIsInvalid)
		{
			char type[] = "Townhouse";
			double price = 1200.00;
			int bedrooms = 3;
			int bathrooms = 2;
			char location[] = "Gotham";
			Assert::AreEqual(-1, searchListing(type[], price, bathrooms, bedrooms, location[]));
		}
		TEST_METHOD(BathroomCountIsNegative)
		{
			char type[] = "Townhouse";
			double price = 1200.00;
			int bedrooms = 3;
			int bathrooms = -2;
			char location[] = "Waterloo";
			Assert::AreEqual(-1, searchListing(type[], price, bathrooms, bedrooms, location[]));
		}
		TEST_METHOD(BedroomCountIsZero)
		{
			char type[] = "Townhouse";
			double price = 1200.00;
			int bedrooms = 0;
			int bathrooms = 2;
			char location[] = "Waterloo";
			Assert::AreEqual(-1, searchListing(type[], price, bathrooms, bedrooms, location[]));
		}
	};
	TEST_CLASS(SearchListingBoundaryTests)
	{
	public:

		TEST_METHOD(TestMethod1)
		{

		}
	};
}