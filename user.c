#include <stdio.h> 
#include <string.h>




char username, email, password;


int userRegistration(char username, char email, char password)
{
	printf("Enter Username: ");
	scanf_s("%c\n", username);

	if (strleng(username) > USERNAME_MAXLEN)
	{
		printf("")
	};

	printf("Enter Email: ");
	scanf_s("%c\n", email);

	printf("Enter Password");
	scanf_s("%c\n", password);

};

int userLogin(char username, char password)
{

	printf("Enter Username: ");
	printf("Enter Password: ")



};

