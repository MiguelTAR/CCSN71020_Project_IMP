#include <stdio.h> 
#include <string.h>
#include "user.h"

char username[], email[], password[], usernameInput[], passwordInput[];


int userRegistration(char username[], char email[], char password[])
{
	printf("Enter Username: ");
	scanf_s("%s\n", username, sizeof(username));

	if (strlen(username) > USERNAME_MAXLEN)
	{
		printf("Username too long");
		return;
	}
	else if (strleng(username) < USERNAME_MINLEN)
	{
		printf("Username to short");
		return;
	}

	printf("Enter Email: ");
	scanf_s("%s\n", email, sizeof(email));

	if (strlen(email) > EMAIL_LEN)
	{
		printf("Email too long");
		return;
	}
	else {

		if (strchr(email, '@') && strchr(email,'.'))
		{
			printf("Email Saved");
		}
		else{
			printf("Email Not valid");
			return;
		}

	}

	printf("Enter Password");
	scanf_s("%s\n", password);

	if (strlen(password) > PASSWORD_MAXLEN)
	{
		printf("Password too long");
		return;
	}
	else if (strlen(password) < PASSWORD_MINLEN)
	{
		printf("Password too short");
		return;
	}
	return 0;
}

int userLogin(char username[], char password[])
{

	printf("Enter Username: ");
	scanf_s("%s\n", usernameInput);
	if (strcmp (usernameInput,username) == 0)
	{
		printf("Username Found");
	}
	else {	
		printf("Wrong Username");
		return;
	}

	printf("Enter Password: ");
	scanf_s("%s\n", passwordInput);
	if (strcmp (passwordInput,password) == 0)
	{
		printf("Login Succesfull");
	}
	else {
		printf("Wrong Password");
		return;
	}

	return 0;
}

