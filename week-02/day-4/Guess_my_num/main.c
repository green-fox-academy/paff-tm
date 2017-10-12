#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hidden_num = 0;
    int range = 0;
    int lives = 6;
    int guess = 0;

    printf("Add the range of the number: 1 - ");
    scanf("%d", &range);
    hidden_num = rand() % range + 1;

    printf("I've the number between 1-%d. You have %d lives.\n", range, lives);

    do {
        printf("Your guess is: ");
        scanf("%d", &guess);
        if (guess < hidden_num) {
            lives--;
            printf("Too low. You have %d lives left.\n", lives);
        } else if (guess > hidden_num) {
            lives--;
            printf("Too high. You have %d lives left.\n", lives);
        }
    } while (guess != hidden_num && lives > 0);

    if (lives > 0) {
        printf("Congratulations. You won!");
    } else {
        printf("You loose... The number was %d.", hidden_num);
    }

    return 0;
}
