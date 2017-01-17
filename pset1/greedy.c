#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main(void) {

    double change;
    do {
    printf("What is the total price?\n");
    change = GetFloat();
    }
    
    while (change <= 0);
    
    // Get change from dollars
    
    double getDollars = floor(change);
    int getCoins = getDollars * 4;
    
    // Convert remaining change to int
    
    double getChange = change - getDollars;
    int convChange = (getChange * 100) + 0.5;
    
    // Coin values
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    
    // Get # of quarters
    while (convChange >= quarter) {
        getCoins++;
        convChange -= quarter;
    }
    
    // Get # of dimes
    while (convChange >= dime) {
        getCoins++;
        convChange -= dime;
    }
    
    // Get # of nickels
    while (convChange >= nickel) {
        getCoins++;
        convChange -= nickel;
    }
    
    // Get # of pennies
    while (convChange > 0) {
        getCoins++;
        convChange -= penny;
    }
    
    printf("%i\n", getCoins);

}