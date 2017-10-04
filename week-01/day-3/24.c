#include <stdio.h>
#include <stdlib.h>

/*
Create a program which converts days to years, months, weeks and days
to keep it simple we say every year is 365 days long, every month is 30 days
*/

int main()
{
    int days = 3243;
    int years = 0, months = 0, weeks = 0;

    printf("days: %d\n", days);

    years = days / 365;
    days %= 365;

    months = days / 30;
    days %= 30;

    weeks = days / 7;
    days %= 7;

    printf("years: %d\nmonths: %d\nweeks: %d\ndays: %d\n ", years, months, weeks, days);
    printf("%d", years * 365 + months * 30 + weeks * 7 + days);


    return 0;
}
