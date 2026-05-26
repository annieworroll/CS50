// Determine smallest number of coins to make
// given change among common US coinage(25c, 10, 5c, 1c)

#include <cs50.h>
#include <stdio.h>

int make_change(int num_cents);

int main()
{
    int num_coins = 0;
    do{
        num_coins = get_int("Change Owed: ");
    }while (num_coins < 0);\
    
    printf("%i\n", make_change(num_coins));
    return 0;
}

int make_change(int num_cents)
{
    int num_coins = 0;

    // Get number of quarters
    num_coins += num_cents / 25;
    num_cents = num_cents % 25;
    // dimes
    num_coins += num_cents / 10;
    num_cents = num_cents % 10;
    // nickels
    num_coins += num_cents / 5;
    num_cents = num_cents % 5;
    // Pennies(rip)
    num_coins += num_cents;

    return num_coins;
}