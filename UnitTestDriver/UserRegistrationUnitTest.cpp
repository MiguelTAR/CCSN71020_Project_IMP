#include "pch.h"
#include "CppUnitTest.h"
#include "../project/user.h"

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
			Assert::AreEqual(1, userRegristration(username, email, password));
		}
		TEST_METHOD(TestMethod1)
		{
			char username[] = "supermanhasnonipples";
			char email[] = "reallythebestemailever@gmail.com";
			char password[] = "reallybadpassword";
			Assert::AreEqual(1, userRegristration(username, email, password));
		}
	};
	TEST_CLASS(UserRegistrationExceptionTests)
	{
	public:

		TEST_METHOD(PasswordTooLong)
		{
			char username[] = "testingnames";
			char email[] = "bestemailever@gmail.com";
			char password[] = "goodpasswordtrustmeaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
			Assert::AreEqual(INEEDTHEANSWERPLSTELLME, userRegristration(username, email, password));
		}
		TEST_METHOD(PasswordTooShort)
		{
			char username[] = "testingnames";
			char email[] = "bestemailever@gmail.com";
			char password[] = "help";
			Assert::AreEqual(INEEDTHEANSWERPLSTELLME, userRegristration(username, email, password));
		}
		TEST_METHOD(InvalidEmailAddress)
		{
			char username[] = "testingnames";
			char email[] = "bestemailever@yahoo.com";
			char password[] = "goodpasswordtrustme";
			Assert::AreEqual(INEEDTHEANSWERPLSTELLME, userRegristration(username, email, password));
		}
		TEST_METHOD(UserNameIsTooLong)
		{
			char username[] = "testingnamesaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
			char email[] = "bestemailever@gmail.com";
			char password[] = "goodpasswordtrustme";
			Assert::AreEqual(INEEDTHEANSWERPLSTELLME, userRegristration(username, email, password));
		}
		TEST_METHOD(UserNameIsTooShort)
		{
			char username[] = "fdsf";
			char email[] = "bestemailever@gmail.com";
			char password[] = "goodpasswordtrustme";
			Assert::AreEqual(INEEDTHEANSWERPLSTELLME, userRegristration(username, email, password));
		}
		TEST_METHOD(UserNameExists)//ask JP how he's handling this
		{

		}
		TEST_METHOD(EmailAlreadyExists)//ask JP how he's handling this
		{

		}
		
	};
	TEST_CLASS(UserRegistrationBoundaryTests)
	{
	public:

		TEST_METHOD(UserNameIsMinimumLength)
		{
			char username[] = "supermanhasnonipples";//find min length
			char email[] = "reallythebestemailever@gmail.com";
			char password[] = "reallybadpassword";
			Assert::AreEqual(1, userRegristration(username, email, password));
		}
		TEST_METHOD(UserNameIsMaximumLength)
		{
			char username[] = "supermanhasnonipples";//find max length
			char email[] = "reallythebestemailever@gmail.com";
			char password[] = "reallybadpassword";
			Assert::AreEqual(1, userRegristration(username, email, password));
		}
		TEST_METHOD(PasswordIsMaximumLength)
		{
			char username[] = "supermanhasnonipples";
			char email[] = "reallythebestemailever@gmail.com";
			char password[] = "reallybadpassword";//find max length
			Assert::AreEqual(1, userRegristration(username, email, password));
		}
		TEST_METHOD(PasswordIsMinimumLength)
		{
			char username[] = "supermanhasnonipples";
			char email[] = "reallythebestemailever@gmail.com";
			char password[] = "reallybadpassword";//find min length
			Assert::AreEqual(1, userRegristration(username, email, password));
		}
	};
}
