#ifndef DEF_STRUCT_H
#define DEF_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Defines the hashtable items */
typedef struct ht_item
{
    char *key;
    char *value;
}ht_item;


/* Define the hash table*/
typedef struct hashtable
{
    /* COntains an array of pointers to the items*/
    ht_item **items;

    int size; /* TO return the size of the hash table*/
    int count; /* To return the number of items in the hash table*/

}hashtable;

ht_item* create_item(char* key, char* value);
hashtable* create_table(int size);

#endif /*DEF_STRUCT_H*/