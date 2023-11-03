#include "def_struct.h"

void print_table(hashtable* table)
{
    int i;

    printf("\nHash Table\n-------------------\n");

    for (i = 0; i < table->size; i++)
    {
        if (table->items[i])
        {
            printf("Index:%d, Key:%s, Value:%s\n", i, table->items[i] -> key, table->items[i]->value);
        }
    }

    printf("-------------------\n\n");
}