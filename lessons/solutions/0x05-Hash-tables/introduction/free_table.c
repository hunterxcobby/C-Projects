#include "def_struct.h"

/**
 * These functions are like a janitor who knows how to clean up after a party.
*/

/**
 * The first function (free_item) is responsible for cleaning up a single item (like picking up a piece of trash).
 * It takes the item, gets rid of the key and value (like throwing away garbage), and then gets rid of the item itself
 *  (like putting the trash bag in the dumpster).
*/

/* This function frees an item in the HashTable. */

void free_item(ht_item* item)
{
    /* Frees the memory occupied by an item. */
    free(item->key); /* Free the memory for the key. */
    free(item->value); /* Free the memory for the value. */
    free(item); /* Free the memory for the item itself. */
}

/**
 * The second function (free_table) is like a super janitor. 
 * It goes through all the items in the table and asks the first janitor to clean each one up.
 *  Then, it gets rid of the table itself and the array of items. It's like making sure 
 * the whole party area is clean before closing up
*/

/* This function frees a HashTable. */

void free_table(hashtable* table)
{
    int i;

    /* Frees the memory occupied by the table and its items. */
    for (i = 0; i < table->size; i++)
    {
        ht_item* item = table->items[i]; /* Get the item at index i. */

        if (item != NULL)
            free_item(item); /* If there's an item, free it. */
    }

    free(table->items); /* Free the memory for the array of items. */
    free(table); /* Free the memory for the table itself. */
}

