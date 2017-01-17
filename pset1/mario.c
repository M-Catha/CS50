#include <cs50.h>
#include <stdio.h>

int main(void) {
    
   
    int pyrHeight;
    do {
         printf("Please enter a pyramid height that is between 0 and 24\n");
         pyrHeight = GetInt();
    }
    
    while (pyrHeight < 0 || pyrHeight > 23);
    
   for (int x = 0; x < pyrHeight; x++) {
      for (int i = 1; i < pyrHeight - x; i++) {
          printf(" ");
      }
      for (int j = 0; j < x + 2; j++) {
          printf("#");
      }
      printf("\n");
   }
}
