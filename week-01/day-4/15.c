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
    int amount_of_money = 57545;
    int m;

    m = 0;
    while (amount_of_money >= 20000) {
        m++;
        amount_of_money -= 20000;
    }
    if (m > 0)
        printf("%d-20000\n", m);

    m = 0;
    while (amount_of_money >= 10000) {
        m++;
        amount_of_money -= 10000;
    }
    if (m > 0)
        printf("%d-10000\n", m);

    m = 0;
    while (amount_of_money >= 5000) {
        m++;
        amount_of_money -= 5000;
    }
    if (m > 0)
        printf("%d-5000\n", m);

    m = 0;
    while (amount_of_money >= 2000) {
        m++;
        amount_of_money -= 2000;
    }
    if (m > 0)
        printf("%d-2000\n", m);

    m = 0;
    while (amount_of_money >= 1000) {
        m++;
        amount_of_money -= 1000;
    }
    if (m > 0)
        printf("%d-1000\n", m);

    m = 0;
    while (amount_of_money >= 500) {
        m++;
        amount_of_money -= 500;
    }
    if (m > 0)
        printf("%d-500\n", m);

     m = 0;
    while (amount_of_money >= 200) {
        m++;
        amount_of_money -= 200;
    }
    if (m > 0)
        printf("%d-200\n", m);

    m = 0;
    while (amount_of_money >= 100) {
        m++;
        amount_of_money -= 100;
    }
    if (m > 0)
        printf("%d-100\n", m);

    m = 0;
    while (amount_of_money >= 50) {
        m++;
        amount_of_money -= 50;
    }
    if (m > 0)
        printf("%d-50\n", m);

    m = 0;
    while (amount_of_money >= 20) {
        m++;
        amount_of_money -= 20;
    }
    if (m > 0)
        printf("%d-20\n", m);

    m = 0;
    while (amount_of_money >= 10) {
        m++;
        amount_of_money -= 10;
    }
    if (m > 0)
        printf("%d-10\n", m);

    m = 0;
    while (amount_of_money >= 5) {
        m++;
        amount_of_money -= 5;
    }
    if (amount_of_money >= 3)
        m++;

    if (m > 0)
        printf("%d-5\n", m);

    return 0;
}
