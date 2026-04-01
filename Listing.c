#include <string.h>
#include "listing.h"
#include <stdio.h>

#define listing_file "list.txt"
//Creating a function to load the listings from the text file.
int loadListings(const char* filename, Listing listing[], int maxListing) {
	FILE* file = fopen(filename, "r");
	if (!file) return -1;

	char line[256];
	int count = 0;
	double rent = -1;
	char type[TYPE_LEN] = "";
	int bedrooms = -1;
	char location[LOCATION_LEN] = "";

	while (fgets(line, sizeof(line), file) && count < maxListing) {
		
		if (strncmp(line, "Monthly Rent: ", 13) == 0) {
			sscanf(line, "Monthly Rent: ", &rent);
		}
		else if (strncmp(line, "Type of housing: ", 16) == 0) {
			sscanf(line, "Type of housing: %[^\n]", type);
		}
		else if (strcmp(line, "bedrooms: ", 9) == 0) {
			sscanf(line, "bedrooms: %d", &bedrooms);
		}
		else if (strncmp(line, "Location: ", 9) == 0) {
			sscanf(line, "Location: %[^\n]", location);
		}

		//When all four fields are collected, store the listing.
		if (rent > 0 && strlen(type) > 0 && bedrooms >= 0 && strlen(location) > 0) {
			listing[count].id = count + 1;
			listing[count].monthlyRent = rent;

			strcpy(listing[count].Type, type, TYPE_LEN - 1);
			listing[count].Type[TYPE_LEN - 1] = '\0';

			listing[count].bedrooms = bedrooms;

			strncpy(listing[count].location, location, LOCATION_LEN - 1);
			listing[count].location[LOCATION_LEN - 1] = '\0';

			count++;

			//reset fields for next listing
			rent = -1;
			bedrooms = -1;
			type[0] = '\0';
			location[0] = '\0';

		}

	}

	fclose(file);
	return count;

}

int saveListing(const char* filename, Listing Listing[], int count) {

	FILE*file = fopen(filename, "w");
	if (!file) return 0;

	for (int i = 0; i < count; i++) {
		fprintf(file, "Monthly Rent: %.2f\n", Listing[i].monthlyRent);
		fprintf(file, "Type of housing: %s\n", Listing[i].Type);
		fprintf(file, "bedrooms: %d\n", Listing[i].bedrooms);
		fprintf(file, "Location: %s\n", Listing[i].location);

			if (i < count - 1) {
				fprintf(file, "\n");
			}

	}
	
	
	fclose(file);
	return 1;
	
}

int addlisting(const char* filename, double monthlyRent,
	const char Type[], int bedrooms,
	const char location[])
{
	FILE*file = fopen(filename, "a");
	if (!file) return 0;

	fprintf(file, "Monthly Rent: %.2f\n", monthlyRent);
	fprintf(file, "Type of housing: %s\n", Type);

}

