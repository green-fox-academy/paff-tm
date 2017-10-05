#include <stdio.h>
#include <stdlib.h>

/*
Create a program which can tell how to pay an exact amount of money
for example 45670 Ft, is the amount (store this as an integer)
and the output should be:
2-20000Ft
1-5000Ft
1-500Ft
1-100Ft
1-50Ft
1-20Ft
*/

/*
Take care of the rounding (when giving back 5 coins):
1, 2 - 0 down
3, 4 - 5 up
6, 7 - 5 down
8, 9 - 0 up
*/

int main()
{
    int amount_of_money = 57552;
    int m;

    m = amount_of_money / 20000;
    amount_of_money -= m * 20000;
    if (m > 0)
        printf("%d-20000\n", m);

    m = amount_of_money / 10000;
    amount_of_money -= m * 10000;
    if (m > 0)
        printf("%d-10000\n", m);

    m = amount_of_money / 5000;
    amount_of_money -= m * 5000;
    if (m > 0)
        printf("%d-5000\n", m);

    m = amount_of_money / 2000;
    amount_of_money -= m * 2000;
    if (m > 0)
        printf("%d-2000\n", m);

    m = amount_of_money / 1000;
    amount_of_money -= m * 1000;
    if (m > 0)
        printf("%d-1000\n", m);

    m = amount_of_money / 500;
    amount_of_money -= m * 500;
    if (m > 0)
        printf("%d-500\n", m);

    m = amount_of_money / 200;
    amount_of_money -= m * 200;
    if (m > 0)
        printf("%d-200\n", m);

    m = amount_of_money / 100;
    amount_of_money -= m * 100;
    if (m > 0)
        printf("%d-100\n", m);

    m = amount_of_money / 50;
    amount_of_money -= m * 50;
    if (m > 0)
        printf("%d-50\n", m);

    m = amount_of_money / 20;
    amount_of_money -= m * 20;
    if (m > 0)
        printf("%d-20\n", m);

    m = amount_of_money / 10;
    amount_of_money -= m * 10;
    if (m > 0)
        printf("%d-10\n", m);

    m = amount_of_money / 5;
    amount_of_money -= m * 5;
    switch (amount_of_money) {
    case (3):
    case (4):
        m++;
    }
    if (m > 0)
        printf("%d-5\n", m);

    return 0;
}
