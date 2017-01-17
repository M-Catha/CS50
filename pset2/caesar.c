#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[]) {

    if (argc != 2 || atoi(argv[1]) < 0) {  // Handles, negative key, no key, or >1 keys
        printf("Your arguments are not valid! Please try again!\n");
        return 1;
    }
    
    else {
        
        int key = atoi(argv[1]);  // Convert key from string to int
        
        if (key > 26) { // Handle keys > 26
        key %= 26;
        }
        
        printf("What shall will be encoded?\n");
        string newCipher = GetString();
    
        for (int i = 0, n = strlen(newCipher); i < n; i++) {
             
            int alphaToInt = newCipher[i];                  // Stores each letter as int decimal
            int valueCheck = alphaToInt + key;              // Finds ASCII decimal value with key added
            int alphaWrapAround = (alphaToInt + key) - 26;  // Handles characters that must "wrap around"
                
            if (ispunct(alphaToInt) || isspace(alphaToInt)) {    // Prints all characters/spaces without shifting
                printf("%c", alphaToInt);
            } 
            else if (isupper(alphaToInt) && valueCheck > 90) { // Handles uppercase characters that "wrap around"
                printf("%c", alphaWrapAround);
            }
            else if (islower(alphaToInt) && valueCheck > 122) { // Handles lowercase characters that "wrap around"
                printf("%c", alphaWrapAround);
            }
            else {
                printf("%c", valueCheck);
            }
        }
        printf("\n");
    } 

    return 0;

}