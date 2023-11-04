#include "def_struct.h"

/**
 * Think of the overflow buckets like extra shelves in a library. 
 * When the main shelves (the HashTable) are full, 
 * the librarian (the program) takes out some extra shelves (the overflow buckets) 
 * and puts books there.
*/

/**
 * The first function (create_overflow_buckets) creates the extra shelves 
 * and makes sure they're all empty. 
 * It returns the list of extra shelves.
*/

/* This function creates and manages overflow buckets for a HashTable. */

LinkedList** create_overflow_buckets(hashtable* table)
{
    int i;
    /* Create the overflow buckets; an array of LinkedLists.*/
    LinkedList** buckets = (LinkedList**) calloc(table->size, sizeof(LinkedList*));

    for (i = 0; i < table->size; i++)
        buckets[i] = NULL; /* Initialize each slot to be empty. */

    return buckets; /* Return the array of overflow buckets. */
}


/**
 * The second function (free_overflow_buckets) is like a cleaning crew 
 * that comes in when the library is closing. They make sure all 
 * the extra shelves are empty, 
 * and then they take away the shelves themselves.
*/

void free_overflow_buckets(hashtable* table)
{
    int i;
    /* Free all the overflow bucket lists.*/
    LinkedList** buckets = table->overflow_buckets; /* Get the array of overflow buckets. */

    for (i = 0; i < table->size; i++)
        free_linkedlist(buckets[i]); /* Free each linked list in the overflow buckets. */

    free(buckets); /* Free the memory for the array of overflow buckets. */
}
