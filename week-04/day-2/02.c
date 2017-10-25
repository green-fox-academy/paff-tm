#include <stdio.h>

enum CarType {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct Car {
  enum CarType type;
  double km;
  double gas;
};

// TODO:
// Write a function that takes a Car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

int main() {

    struct Car car;

    printf("%d: VOLVO\n"
           "%d: TOYOTA\n"
           "%d: LAND ROVER\n"
           "%d: TESLA\n", VOLVO, TOYOTA, LAND_ROVER, TESLA);
    printf("Car type: ");
    scanf("%u", &car.type);

    printf("Km: ");

    fflush(stdin);
    scanf("%lf", &car.km);
    fflush(stdin);

    if (car.type != TESLA) {
        printf("Gas: ");
        fflush(stdin);
        scanf("%lf", &car.gas);
        fflush(stdin);
    }

    printf("Car type: %u\n", car.type);
    printf("Km: %g\n", car.km);
    if (car.type != TESLA) {
        printf("Gas: %g\n", car.gas);
    }

    return 0;
}
