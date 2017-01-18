/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdint.h>
 #include <cs50.h>

typedef uint8_t BYTE;

bool containsByte(BYTE jpegByte);


int main(int argc, char* argv[])
{
    
    // Variables
    int block = 512;        // Size of block to be read
    int jpgNumber = 0;      // Initialize jpg counter
    BYTE buffer[block];     // Create array of type BYTE of size block
    FILE* output = NULL;    // Initialize output file to NULL
    char fileName[8];       // Create array of char with size 8 (7 characters + escape character)
    
    // open input file 
    FILE* card = fopen("card.raw", "r");
    if (card == NULL)
    {
        printf("Could not open card.raw.\n");
        return 2;
    }
    
    // Should return "1" upon each successful read of 1 block of 512 bytes
    // If not, EOF has been reached
    while(fread(buffer, block, 1, card) == 1) { 
      
      if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && containsByte(buffer[3])) {
          
          // Creating file name
          sprintf(fileName, "%03i.jpg", jpgNumber);
            
          // If jpg is open, close it    
          if(output != NULL) {
              fclose(output);
              output = NULL;
          }
          
          // Open new jpg and increment file number
          output = fopen(fileName, "w");
          jpgNumber++;
          
      }
      
      // Only write to output if file is not NULL (skips all unwritten blocks at beginning of card)
      if (output != NULL) {
          fwrite(buffer, block, 1, output);
      }

  }
  
  // Once last image is found and while loop has exited, close last output file and input card
  fclose(output);
  fclose(card);
    
}

bool containsByte(BYTE jpegByte) {
    switch (jpegByte) {
        case 0xe0:
            return true;
        case 0xe1:
            return true;
        case 0xe2:
            return true;
        case 0xe3:
            return true;
        case 0xe4:
            return true;
        case 0xe5:
            return true;
        case 0xe6:
            return true;
        case 0xe7:
            return true;
        case 0xe8:
            return true;
        case 0xe9:
            return true;
        case 0xea:
            return true;
        case 0xeb:
            return true;
        case 0xec:
            return true;
        case 0xed:
            return true;
        case 0xee:
            return true;
        case 0xef:
            return true;
        default:
            return false;
    }
}
