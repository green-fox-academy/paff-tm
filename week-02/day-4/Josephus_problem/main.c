#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

int josephus_math(int people);
int josephus_bit(int people);
int josephus(int people);
int next_alive(int group[], int people, int starting_seat);

int main()
{
    int people = 0;

    printf("JOSEPHUS PROBLEM\n\n");
    printf("How many people are in the \"game\": ");
    scanf("%d", &people);

    printf("Number of the winning seat is (step-by-step method): %d\n", josephus(people));
    printf("Number of the winning seat is (bitwise method): %d\n", josephus_bit(people));
    printf("Number of the winning seat is (mathematic method): %d\n", josephus_math(people));

    return 0;
}

/*  Mathematic solution gives back the winning seat;
 *  All bits shifts left, and the highest order bit will go to the first place value
 */
int josephus_math(int people)
{
    int winning_seat = (people << 1) + 1 ;  // shifts the bit to left and set the last bit to 1
    int x;

    printf("\noriginal bits of the nr. of people:\t"BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(people));

    // find the highest order bit in people.
    x = 0;
    while (people != (people & x)) {
        x = (x << 1) + 1;
    }

    // Delete the highest order bit. winning_seat is already shifted
    winning_seat -= ++x;
    printf("\nthe bits of the winning seat:\t\t"BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(winning_seat));

    return winning_seat;
}

/*  Bitwise solution of Josephus problem
 *  Return the winner position counted from 1. If there are more people given that it can handle, return 0;
 *  This function is also play the game step-by-step but not in an array but in one variable (group)
 */
int josephus_bit(int people)
{
    uint64_t group = 0;              // 1 for alive, 0 for dead person in binary
    uint64_t counter = 0;            // always shows the person's position who's at the last digit

    if (people > sizeof(group) * 8) { // if there are more people than it can be handled, return 0
        return 0;
    } else {
        // set the init value of the group according to the number of the people (5 -> 0b00011111)
        group = pow(2, people) - 1;

        // (The last bit is always 1) While there are more people than 1
        // that person remain alive, put it at the beginning bit, according to the number of people
        while (group > 1) {
            group = (group >> 1) + pow(2, people - 1);
            counter++;
            counter %= people;
            printf("\nkiller remains alive:\t\t"BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(group));

            // find the next alive person (to kill)
            while (group % 2 == 0) {
                group >>= 1;
                counter++;
                counter %= people;
                printf("\nlooking for the victim\t\t"BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(group));
            }

            // then set the last bit to 0 (kill him)
            group--;
            printf("\nkill him:\t\t\t"BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(group));

            // find the next alive person (who can kill somebody)
            while (group % 2 == 0) {
                group >>= 1;
                counter++;
                counter %= people;
                printf("\nlooking for the next killer\t"BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(group));
            }
        }
    }
    printf("\n");
    return counter + 1;
}

/*  Step-by-step solution, gives back the nr. of the winning seat counted from 1
 *
 */
int josephus(int people)
{
    int group[people];  // 1 is alive, 0 is dead
    int seat = 0;       // the position of a killer
    int next = 0;       // the position of the next alive person
    int step = 0;       // counts the steps

    for (int i = 0; i < people; i++)
        group[i] = 1;

    do {
        step++;

        // Set the killer position to the last found alive person.
        // At first round it will be 0;
        seat = next;

        // Looking for the next alive person to kill
        next = next_alive(group, people, seat);

        // If it is not the same than the killer (that means he's not the only one alive),
        // than kill him, and find the next alive person who will be a killer
        if (next != seat) {
            group[next] = 0;
            next = next_alive(group, people, seat);
        }

        // print out the actual stage
        printf("After the %d. step:\t", step);
        for (int i = 0; i < people; i++)
            printf("%d", group[i]);
        printf("\n");

      // Do until the killer and the person to be killed is at the same position, so he's the only alive person
    } while (next != seat);

    return seat + 1;
}

/* Gives back the next alive person's seat in the array (for josephus() )
 * (the index of the next '1' value)
 */
int next_alive(int group[], int people, int starting_seat)
{
    int i = starting_seat;
    do {
        // if this is the last item in the group, then start from the beginning, if not, step one
        if (i == people - 1) {
            i = 0;
        } else {
            i++;
        }
    } while (group[i] == 0 && i != starting_seat);

    return i;
}


