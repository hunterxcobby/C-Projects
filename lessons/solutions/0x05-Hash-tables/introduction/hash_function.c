#include "def_struct.h"

/* This function calculates the hash value for a given string. */

#define CAPACITY 50000 /* Size of the HashTable.*/

unsigned long hash_function(char* str)
{
    unsigned long i = 0; /* Initialize a variable to keep track of the hash value. */

    for (int j = 0; str[j]; j++)
        i += str[j]; /* Add the ASCII values of each character in the string. */

    return i % CAPACITY; /* Return the remainder of dividing the sum by the CAPACITY. */
}

/**
 * Think of this function like a special machine that takes a word (the string) and turns it into a number (the hash value). 
 * It works by adding up the values of the letters in the word (using their ASCII values) 
 * and then doing some math to make sure the number isn't too big. 
 * This way, the number will fit nicely into a slot in the hash table.
*/