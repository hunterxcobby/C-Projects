#include <stdio.h>
#include <stdlib.h>

/**
 * This is a file to implement the concept
 * of a singly linked to my future self and 
 * any other developer who chances upon it 
 * whiles leanring the C language
 */

/**
 * Remeber in our previous file we had issues
 * when we try to add a third node
 * In this file we are going to solve that
 * by introducing a third pointer call temp
 * this will tempory hold nodes for it to be 
 * easy to update it with new nodes
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
    node *temp = NULL; /* This is our temp*/

    int count = 1;

/* A function to create a node*/
void create_node(void)
{
    /* Allocate memory for the newnode*/
    newnode = malloc(sizeof(struct node));
    
    /* Take the data from the user */
    printf("Enter data: %d\n", count);
    scanf("%d", &newnode->data);
    count ++;

    newnode->next = NULL;/* Because it does not point to any node now*/
    
    /* We first check if this is the first node*/
    /* That is if head is equal to NULL*/
    if (head == NULL)
    {
        /* Then we assign the new node as the head node */
        head = temp = newnode;
    }
    else /* If the node is not the first node*/
    {
        /* The pointer temp
         now points to the newnode*/
        temp->next = newnode;
        temp = newnode;
    }
} 

int main(void)
{
    /*We will use this to traverse through */
    node *current = NULL;
    int numNodes, i;
    
    /* Ask the user the number of nodes they want to create*/
    printf("How many nodes do you want to create?:\n");
    scanf("%d", &numNodes);

    for (i = 0; i < numNodes; i++) 
    {
        create_node();/* Let us call for our function here*/
    }

    /* We will display the nodes here*/
    current = head;
    /* Let us tranverse through the list*/
    while (current != NULL)
    {
        printf("The data:%d\n", current->data);
        current = current->next;
        count++;
    }
    free(newnode);/* Remember to free node*/
    return(0);
}
