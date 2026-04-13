#include <stdio.h>
#include <string.h>

//Function to verify if the username and password are valid.
int userLogin(char username[], char password[]) {

	if (strlen(username) == 0 || strlen(password) == 0) {
		return 0;
	}

	if (strcmp(username, "admin") == 0 && strcmp(password, "1234") == 0) {
		return 1;
	}

	return 0;
}

// Function to add a listing with valid housing details.
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
	if (expected == actual) {
		printf("%s: PASS\n", testName);
	}
	else {
		printf("%s: FAIL (Expected %d, Got %d)\n", testName, expected, actual);
	}
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

	checkTest("Valid Waterloo listing", 1, add_Listing('A', 1800.0, 2, "Waterloo"));
	checkTest("Valid Kitchener listing", 1, add_Listing('T', 2200.0, 3, "Kitchener"));
	checkTest("Valid Cambridge listing", 1, add_Listing('C', 2000.0, 1, "Cambridge"));
	checkTest("Invalid type", 0, add_Listing('X', 1800.0, 2, "Waterloo"));
	checkTest("Negative rent", 0, add_Listing('A', -100.0, 2, "Kitchener"));
	checkTest("Zero bedrooms", 0, add_Listing('C', 1500.0, 0, "Cambridge"));
	checkTest("Empty location", 0, add_Listing('A', 1700.0, 1, ""));
	checkTest("Invalid region", 0, add_Listing('A', 1700.0, 1, "Toronto"));
}

int main() {
	test_userLogin();
	test_add_Listing();
	return 0;
}