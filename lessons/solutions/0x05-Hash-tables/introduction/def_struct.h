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

    LinkedList **overflow_buckets;
    int size; /* TO return the size of the hash table*/
    int count; /* To return the number of items in the hash table*/

}hashtable;

/* Defines the LinkedList. */
typedef struct LinkedList 
{
    ht_item *item; /* Pointer to an item in the HashTable. */
    struct LinkedList *next; /* Pointer to the next node in the linked list. */
} LinkedList;


/* The function prototypes*/

ht_item *create_item(char *key, char *value);
hashtable *create_table(int size);
unsigned long hash_function(char *str);
void ht_insert(hashtable *table, char *key, char *value);
ht_item *create_item(char *key, char *value);
LinkedList *allocate_list();
LinkedList *linkedlist_insert(LinkedList *list, ht_item *item);
ht_item *linkedlist_remove(LinkedList *list);
void free_linkedlist(LinkedList *list);
LinkedList **create_overflow_buckets(hashtable *table);
void free_overflow_buckets(hashtable *table);
void handle_collision(hashtable *table, unsigned long index, ht_item *item);
char *ht_search(hashtable *table, char *key);
void print_search(hashtable *table, char *key);
void ht_delete(hashtable *table, char *key);
void print_table(hashtable *table);
void free_item(ht_item *item);
void free_table(hashtable *table);

#endif /*DEF_STRUCT_H*/