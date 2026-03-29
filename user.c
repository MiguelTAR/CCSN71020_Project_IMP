#include <stdio.h> 
#include <string.h>
#include "user.h"

char username, email, password, usernameInput, passwordInput;

userRegistration();

userLogin();


int userRegistration(char username, char email, char password)
{
	printf("Enter Username: ");
	scanf_s("%c\n", username);

	if (strleng(username) > USERNAME_MAXLEN)
	{
		printf("Username to long");
	}
	else if (strleng(username) < USERNAME_MINLEN)
	{
		printf("Username to short");
	};
	printf("Enter Email: ");
	scanf_s("%c\n", email);

	if (strleng(email) > EMAIL_LEN)
	{
		printf("email to long");
	};

	printf("Enter Password");
	scanf_s("%c\n", password);

	if (strleng(password) > PASSWORD_MAXLEN)
	{
		printf("Username to long");
	}
	else if (strleng(username) < PASSWORD_MINLEN)
	{
		printf("Username to short");
	}

};

int userLogin(char username, char password)
{

	printf("Enter Username: ");
	scanf_s("%c\n", usernameInput);
	if (usernameInput == username)
	{
		printf("Username Found");
	}
	else {
		printf("Wrong Username");
	}

	printf("Enter Password: ");
	scanf_s("%c\n", passwordInput);
	if (passwordInput == password)
	{
		printf("Login Succesfull");
	}
	else {
		printf("Wrong Password");
	}


};

