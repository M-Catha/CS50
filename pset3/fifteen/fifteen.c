/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void swapCol(int row, int col, int blankCol);
void swapRow(int row, int col, int blankRow);


int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(200000);
        }
        
        // sleep thread for animation's sake
        usleep(200000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // Use dimension int to determine board size
    int nums = (d*d) - 1;                   
    for (int i = 0; i < d; i++) {           
        for (int j = 0; j < d; j++) {
            board[i][j] = nums;
            nums--;
            }
        }
        
    // If board is even-numbered dimension, swap 1 and 2 tiles
    if (d % 2 == 0) {                     
        int a = board[d - 1][d - 3];
        int b = board[d - 1][d - 2];
        board[d - 1][d - 3] = b;
        board[d - 1][d - 2] = a;
        }  
    
}


/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for (int row = 0; row < d; row++) {
        printf("\n\n");
        for (int col = 0; col < d; col++) {
            
            // Print underscore in 0 place
            if (board[row][col] == 0) {
                printf(" _ ");
            }
            // Else, print number
            else {
            printf("%2d ", board[row][col]);
            }
        }
    }
    printf("\n\n");
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    int blankTileVal = 0;
    
    for (int row = 0; row < d; row++) {
        for (int col = 0; col < d; col++){
            
            int tileRow, tileCol, blankTileRow, blankTileCol;
            
            // If tile value is found, capture its row and column
            if (board[row][col] == tile) {
                tileRow = row;
                tileCol = col;
                
                // If tile is above blank space and does not exceed matrix upper boundaries
                if (board[tileRow + 1][col]  ==  blankTileVal && (tileRow + 1) < d) {
                    blankTileRow = tileRow + 1;
                    swapRow(tileRow, tileCol, blankTileRow);
                    blankTileRow--;
                    return true;
                }
                
                // If tile is below blank space and does not exceed matrix lower boundaries
                else if (board[tileRow - 1][col] == blankTileVal && (tileRow - 1) >= 0)  {
                    blankTileRow = tileRow - 1;
                    swapRow(tileRow, tileCol, blankTileRow);
                    blankTileRow++;
                    return true;
                }
                
                // If tile is to the left of the blank and does not exceed matrix right-most boundary
                else if (board[row][tileCol + 1] == blankTileVal && (tileCol + 1) < d) {
                    blankTileCol = tileCol + 1;
                    swapCol(tileRow, tileCol, blankTileCol);
                    blankTileCol--;
                    return true;
                }
                
                // If tile is to the right of the blank and does not exceed matrix left-most boundary
                else if (board[row][tileCol - 1] == blankTileVal && (tileCol - 1) >= 0) {
                    blankTileCol = tileCol - 1;
                    swapCol(tileRow, tileCol, blankTileCol);
                    blankTileCol++;
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int correctPositions = 0;           // Initialize # of correct positions while iterating
    int size = (d - 1);
    int numComparisons = (d * d) - 1;   // Initialize # of correct positions needed for "win"
    
    for (int row = 0; row < d; row++) {
        for (int col = 0; col < d; col++){
            
            // If the value to the right of the current iterator is greater and does
            // not exceed right-most boundary, increment # of correct positions
            if (board[row][col] < board[row][col + 1] && col != size) {
                correctPositions++;
            }
            // If on the last column...
            else if (col == size) {
                
                // Check the value at the [0]th column of the following row if it does
                // not exceed the matrix lower boundary
                if (board[row][col] < board[row + 1][0] && row != size) {
                    correctPositions++;
                }
                // Catch for blank tile in the bottom-right corner of matrix
                else if (row == size && board[size][size] == 0) {
                    correctPositions++;  
                }
            }
        }
    }
    return (correctPositions == numComparisons);
}

void swapCol(int row, int col, int blankCol) {
    int temp;
    temp = board[row][blankCol];
    board[row][blankCol] = board[row][col];
    board[row][col] = temp; 
}

void swapRow(int row, int col, int blankRow) {
    int temp;
    temp = board[blankRow][col];
    board[blankRow][col] = board[row][col];
    board[row][col] = temp; 
}