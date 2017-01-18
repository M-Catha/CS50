/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
```
bool search(int value, int values[], int n)
{
    
    int midPointValue = values[n / 2];      // Find midpoint from array of values
    int midPointIndex = n / 2;              // Find index of midpoint
    
    while (n > 0) {                         // While number of array indices to inspect "n" is > 0
        if (value < midPointValue) {
            n -= (n/2) + 1;                 // "Subtract" half of array to inspect including old midpoint value
            midPointValue = values[n/2];    // Find new midpoint value from left half of array
        }
        else if (value > midPointValue) {
            n -= (n/2) + 1;                                 // "Subtract" half of array to inspect including old midpoint value
            midPointValue = values[(n/2) + midPointIndex];  // Find new midpoint value from right half of array
        }
        else {                              // If midpoint is not > or < "needle", it must be equal
            return true;
        }
    }
    return false;                           // If all elements are inspected and none match "needle", return false
}
/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{

    for (int i = 0; i < (n - 1); i++) {      // Iterate through array (n - 1) times
        for (int j = 0; j < (n - 1); j++) {  // Iterate over all array values
            if (values[j] > values[j + 1]) { // If first number is higher than adjacent number in array
                
                // Create temp variable to store higher value
                int temp = values[j];  
                
                // Reassign lower number to lower index in array
                values[j] = values[j + 1]; 
                
                // Reassign higher number to higher index in array
                values[j + 1] = temp; 
            } 
        }
            
    }
}
```



