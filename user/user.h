#pragma once

#if defined(__cplusplus)
extern "C" {
#endif


	#ifndef CONSTANTS_H

	#define CONSTANTS_H

	int userRegistration(char[], char[], char[]);
	int userLogin(char[], char[], char[]);

	#define MAX_USERNAME 2
	#define MAX_LISTING 7

	#define USERNAME_MAXLEN 30
	#define USERNAME_MINLEN 5
	#define EMAIL_LEN 50
	#define PASSWORD_MAXLEN 30
	#define PASSWORD_MINLEN 8
	#define TYPE_LEN 20
	#define ADDRESS_LEN 50
	#define CITY_LEN 20

	#endif

#if defined(__cplusplus)
}
#endif