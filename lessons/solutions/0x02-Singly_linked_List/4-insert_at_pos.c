#include <stdio.h>
#include <stdlib.h>

/* Remember this code does not run because I did not write a test code for it*/

/**
 * This is a code to implement the concept
 * of a singly linked to my future self and 
 * any other developer who chances upon it 
 * whiles leanring the C language
 */

/**
 * In this file, we are going to demonstrate how
 * to insert a node at the a given position
 * of a linked list,
 * we already assume the list has been created
 * check the previous files to see a demonstration of how 
 * to create a linked list.
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
    node *temp = NULL; /* This is our temporary pointer*/

    int count = 1;
    int position, i; /* This is a variable to store the postion we will take from the user*/

/* A function to insert a node at a given position*/
void insert_pos()
{
    /* Allocate memory for the newnode*/
    newnode = malloc(sizeof(struct node));
    
    /* Take the psotion from the user */
    printf("Enter the data to insert: %d\n", count);
    scanf("%d", &newnode->data);
    count ++;

   temp = head;
  
    
} 

int main(void)
{
    
    node *current = NULL;
    int position;

    /* This is the list*/
    node list = {8, 9, NULL};
    
    /* Ask the user the user the position they want to insert the node*/
    /*printf("Enter the position you want to insert your data: %d\n");
    scanf("%d", &position);

    if (position < list)
    {
        printf("The position ':%d' you entered does not exist in the list\n", position);
    }
    else
    {
        insert_pos();
    }*/

    return(0);
}
