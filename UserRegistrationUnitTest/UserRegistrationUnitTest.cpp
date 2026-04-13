#include "pch.h"
#include "CppUnitTest.h"
#include "../user/user.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDriver
{
	TEST_CLASS(UserRegistrationFunctionalTests)
	{
	public:

		TEST_METHOD(AllValidListings)
		{
			char username[] = "testingnames";
			char email[] = "bestemailever@gmail.com";
			char password[] = "goodpasswordtrustme";
			Assert::AreEqual(1, userRegistration(username, email, password));
		}
		TEST_METHOD(TestMethod1)
		{
			char username[] = "supermanhasnonipples";
			char email[] = "reallythebestemailever@gmail.com";
			char password[] = "reallybadpassword";
			Assert::AreEqual(1, userRegistration(username, email, password));
		}
	};
	TEST_CLASS(UserRegistrationExceptionTests)
	{
	public:

		TEST_METHOD(Password_Too_Long)
		{
			char username[] = "testingnames";
			char email[] = "bestemailever@gmail.com";
			char password[] = "goodpasswordtrustmeaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
			Assert::AreEqual(0, userRegistration(username, email, password));
		}
		TEST_METHOD(Password_Too_Short)
		{
			char username[] = "testingnames";
			char email[] = "bestemailever@gmail.com";
			char password[] = "help";
			Assert::AreEqual(0, userRegistration(username, email, password));
		}
		TEST_METHOD(Invalid_Email_Address)
		{
			char username[] = "testingnames";
			char email[] = "bestemailever.yahoo.com";
			char password[] = "goodpasswordtrustme";
			Assert::AreEqual(0, userRegistration(username, email, password));
		}
		TEST_METHOD(Username_Is_Too_Long)
		{
			char username[] = "testingnamesaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
			char email[] = "bestemailever@gmail.com";
			char password[] = "goodpasswordtrustme";
			Assert::AreEqual(0, userRegistration(username, email, password));
		}
		TEST_METHOD(Username_Is_Too_Short)
		{
			char username[] = "fdsf";
			char email[] = "bestemailever@gmail.com";
			char password[] = "goodpasswordtrustme";
			Assert::AreEqual(0, userRegistration(username, email, password));
		}

	};
	TEST_CLASS(UserRegistrationBoundaryTests)
	{
	public:

		TEST_METHOD(Username_Is_Minimum_Length)
		{
			char username[] = "super";
			char email[] = "reallythebestemailever@gmail.com";
			char password[] = "reallybadpassword";
			Assert::AreEqual(1, userRegistration(username, email, password));
		}
		TEST_METHOD(Username_Is_Maximum_Length)
		{
			char username[] = "supermanhasnonipples123456789";//find max length
			char email[] = "reallythebestemailever@gmail.com";
			char password[] = "reallybadpassword";
			Assert::AreEqual(1, userRegistration(username, email, password));
		}
		TEST_METHOD(Password_Is_Maximum_Length)
		{
			char username[] = "supermanhasnonipples";
			char email[] = "reallythebestemailever@gmail.com";
			char password[] = "reallygoodpasswordipromisebro";//find max length
			Assert::AreEqual(1, userRegistration(username, email, password));
		}
		TEST_METHOD(Password_Is_Minimum_Length)
		{
			char username[] = "supermanhasnonipples";
			char email[] = "reallythebestemailever@gmail.com";
			char password[] = "fives";
			Assert::AreEqual(1, userRegistration(username, email, password));
		}
	};
}