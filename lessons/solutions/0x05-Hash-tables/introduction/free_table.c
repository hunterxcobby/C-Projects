#include "def_struct.h"

void free_item(ht_item* item)
{
    /* Frees an item.*/
    free(item->key);
    free(item->value);
    free(item);
}

void free_table(hashtable* table)
{
    int i;
    
    /* Frees the table.*/
    for (i = 0; i < table->size; i++)
    {
        ht_item* item = table->items[i];

        if (item != NULL)
            free_item(item);
    }

    free(table->items);
    free(table);
}

