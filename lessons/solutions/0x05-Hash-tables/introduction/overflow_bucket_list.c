#include "def_struct.h"

/* Function to allocate memory for a new linked list node. */
LinkedList* allocate_list()
{
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList)); /* Allocate memory for a new node. */
    return list;
}

/* Function to insert a new item into the linked list. */
LinkedList* linkedlist_insert(LinkedList* list, ht_item* item)
{
    LinkedList *temp;
    LinkedList *node;

    if (!list)
    {
        /* If the list is empty, create a new list and make it the head. */
        LinkedList* head = allocate_list();
        head->item = item;
        head->next = NULL;
        list = head;
        return list;
    }
    else if (list->next == NULL)
    {
        /* If there's only one item in the list, create a new one and link them together. */
        LinkedList* node = allocate_list();
        node->item = item;
        node->next = NULL;
        list->next = node;
        return list;
    }

    temp = list;

    while (temp->next->next)
    {
        temp = temp->next;
    }

    /* Find the last item in the list and add a new item after it. */
    node = allocate_list();
    node->item = item;
    node->next = NULL;
    temp->next = node;
    return list;
}

/* Function to remove and return the first item from the linked list. */
ht_item* linkedlist_remove(LinkedList* list)
{
    LinkedList *node;
    LinkedList *temp;
    ht_item *it;

    if (!list)
        return NULL;

    if (!list->next)
        return NULL;

    node = list->next;
    temp = list;
    temp->next = NULL;
    list = node;
    it = NULL;
    memcpy(temp->item, it, sizeof(ht_item)); /* Copy a null item to the removed node. */
    free(temp->item->key); /* Free memory for the key of the removed item. */
    free(temp->item->value); /* Free memory for the value of the removed item. */
    free(temp->item); /* Free memory for the removed item. */
    free(temp); /* Free memory for the removed node. */
    return it; /* Return the removed item (which is NULL in this case). */
}

/* Function to free memory used by the linked list. */
void free_linkedlist(LinkedList* list)
{
    LinkedList* temp = list;

    while (list)
    {
        temp = list;
        list = list->next;
        free(temp->item->key); /* Free memory for the key of each item. */
        free(temp->item->value); /* Free memory for the value of each item. */
        free(temp->item); /* Free memory for each item. */
        free(temp); /* Free memory for each node. */
    }
}


/**
 * Imagine you have a train (linked list) where each carriage (node) can hold an item. 
 * The item is like a box with a key and a value inside.
 * 
 * allocate_list creates a new carriage for the train.
 * @ : linkedlist_insert adds a new carriage to the end of the train.
 * @ : linkedlist_remove takes off the first carriage from the train and gives you the item inside.
 * @ : free_linkedlist is like dismantling the entire train, taking out each item, and throwing away the empty carriages.
This linked list helps manage items in the HashTable, especially when there are more items than slots available.
*/