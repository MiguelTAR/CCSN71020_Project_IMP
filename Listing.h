#ifndef LISTING_H
#define LISTING_H
#include "constants.h"


typedef struct {
    int id;
    double monthlyRent;
    char Type[TYPE_LEN];
    int bedrooms;
    int bathrooms;
    char location[LOCATION_LEN];
} Listing;

int loadListings(const char* filename, Listing listing[], int maxListing);
int saveListings(const char* filename, Listing listing[], int count);

int addListing_txt(const char* filename, double monthlyRent,
    const char* type[], int bedrooms,
    const char location[]);

int delete_item_txt(const char* filename, int id_delete);

int search_listing_txt(const char* filename,
    const char* type_filter, const char* located_filter,
    int minbedrooms, double maxRent);

void view_listings_txt(const char* filename);

#endif
