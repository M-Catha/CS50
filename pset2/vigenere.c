#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) {

    if (argc != 2) {  // Handles no key or >1 keys
        printf("Please try again!\n");
        return 1;
    }
    
    else {
        string cmdLineKey = argv[1];
        
        for(int i = 0, n = strlen(cmdLineKey); i < n; i++) {  // Iterates over key for nums
            if (isdigit(cmdLineKey[i])) {
                printf("Please try again!\n");
                return 1;
            }
        }
        
        printf("");
        string userInput = GetString();
        
        int cmdLength = strlen(cmdLineKey);  // Initialize counter for iterator
        int j = 0;
        
        for (int i = 0, n = strlen(userInput); i < n; i++){
                     
                int iterator = (j % cmdLength);                            // Set key iterator to continuously loop key                       
                int keyTransform = toupper(cmdLineKey[iterator]) - 65;     // Makes key uniformly uppercase and gets [0-25] value
                int alphaWrapAround = (userInput[i] + keyTransform) - 26;  // Handles characters that must "wrap around"
                int valueCheck = userInput[i] + keyTransform;              // Finds ASCII decimal value with key added
            
                if (ispunct(userInput[i]) || isspace(userInput[i])) {      // Prints all characters/spaces without shifting
                    printf("%c", userInput[i]);
                }
                else if (isupper(userInput[i]) && valueCheck > 90) {       // Handles uppercase characters that "wrap around"
                    printf("%c", alphaWrapAround);
                    j++;
                }
                else if (islower(userInput[i]) && valueCheck > 122) {      // Handles lowercase characters that "wrap around"
                    printf("%c", alphaWrapAround);
                    j++;
                }
                else {
                    printf("%c", valueCheck);
                    j++;
                }
            
        }
    printf("\n");
    }
    return 0;
}