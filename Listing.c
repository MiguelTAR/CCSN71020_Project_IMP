#include <string.h>
#include "listing.h"
#include <stdio.h>

int loadListings(const char* filename, Listing listings[], int maxListings) {
	FILE* file = fopen(filename, "r");
	if (!file) return -1;

	char line[256];
	int count = 0;
	double rent = -1;
	char type[TYPE_LEN] = "";
	int bedrooms = -1;
	char location[LOCATION_LEN] = "";

	while (fgets(line, sizeof(line), file) && count < maxListings) {

	}

}
