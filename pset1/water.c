#include <cs50.h>
#include <stdio.h>

int main(void) 
{
    
    printf("How long were you in the shower (in minutes)?\n");
    int numMinutes = GetInt();
    int numBottles = (1.5 * numMinutes * 128) / 16;
    printf("Your %i minute shower is the equivalent of %i bottles of water wasted!\n", numMinutes, numBottles);
}