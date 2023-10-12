#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}node;

/* This is the head pointer that points to the first node*/
node *head; 
node *newnode;

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

     free(newnode); /* Remember to free node after using*/
}

int main(void)
{

    create_node();
}