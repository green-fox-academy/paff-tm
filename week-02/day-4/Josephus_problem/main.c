#include <stdio.h>
#include <stdlib.h>

int josephus(int people);

int main()
{
    int people = 0;

    printf("JOSEPHUS PROBLEM\n\n");
    printf("How many people are in the \"game\": ");
    scanf("%d", &people);

    printf("number of the winning seat is: %d", josephus(people));

    return 0;
}

int josephus(int people) {
    int winning_seat = 0;


    return winning_seat;
}


