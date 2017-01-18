# CS50

All completed homework PSETs from [Harvard's CS50 class](https://cs50.harvard.edu/).  Some assignment sets came with code already provided.  All instances are indicated below.

# PSET1 - C

### Hello.c

A simple program to output "Hello World" using C.

### Water.c

A program that asks the user for input on how long he/she took a shower and calculates the equivalent number of bottles of water use.

### Mario.c

A program that builds a small hash sign half-pyramind based on the user input size.  Looks like:

~~~
       ##
      ###
     ####
    #####
~~~

### Greedy.c

A program that accepts a user's input of change.  The program will return the fewest number of coins necessary to make change.

***

# PSET2 - Crypto

### Initials.c

A program that accepts a user's name and outputs the initials in all CAPS.

### Caesar.c

A progam that accept's a user's string and returns it encoded using [Caesar's cipher](https://en.wikipedia.org/wiki/Caesar_cipher)

### Vigenère.c

A program that accept's a user's key word and a user's string and returns it encoded using [Vigenère's cipher](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher)

***

# PSET3 - Game Of Fifteen

## Find

### Helpers.c

**Wrote search() function and sort() function found within helpers.c.  All other code was provided.**

A program that generates a randomly generated "haystack" of numbers and then searches for the "needle".  The "haystack" is first sorted smallest to largest and then searched using linear search.

### Fifteen.c

**Wrote init(), draw(), move(), won(), swapCol(), and swapRow() function for this program.  All other code was provided.**

An implementation of the [15 puzzle](https://en.wikipedia.org/wiki/15_puzzle) using C.

***

# PSET4 - Forensics

## BMP

### Whodunit.c

**Wrote lines 85 - 89 :).  All other code was provided.**

Recolor provided image to reveal whodunit.  Was mostly used to help understand file structure, file I/O, and how .bmp images are implemented.

### Resize.c

**Wrote lines 70 - 130 for this program.  All other code was provided.**

Resize an image based on user input scale. (i.e. 4 = image height/width x 4).

## JPG

### Recover.c

Recovers "lost" .jpg images on a camera memory card by reading in information from card, dumping information to new file, and repeating until the end of the card is reached.
