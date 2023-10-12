#include <stdio.h>
#include <stdlib.h> 

/**
 * This explains how noes are created
 * it is the first implemetation of a 
 * doubly linked list
 * i will implement the others in the other files
 */

typedef struct node
{
    int data; /* The data you want to store*/
    struct node *next;/* A pointer to the next node */
    struct node *prev;/* A pointer to the previous*/

}node;

int main(void)
{
    /* Declaring a variable to traverse*/
    node *current;

    /* Create and allocate meemory for nodes*/
    node *first = malloc(sizeof(struct node));
    node *second = malloc(sizeof(struct node));
    node *third = malloc(sizeof(struct node));

    /* Setting data to the nodes*/
    first->data = 13;
    second->data = 18;
    third->data = 25;

    /* Linking the nodes*/
    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;
    
    /* Traversal*/
    current = first; /* We are setting a current to point to the first*/

    while (current != NULL)
    {
        printf("Data : %d\n", current->data);
        current = current->next;
    }

    /* Free memory*/
    free(first);
    free(second);
    free(third);

    return 0;

}


