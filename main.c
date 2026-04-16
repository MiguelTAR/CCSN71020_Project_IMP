#include <stdio.h>
#include "main.h"
#include "user.h"
#include "user.c"
#include <string.h>
#include "Listing.h"

#define LISTING_FILE "list.txt"

/*
===========================================================
 FUNCTION: displayMenu
 PURPOSE:
    - Show the menu options for the listing system
===========================================================
*/
void displayMenu()
{
    printf("\n===== LISTING SYSTEM MENU =====\n");
    printf("1. View all listings\n");
    printf("2. Add a new listing\n");
    printf("3. Delete a listing\n");
    printf("4. Search listings\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

/*
===========================================================
 FUNCTION: main
 PURPOSE:
    - Provide a menu-driven interface for the listing system
    - Allow the user to:
         * View listings
         * Add listings
         * Delete listings
         * Search listings
    - Uses list.txt as the database file
===========================================================
*/
int main()
{
    int choice = 0;

    while (choice != 5)
    {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // clear newline

        if (choice == 1)
        {
            // VIEW LISTINGS
            view_listings_txt(LISTING_FILE);
        }
        else if (choice == 2)
        {
            // ADD LISTING
            double rent;
            char type[TYPE_LEN];
            int bedrooms;
            int bathrooms;
            char location[LOCATION_LEN];

            printf("Enter monthly rent: ");
            scanf("%lf", &rent);
            getchar();

            printf("Enter type of housing: ");
            fgets(type, TYPE_LEN, stdin);
            type[strcspn(type, "\n")] = '\0';

            printf("Enter number of bedrooms: ");
            scanf("%d", &bedrooms);
            getchar();

            printf("Enter number of bathrooms: ");
            scanf("%d", &bathrooms);
            getchar();

            printf("Enter location: ");
            fgets(location, LOCATION_LEN, stdin);
            location[strcspn(location, "\n")] = '\0';

            // NOTE: your header uses const char* type[]
            const char* typePtr = type;

            if (addListing_txt(LISTING_FILE, rent, &typePtr, bedrooms, location))
                printf("Listing added successfully!\n");
            else
                printf("Error adding listing.\n");
        }
        else if (choice == 3)
        {
            // DELETE LISTING
            int id;
            printf("Enter ID of listing to delete: ");
            scanf("%d", &id);

            if (delete_item_txt(LISTING_FILE, id))
                printf("Listing deleted successfully!\n");
            else
                printf("Error deleting listing.\n");
        }
        else if (choice == 4)
        {
            // SEARCH LISTINGS
            char typeFilter[TYPE_LEN];
            char locationFilter[LOCATION_LEN];
            int minBedrooms;
            double maxRent;

            printf("Enter type filter (or leave blank): ");
            getchar();
            fgets(typeFilter, TYPE_LEN, stdin);
            typeFilter[strcspn(typeFilter, "\n")] = '\0';

            printf("Enter location filter (or leave blank): ");
            fgets(locationFilter, LOCATION_LEN, stdin);
            locationFilter[strcspn(locationFilter, "\n")] = '\0';

            printf("Enter minimum bedrooms (0 for none): ");
            scanf("%d", &minBedrooms);

            printf("Enter maximum rent (0 for none): ");
            scanf("%lf", &maxRent);

            int matches = search_listing_txt(
                LISTING_FILE,
                typeFilter,
                locationFilter,
                minBedrooms,
                maxRent
            );

            printf("\nSearch results: %d listings matched.\n", matches);
        }
        else if (choice == 5)
        {
            printf("Exiting program...\n");
        }
        else
        {
            printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}

		
