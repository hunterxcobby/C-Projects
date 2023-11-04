#include "def_struct.h"

/* This function deletes an item from the HashTable. */

void ht_delete(hashtable* table, char* key)
{
    /* Deletes an item from the table.*/
    int index = hash_function(key); /* Find the index where the item is located. */
    ht_item* item = table->items[index]; /* Get the item at that index. */
    LinkedList* head = table->overflow_buckets[index]; /* Get the linked list at that index. */

    if (item == NULL)
    {
        /* If there's no item at that index, it doesn't exist.*/
        return;
    }
    else 
    {
        if (head == NULL && strcmp(item->key, key) == 0)
        {
            /* If there's no linked list and the item matches the key, remove the item.*/
            /* Set table index to NULL.*/
            table->items[index] = NULL; /* Remove the item from the table. */
            free_item(item); /* Clean up the item. */
            table->count--; /* Decrease the count of items in the table. */
            return;
        }
        else if (head != NULL)
        {
            /* If there's a linked list (collision chain).*/
            if (strcmp(item->key, key) == 0)
            {
                /* If the item matches the key, remove this item and update the linked list.*/
                free_item(item); /* Clean up the item. */
                LinkedList* node = head; /* Get the first node in the linked list. */
                head = head->next; /* Move to the next node. */
                node->next = NULL; /* Disconnect the node from the list. */
                table->items[index] = create_item(node->item->key, node->item->value); /* Create a new item with the same key and value. */
                free_linkedlist(node); /* Clean up the node. */
                table->overflow_buckets[index] = head; /* Update the linked list in the overflow bucket. */
                return;
            }

            LinkedList* curr = head; /* Start from the beginning of the linked list. */
            LinkedList* prev = NULL; /* Keep track of the previous node. */

            while (curr)
            {
                if (strcmp(curr->item->key, key) == 0)
                {
                    if (prev == NULL)
                    {
                        /* If it's the first element in the chain, remove the entire chain.*/
                        free_linkedlist(head); /* Clean up the linked list. */
                        table->overflow_buckets[index] = NULL; /* Set the overflow bucket to be empty. */
                        return;
                    }
                    else
                    {
                        /* If it's somewhere else in the chain, remove the current node.*/
                        prev->next = curr->next; /* Update the links. */
                        curr->next = NULL; /* Disconnect the node from the list. */
                        free_linkedlist(curr); /* Clean up the node. */
                        table->overflow_buckets[index] = head; /* Update the linked list in the overflow bucket. */
                        return;
                    }
                }

                prev = curr; /* Move the previous pointer. */
                curr = curr->next; /* Move to the next node. */
            }
        }
    }
}
