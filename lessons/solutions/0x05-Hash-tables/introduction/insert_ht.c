#include "def_struct.h"

/* This function inserts an item into a HashTable. */

void ht_insert(hashtable *table, char *key, char *value)
{
    int index; /* The index where the item will be inserted. */
    ht_item *item; /* The item to be inserted. */

    /* First create the item */
    item = create_item(key, value); /* Create a new item with the provided key and value. */

    /* Compute the index using the hash function */
    index = hash_function(key); /* Find the slot in the table where the item belongs. */

    ht_item* current_item = table->items[index]; /* Get the item currently at that index. */

    /* When inserting the key for the first time, the item must be NULL */
    if (current_item == NULL)
    {
        /* Key does not exist. */

        if (table->count == table->size)
        {
            /* HashTable is full. */
            printf("Insert Error: Hash Table is full\n");
            free_item(item); /* Clean up the item since it won't be added. */
            return;
        }

        /* Insert directly. */
        table->items[index] = item; /* Place the new item in the table. */
        table->count++; /* Increase the count of items in the table. */
    }
    else 
    {
        /* Scenario 1: Update the value. */

        /* The { key: value } pair already exists */
        if (strcmp(current_item->key, key) == 0)
        {
            strcpy(table->items[index] -> value, value); /* Update the value. */
            return;
        }
        else 
        {
            /* Scenario 2: Handle the collision. */
            handle_collision(table, item); /* Handle the case where there's a collision. */
            return;
        }
    }

    return; /* This function does not return anything, so 'return;' is enough. */
}


/**
 * This function is like a manager at a hotel. 
 * When you arrive with a new guest (the item), 
 * the manager first checks if there's a room available (by using the hash function to find an index). 
 * If there's a room available, the guest is checked in. If the room is already occupied, 
 * the manager checks if it's the same guest who has stayed before (by comparing keys). 
 * If it's the same guest, the manager updates the details. 
 * If it's a different guest, the manager finds a new room (by handling the collision).
 * If the hotel is full, the manager apologizes and asks the guest to come back later.
*/