#include "def_struct.h"

/* This function searches for a 'key' in a HashTable.
   If the 'key' is found, it returns the associated value.
   If the 'key' is not found, it returns NULL. */

char* ht_search(hashtable* table, char* key)
{
    /* Searches for the key in the HashTable.
       Returns NULL if it doesn't exist. */

    /* First, we need to figure out where in the HashTable
       we should look for the key. We use a special function
       called hash_function that turns the key into a number. */
    int index = hash_function(key);

    /* Now, let's see if there's something stored at that place
       in the HashTable. */
    ht_item* item = table->items[index];

    /* If there's something there (it's not empty), we'll check if
       the key matches the one we're looking for. */
    if (item != NULL)
    {
        /* If the keys match, that means we found what we were
           looking for, and we can return the associated value. */
        if (strcmp(item->key, key) == 0)
            return item->value;
    }

    /* If we didn't find what we were looking for, we return NULL. */
    return NULL;
}
