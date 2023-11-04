#include "def_struct.h"

/* When there is the need to handle a collision*/
/* This function handles collisions in a HashTable. */

void handle_collision(hashtable* table, unsigned long index, ht_item* item)
{
    LinkedList* head = table->overflow_buckets[index]; /* Get the linked list at the specified index. */

    if (head == NULL)
    {
        /* If the linked list is empty, create a new list and add the item to it. */
        head = allocate_list(); /* Create a new linked list. */
        head->item = item; /* Set the item for the linked list. */
        table->overflow_buckets[index] = head; /* Assign the new list to the overflow bucket. */
        return;
    }
    else 
    {
        /* If the linked list is not empty, insert the item into the existing list. */
        table->overflow_buckets[index] = linkedlist_insert(head, item); /* Add the item to the list. */
        return;
    }
}


/**
 * Think of this function as the librarian's helper. 
 * When two books (items) have the same title (hash value), 
 * the librarian asks for help. If the extra shelf (linked list) is empty, 
 * the helper creates a new shelf and puts the book on it. 
 * If the shelf already has books, the helper just adds one more.
 * 
 * In this case, the extra shelves are the overflow_buckets, 
 * and each shelf is a linked list. 
 * If there's already a linked list at the specified index, 
 * the function adds the new item to it. If not, 
 * it creates a new linked list and assigns it to that index.

*/