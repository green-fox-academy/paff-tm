#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Tom, Mark and Jerry went to the supermarket
//help them decide what can they buy out of their money

int tom_money = 2000;
int mark_money = 3500;
int jerry_money = 1200;
int tmj = 0;

void can_they_buy_a_new_tv(/*int your_money*/)
{
    int tv_price = 6950;

    //if they can, the program should write out that how much
    //money they have after they bought the tv
    //if they can't tell, how much money they need to buy it
    if (/*your_money*/tmj - tv_price < 0) {
        printf(" need %d to by a new TV\n", tv_price - tmj/*your_money*/);
    } else {
        printf(" will have %d money after buying a new TV\n", /*your_money*/tmj - tv_price);
    }

    return;
}

void can_they_make_a_cake(int your_money)
{
    int milk = 200;
    int chocolate = 340;
    int flour = 75;
    int egg = 345;
    int sugar = 160;
    int salt = 90;
    int oven_shape = 330;
    int cream = 220;

    int sum = milk + chocolate + flour + egg + sugar + salt + oven_shape + cream;

    if (sum > your_money)
        printf("They have not enough money to make cake.\n");
    else
        printf("They have enough money to make cake. The price is divided by 3 is %d.\n", sum / 3);
    //if they can buy all these stuff calculate how much
    //each of them should pay to share the bill equally

    return;
}

void can_they_make_ham_and_eggs(int your_money)
{
    int milk = 200;
    int egg = 345;
    int salt = 90;
    int ham = 450;
    int onion = 60;
    int spice = 25;

    int sum = milk + egg + salt + ham + onion + spice;

    if (sum > your_money)
        printf("They have not enough money to make ham and eggs.\n");
    else
        printf("They have enough money to make ham and eggs. The price is divided by 3 is %d\n", sum / 3);
    //if they can buy all these stuff calculate how much
    //each of them should pay to share the bill equally

    return;
}

//is there any local or global variables we did not use well?
//are we using functions correctly?

int main()
{
    tmj = tom_money + mark_money + jerry_money;

    printf("Tom");
    can_they_buy_a_new_tv(tom_money);
    printf("Mark");
    can_they_buy_a_new_tv(mark_money);
    printf("Jerry");
    can_they_buy_a_new_tv(jerry_money);
    printf("Tom, Mark and Jerry");
    can_they_buy_a_new_tv(tmj);
    printf("\n");
    can_they_make_a_cake(tmj);
    printf("\n");
    can_they_make_ham_and_eggs(tmj);

	return 0;
}
