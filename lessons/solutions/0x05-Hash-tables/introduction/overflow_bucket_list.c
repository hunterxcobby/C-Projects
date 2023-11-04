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

    LinkedList* temp = list;

    while (temp->next->next)
    {
        temp = temp->next;
    }

    /* Find the last item in the list and add a new item after it. */
    LinkedList* node = allocate_list();
    node->item = item;
    node->next = NULL;
    temp->next = node;
    return list;
}

/* Function to remove and return the first item from the linked list. */
ht_item* linkedlist_remove(LinkedList* list)
{
    if (!list)
        return NULL;

    if (!list->next)
        return NULL;

    LinkedList* node = list->next;
    LinkedList* temp = list;
    temp->next = NULL;
    list = node;
    ht_item* it = NULL;
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
