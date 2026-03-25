#ifndef LISTING_H
#define LISTING_H
#include "constants.h"


typedef struct {
    int id;
    char type[TYPE_LEN];
    double price;
    int rooms;
    int bathrooms;
    double sqft;
    char address[ADDRESS_LEN];
    char city[CITY_LEN];
} Listing;

int addRentalListing(const char type[], double price, int rooms, int bathrooms,
    double sqft, const char address[], const char city[]);

int searchListing(const char type[], double maxPrice, int minRooms, int minBathrooms,
    const char city[], double minSqft);

int deleteListing(int listingId);

#endif
