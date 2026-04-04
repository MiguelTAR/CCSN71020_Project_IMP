#include <stdio.h>
#include "main.h"
#include "user.h"
#include "user.c"


void userRegistration();
void userLogin();

//definition of the dummyfunction. You can remove this function once the project works.
int dummyFunction(int x, int y) {
	return x + y;
}

//definition of functions here. E.g., 
// int yourFunction(...){
//		return INVALID_VALUE;
// }




int main() {
	
	userRegistration();
	userLogin();
	
	int option;

	while (1) {
		printf("                          \n");
		printf("        Menu Listing      \n");
		printf("1. Add Listing            \n");
		printf("2. Delete Listing         \n");
		printf("3. Add Listing            \n");
		printf("4. Delete Listing         \n");
		printf("5. Search Listing         \n");
		printf("6. View Listing           \n");
		printf("7. Exit                   \n");
		printf("                          \n");
		printf("Enter an option:          \n");
		scanf_s("%d", &option);

		switch (option) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7: exit();
			break;
		}
	}

	return 0;

}

void exit() {
	printf("Exit Listing Management System");
}

		
