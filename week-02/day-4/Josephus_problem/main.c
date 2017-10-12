#include <stdio.h>
#include <stdlib.h>

int josephus(int people);
int next_alive(int group[], int people, int starting_seat);

int main()
{
    int people = 0;

    printf("JOSEPHUS PROBLEM\n\n");
    printf("How many people are in the \"game\": ");
    scanf("%d", &people);

    printf("number of the winning seat is: %d", josephus(people));

    return 0;
}

// step-by-step solution, gives back the nr. of the winning seat from 1
int josephus(int people) {
    int group[people];  //1 is alive, 0 is dead
    int seat = 0;
    int n = 0;
    int step = 0;

    for (int i = 0; i < people; i++)
        group[i] = 1;

    do {
        step++;
        seat = n;
        n = next_alive(group, people, seat);
        if (n != seat) {
            group[n] = 0;
            n = next_alive(group, people, seat);
            //n = next_alive(group, people, seat);
        }
        printf("After the %d. step:\t", step);
        for (int i = 0; i < people; i++)
            printf("%d", group[i]);
        printf("\n");
    } while (n != seat);

    return seat + 1;
}

// find the next alive person's seat in the array (for josephus() )
int next_alive(int group[], int people, int starting_seat)
{
    int i = starting_seat;
    do {
        if (i == people - 1) {
            i = 0;
        } else {
            i++;
        }
    } while (group[i] == 0 && i != starting_seat);

    return i;
}


