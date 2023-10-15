#include <stdio.h>
#include <stdlib.h>

/**
 * This is a file to implement the concept
 * of a singly linked to my future self and 
 * any other developer who chances upon it 
 * whiles leanring the C language
 * Remeber this is only to demonstrate how nodes are
 * created so one ccan only insert two nodes
 * so a problem arises when one wants to add a 
 * third node, check the file to see how we can solve this 
 * problem
 */

/* Create a template for the node using the struct data type*/
typedef struct node
{
    int data ;
    struct node *next;
}node;

    /* Create a pointer called head to store the address of the first node*/
    node *head = NULL; /* Declare the head pointer and set it to NULL*/
    node *newnode;


void create_node(void)
{
    /* Allocate memory for the newnode*/
    newnode = malloc(sizeof(struct node));
    
    /* Take the data from the user */
    printf("Enter data:\n");
    scanf("%d", &newnode->data);
    newnode->next = NULL;/* Because it does not point to any node now*/

    /* We first check if this is the first node*/
    /* That is if head is equal to NULL*/
    if (head == NULL)
    {
        /* Then we assign the new node as the head node */
        head = newnode;
    }
    else /* If the node is not the first node*/
    {
        /* The pointer of the first node now points to the newnode*/
        head->next = newnode;
        head = newnode;
    }
} 

int main(void)
{
    /*We will use this to traverse through */
    node *current = NULL;

    /* Let us call for our funcion here*/
    create_node();

    current = head;
    /* Let us tranverse through the list*/
    while (current != NULL)
    {
        printf("The data:%d\n", newnode->data);
        current = current->next;
    }
    return(0);
}
