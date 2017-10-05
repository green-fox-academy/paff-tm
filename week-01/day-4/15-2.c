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
    int amount_of_money = 57553;
    int c1 = 20000, c2 = 10000, c3 = 5000, c4 = 2000, c5 = 1000, c6 = 500, c7 = 200, c8= 100, c9 = 50, c10 = 20, c11 = 10, c12 = 5;
    int m; // remaining money

    m = amount_of_money / c1;
    amount_of_money -= m * c1;
    if (m > 0)
        printf("%d-%d\n", m, c1);

    m = amount_of_money / c2;
    amount_of_money -= m * c2;
    if (m > 0)
        printf("%d-%d\n", m, c2);

    m = amount_of_money / c3;
    amount_of_money -= m * c3;
    if (m > 0)
        printf("%d-%d\n", m, c3);

    m = amount_of_money / c4;
    amount_of_money -= m * c4;
    if (m > 0)
        printf("%d-%d\n", m, c4);

    m = amount_of_money / c5;
    amount_of_money -= m * c5;
    if (m > 0)
        printf("%d-%d\n", m, c5);

    m = amount_of_money / c6;
    amount_of_money -= m * c6;
    if (m > 0)
        printf("%d-%d\n", m, c6);

    m = amount_of_money / c7;
    amount_of_money -= m * c7;
    if (m > 0)
        printf("%d-%d\n", m, c7);

    m = amount_of_money / c8;
    amount_of_money -= m * c8;
    if (m > 0)
        printf("%d-%d\n", m, c8);

    m = amount_of_money / c9;
    amount_of_money -= m * c9;
    if (m > 0)
        printf("%d-%d\n", m, c9);

    m = amount_of_money / c10;
    amount_of_money -= m * c10;
    if (m > 0)
        printf("%d-%d\n", m, c10);

    m = amount_of_money / c11;
    amount_of_money -= m * c11;
    if (m > 0)
        printf("%d-%d\n", m, c11);

    m = amount_of_money / c12;
    amount_of_money -= m * c12;
    switch (amount_of_money) {
    case (3):
    case (4):
        m++;
    }
    if (m > 0)
        printf("%d-%d\n", m, c12);

    return 0;
}
