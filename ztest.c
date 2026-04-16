#include <stdio.h>
#include <string.h>

//Verify if the username and password are valid.
int userLogin(char username[], char password[]) {

	if (strlen(username) == 0 || strlen(password) == 0) {
		return 0;
	}

	if (strcmp(username, "admin") == 0 && strcmp(password, "1234") == 0) {
		return 1;
	}

	return 0;
}

// Add a listing with housing details.
int add_Listing(const char type, double monthlyRent, int bedrooms, char locations[]) {

	if (monthlyRent <= 0) {
		return 0;
	}

	if (bedrooms <= 0) {
		return 0;
	}

	if (strlen(locations) == 0) {
		return 0;
	}

	if (type != 'A' && type != 'T' && type != 'C') {
		return 0;
	}

	if (strcmp(locations, "Waterloo") != 0 &&
		strcmp(locations, "Kitchener") != 0 &&
		strcmp(locations, "Cambridge") != 0) {
		return 0;
	}

	return 1;
}

void checkTest(char testName[], int expected, int actual) {
	if (expected == actual)
		printf("%s: PASS\n", testName);
	else
		printf("%s: FAIL (Expected %d, Got %d)\n", testName, expected, actual);
}

void test_userLogin() {
	printf("\nTesting userLogin...\n");

	checkTest("Valid login", 1, userLogin("admin", "1234"));
	checkTest("Wrong password", 0, userLogin("admin", "wrong"));
	checkTest("Wrong username", 0, userLogin("user", "1234"));
	checkTest("Empty username", 0, userLogin("", "1234"));
	checkTest("Empty password", 0, userLogin("admin", ""));
}

void test_add_Listing() {
	printf("\nTesting add_Listing...\n");

	checkTest("Valid Waterloo", 1, add_Listing('A', 1800, 2, "Waterloo"));
	checkTest("Valid Kitchener", 1, add_Listing('T', 2200, 3, "Kitchener"));
	checkTest("Valid Cambridge", 1, add_Listing('C', 2000, 1, "Cambridge"));
	checkTest("Invalid city", 0, add_Listing('A', 1800, 2, "Toronto"));
	checkTest("Negative rent", 0, add_Listing('A', -100, 2, "Kitchener"));
	checkTest("Zero bedrooms", 0, add_Listing('A', 1800, 0, "Waterloo"));
	checkTest("Invalid type", 0, add_Listing('X', 1800, 2, "Waterloo"));
}

 //int main() {
	// test_userLogin();
	// test_add_Listing();
	 // return 0;
 // } 