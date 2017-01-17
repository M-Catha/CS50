#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
 
int main(void) {
    printf("");
    string userName = GetString();
    
    // Print first character of name (to upper case)
    printf("%c", toupper(userName[0]));
    
    for (int i = 0, n = strlen(userName); i < n; i++) {
        
        // Print uppercase character after space
        if (isspace(userName[i])) {
            printf("%c", toupper(userName [i + 1]));
        }
    }
    // Print new line after all initials
    printf("\n");
}