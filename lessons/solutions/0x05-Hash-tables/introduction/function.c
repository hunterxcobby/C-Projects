#include "def_struct.h"

ht_item* create_item(char* key, char* value)
{
    /*Creates a pointer to a new HashTable item.*/

    /* ALlocate memory for the items*/
    ht_item* item = (ht_item*) malloc(sizeof(ht_item));
    item->key = malloc(strlen(key) + 1);
    item->value = malloc(strlen(value) + 1);
    
    /* return a copy the item */
    strcpy(item->key, key);
    strcpy(item->value, value);
    return item;
}

hashtable* create_table(int size)
{
    int i;
    
    /* Create a new hash table*/
    hashtable *table = malloc(sizeof(hashtable));
    table->size = size;
    table->count = 0;
    table->items = calloc(table->size, sizeof(ht_item*));

    /* TO set all the elements of the hashtable to null*/
    for (i = 0; i < table->size; i++)
        table->items[i] = NULL;

    return table;

}