#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

/* Declaration of variables */
/* Declared them globally */

node *head;
node *newnode;
node *temp;

int main(void)
{

	head = NULL; 
	/* Initialize head pointer to NULL, indicating an empty linked list*/

	newnode = (node*)malloc(sizeof(struct node));

	/* Check if memory allocation was successful */
	if (newnode == NULL) 
	{
		printf("Memory allocation failed!\n");
		return (1); /* return 1 to indicate an error*/
	}

	newnode->data = 10;
	newnode->next = NULL;
	printf("This is first data = %d \n", newnode->data);
	printf("This is next data memory = %p \n", newnode->next);

	head = newnode; /* Link the first node to the head of the linked list*/
	printf("head is :%p\n", head);

	/* Allocate memory for the second node*/
	newnode = (node *)malloc(sizeof(struct node));

	if (newnode == NULL)
	{
		printf("Memory allocation failed!\n");
		return 1; /* Return 1 to indicate an error */
	}

	newnode->data = 20;
	newnode->next = NULL;
	printf("This is second data = %d \n", newnode->data);
	printf("This is next data memory = %p \n", newnode->next);

	/* Link the second node to the first node */
	head->next = newnode;
	printf("head is :%p\n", head->next);

	/* Allocate memory for the third node*/
	newnode = (node *)malloc(sizeof(struct node));

	if (newnode == NULL)
	{ printf("Memory allocation failed!\n");
		return (1); /* to indicate error*/
	}

	newnode->data = 30;
	newnode->next = NULL;
	printf("This is  third data = %d\n", newnode->data);
	printf("This is new data memory = %p\n", newnode->next);

	/* Link the third node to the end of the link list.*/
	temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;
	printf("This the head now = %p\n", temp->next = newnode);

	/* Print the linked list for verification*/
	printf("Linked List: ");
	temp = head;
	while (temp != NULL)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");

	return 0;
}


