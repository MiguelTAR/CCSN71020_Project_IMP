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

int saveListings(const char* filename, Listing Listing[], int count) {

	FILE*file = fopen(filename, "w");
	if (!file) return 0;

	for (int i = 0; i < count; i++) {
		fprintf(file, "Monthly Rent: %.2f\n", Listing[i].monthlyRent);
		fprintf(file, "Type of housing: %s\n", Listing[i].Type);
		fprintf(file, "bedrooms: %d\n", Listing[i].bedrooms);
		fprintf(file, "Location: %s\n", Listing[i].location);

		//add blank line between listings
			if (i < count - 1) {
				fprintf(file, "\n");
			}

	}
	
	
	fclose(file);
	return 1;
}	

//in the document this function was once called 
int addlisting_txt(const char* filename, double monthlyRent,
	const char Type[], int bedrooms,
	const char location[])
{
	FILE*file = fopen(filename, "a");
	if (!file) return 0;

	fprintf(file, "Monthly Rent: %.2f\n", monthlyRent);
	fprintf(file, "Type of housing: %s\n", Type);

}

int delete_item_txt(const char* filename, int ID_delete) {
	Listing listings[MAX_LISTINGS];
	int count = loadListings(filename, listings, MAX_LISTINGS);
	if (count <= 0) return 0;

	if (ID_delete < 1 || ID_delete > count) return 0;

	for (int i = 0; i < count; i++)
		listings[i].id = i + 1;

	return saveListing(filename, listings, count - 1);

}



int search_listing_txt(const char* filename,
				const char* typeFilter,
	const char* locationFilter,
	int minBedrooms,
	double maxRent)
{
	Listing listings[MAX_LISTINGS];
	int count = loadListings(filename, listings, MAX_LISTINGS);
	if (count <= 0) return 0;

	int matches = 0;

	for (int i = 0; i < count; i++) {
		int ok = 1;

		if (typeFilter && strlen(typeFilter) > 0 &&
			strcmp(listings[i].Type, typeFilter) != 0)
			ok = 0;

		if (locationFilter && strlen(locationFilter) > 0 &&
			strcmp(listings[i].location, locationFilter) != 0)
			ok = 0;

		if (minBedrooms > 0 && listings[i].bedrooms < minBedrooms)
			ok = 0;

		if (maxRent > 0 && listings[i].monthlyRent > maxRent)
			ok = 0;

		if (ok)
			matches++;
	}

	return matches;
}
void view_listing_txt(const char* filename)
{
	Listing listings[MAX_LISTINGS];
	int count = loadListings(filename, listings, MAX_LISTINGS);

	if (count <= 0) {
		printf("No listings found or could not read file.\n");
		return;
	}

	printf("\n--- Current Listings ---\n");

	for (int i = 0; i < count; i++) {
		printf("ID: %d\n", listings[i].id);
		printf("  Monthly rent: $%.2f\n", listings[i].monthlyRent);
		printf("  Type of housing: %s\n", listings[i].Type);
		printf("  Bedrooms: %d\n", listings[i].bedrooms);
		printf("  Location: %s\n\n", listings[i].location);
	}

	// NEW FEATURE: Print total number of listings
	printf("Total listings posted: %d\n", count);

	// NEW FEATURE: Receipt summary
	printf("\n----- RECEIPT -----\n");
	printf("Total listings processed: %d\n", count);
	printf("-------------------\n");
}


