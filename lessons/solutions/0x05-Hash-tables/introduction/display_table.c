#include "def_struct.h"

/* This function prints the contents of a HashTable. */

void print_table(hashtable* table)
{
    int i;

    printf("\nHash Table\n-------------------\n");

    /* Go through each slot in the table. */
    for (i = 0; i < table->size; i++)
    {
        if (table->items[i])
        {
            /* If there's something stored in this slot, print its details. */
            printf("Index:%d, Key:%s, Value:%s\n", i, table->items[i] -> key, table->items[i]->value);
        }
    }

    printf("-------------------\n\n");
}
