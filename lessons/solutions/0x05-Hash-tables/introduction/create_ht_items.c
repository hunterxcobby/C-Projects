#include "def_struct.h"

/* This function creates a new item for a HashTable. */
/**
 * This function is like a craftsman who creates a special box (the ht_item) to hold two things:
 * a key and a value. The craftsman carefully makes sure the box is the right size 
 * and shape for the key and value. Then, the key and value are placed inside the box, 
 * and the craftsman hands you the finished product.
 */

ht_item* create_item(char* key, char* value)
{
    /* Creates a pointer to a new HashTable item. */

    /* Allocate memory for the items */
    ht_item* item = (ht_item*) malloc(sizeof(ht_item));
    item->key = malloc(strlen(key) + 1); /* Allocate memory for the key. */
    item->value = malloc(strlen(value) + 1); /* Allocate memory for the value. */

    /* Copy the key and value */
    strcpy(item->key, key); /* Copy the key into the allocated memory. */
    strcpy(item->value, value); /* Copy the value into the allocated memory. */

    return item; /* Return the newly created item. */
}


/* This function creates a new HashTable. */
/**
 * This function is like a magician who creates a new magic box (the hashtable). 
 * The magician first makes sure the box is the right size and shape. 
 * Then, the magician sets the size and count for the box, and creates slots for items. 
 * The magician even makes sure all the slots are empty before giving you the magic box.
*/
hashtable* create_table(int size)
{
    int i;

    /* Create a new hash table */
    hashtable *table = malloc(sizeof(hashtable)); /* Allocate memory for the hash table. */
    table->size = size; /* Set the size of the table. */
    table->count = 0; /* Initialize the count of items to 0. */
    table->items = calloc(table->size, sizeof(ht_item*)); /* Allocate memory for an array of item pointers. */

    /* Set all the elements of the hashtable to null */
    for (i = 0; i < table->size; i++)
        table->items[i] = NULL; /* Initialize each slot to be empty. */

    table->overflow_buckets = create_overflow_buckets(table);

    return table; /* Return the newly created hash table. */
}



