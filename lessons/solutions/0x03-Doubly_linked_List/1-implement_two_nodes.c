#include <stdio.h>
#include <stdlib.h>

/**
 * This can only insert two nodes 
 * So meaning we will have a problem
 * when want to insert three nodes
 * check the next file for when we
 * want to insert a third node
 * The mechanism we can use
 */

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}node;

/* This is the head pointer that points to the first node*/
node *head; 
node *newnode;
/* Set head to 0*/
node *head = NULL;

/* A function to create new node*/
void create_node(void)
{
    

    /* ALlocate memory for the new node*/
     newnode = malloc(sizeof(struct node ));/* 20 bytes will be allocated*/

     /* Take data from user*/
     printf("Enter the data:\n");
     scanf("%d", &newnode->data);/* You can also write "(*newnode).data"*/

    /* Display the data to them*/
     printf("Data:%d\n", newnode->data);
     newnode->next = 0;
     newnode->prev = 0; /* Because they do not point to anything yet*/
     printf("Address: %p\n", newnode->next);/*uncomment to see address of next node*/

    /* Insert data as the first node*/
    if (head == 0)
    {
        /* If head is empty then we insert this as first node*/
        head = newnode;
    }
    else /* Insert data as the next node*/
    {
        /* Point the first node's address to the next node*/
        head->next = newnode; /* Link the newnode to the previous node*/
        /* Point the new node's address to the previous node*/
        newnode->prev = head; /* Link the previous node to the new node */
    }

     free(newnode); /* Remember to free node after using*/
}

int main(void)
{

    create_node();
}