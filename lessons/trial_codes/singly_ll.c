#include <stdio.h>
#include <stdlib.h>

/* define a custom data structure for a node in a linked list */
typedef struct node
{
	int data;
	struct node *next;
}node;

/* Global variables to keep track of the head and other nodes in the linked list */
node *head;
node *newnode;
node *temp;

int main(void)
{
	/* create a new node and allocate memory for it */ 
	newnode = (node*)malloc(sizeof(struct node));
	/* Check if memory allocation was successful */
	if (newnode == NULL) 
	{
		printf("Memory allocation failed!\n");
		return (1); /* return 1 to indicate an error*/
	}

	printf("Memory allocation success!\n");

	newnode->data = 10;
	newnode->next = NULL;
	printf("This is data = %d \n", newnode->data);
	printf("This is next data memory = %p \n", newnode->next);

	// newnode->data = 20;
	// newnode->next = NULL;
	// printf("This is data = %d \n", newnode->data);
	// printf("This is next data memory = %p \n", newnode->next);

	return 0;
}

