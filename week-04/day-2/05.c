#include <stdio.h>

// TODO:
// Create a struct that represents a House
// It should store:
//  - The address of the house
//  - The price in EUR
//  - The number of rooms
//  - The area of the house in square meters

// TODO:
// The market price of the houses is 400 EUR / square meters
// Create a function that takes a pointer to a house and decides if it's worth to buy
// (if the price is lower than the calculated price from it's area)

// TODO:
// Create a function that takes an array of houses (and it's length), and counts the
// houses that are worth to buy.

#define MARKET_PRICE 400

typedef enum {FALSE, TRUE} bool;

typedef struct {
    char *address;
    int price;
    int rooms;
    float sqm;
} t_house;

bool is_worth(t_house *house);
int count_house_worth(t_house houses[], int num_of_houses);

int main()
{
    t_house houses[4] =
    {
        "Pesterzsebet kulso 24.",
        40000,
        3,
        100,

        "Nagykorut 2",
        15000,
        2,
        50,

        "Andrassy ut 66.",
        50000,
        4,
        100,

        "Kiskorut 32.",
        35000,
        3,
        100,
    };

    printf("There are %d houses on good price.\n", count_house_worth(houses, sizeof(houses) / sizeof(houses[0])));

    return 0;
}

bool is_worth(t_house *house)
{
    float price_per_sqm = house->price / house->sqm;
    if (price_per_sqm <= MARKET_PRICE) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int count_house_worth(t_house houses[], int num_of_houses)
{
    int count = 0;

    for (int i = 0; i < num_of_houses; i++) {
        if (is_worth(&houses[i]) == TRUE)
            count++;
    }
    return count;
}
