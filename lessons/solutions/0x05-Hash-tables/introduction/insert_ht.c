#include "def_struct.h"

void ht_insert(hashtable *table, char *key, char *value)
{
    int index;
    ht_item *item;
    /*First create the item*/
    item = create_item(key, value);

    /*compute the index using the function*/
    index = hash_function(key);

    ht_item* current_item = table->items[index];

    /*When inserting the key for the first time, the item must be a NULL:*/
    if (current_item == NULL)
    {
        /* Key does not exist.*/
        if (table->count == table->size)
        {
            /* HashTable is full.*/
            printf("Insert Error: Hash Table is full\n");
            free_item(item);
            return;
        }

        /* Insert directly.*/
        table->items[index] = item;
        table->count++;
    }
    else 
    {
        /* Scenario 1: Update the value.*/
        /*the { key: value } pair already exists*/
        if (strcmp(current_item->key, key) == 0)
        {
            strcpy(table->items[index] -> value, value);
            return;
        }
        else 
        {
            /* Scenario 2: Handle the collision.*/
            handle_collision(table, item);
            return;
        }
    }
    
    return(0);
}