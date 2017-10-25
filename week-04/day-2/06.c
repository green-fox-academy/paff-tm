#include <stdio.h>

typedef struct Pirate {
    char name[256];
    int has_wooden_leg;
    short int gold_count;
} t_pirate;

// TODO:
// Create a function that takes an array of pirates (and it's length) then returns the sum of the golds of all pirates

// TODO:
// Create a function that takes an array of pirates (and it's length) then returns the average of the gold / pirate

// TODO:
// Create a function that takes an array of pirates (and it's length) then returns the name of the
// richest that has wooden leg

int sum_of_golds(t_pirate *pirates, int number_of_pirates);
float avg_of_gold_per_pirate(t_pirate *pirates, int number_of_pirates);
char* richest_pirate_with_wooden_leg(t_pirate *pirates, int number_of_pirates);

int main() {
    t_pirate pirates[] = {
        {"Jack", 0, 18},
        {"Uwe", 1, 8},
        {"Hook", 1, 12},
        {"Halloween kid", 0, 0},
        {"Sea Wolf", 1, 14},
        {"Morgan", 0, 1}
    };

    printf("The sum of the golds of all pirates: %d\n", sum_of_golds(pirates, sizeof(pirates) / sizeof(pirates[0])));
    printf("The average of the gold per pirate: %g\n", avg_of_gold_per_pirate(pirates, sizeof(pirates) / sizeof(pirates[0])));
    printf("The name of the richest that has wooden leg: %s\n", richest_pirate_with_wooden_leg(pirates, sizeof(pirates) / sizeof(pirates[0])));

    return 0;
}

int sum_of_golds(t_pirate *pirates, int number_of_pirates)
{
    int count = 0;

    for (int i = 0; i < number_of_pirates; i++){
        count += pirates[i].gold_count;
    }

    return count;
}

float avg_of_gold_per_pirate(t_pirate *pirates, int number_of_pirates)
{
    return (float)sum_of_golds(pirates, number_of_pirates) / number_of_pirates;
}

char* richest_pirate_with_wooden_leg(t_pirate *pirates, int number_of_pirates)
{
    int id_of_richest_pirate = -1;

    for (int i = 0; i < number_of_pirates; i++) {
        if (pirates[i].has_wooden_leg) {
            if ((id_of_richest_pirate == -1) || (pirates[i].gold_count > pirates[id_of_richest_pirate].gold_count)) {
                id_of_richest_pirate = i;
            }
        }
    }

    return pirates[id_of_richest_pirate].name;
}
