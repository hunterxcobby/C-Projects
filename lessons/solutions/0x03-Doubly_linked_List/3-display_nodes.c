#include <stdio.h>
#include <stdlib.h>

/**
 * In this file, we will implement how to display
 * the given nodes we will 
 * take from the user
 */

void display(void);

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
/* Introduce a temp node*/
node *temp = NULL;

int count = 1;

/* A function to create new node*/
void create_node(void)
{
   

    /* ALlocate memory for the new node*/
     newnode = malloc(sizeof(struct node ));/* 20 bytes will be allocated*/

     /* Take data from user*/
     printf("Enter the data %d:\n", count);
     scanf("%d", &newnode->data);/* You can also write "(*newnode).data"*/
      count++;  
    /* Display the data to them*/
     /*printf("Data:%d\n", newnode->data);*/
     newnode->next = 0;
     newnode->prev = 0; /* Because they do not point to anything yet*/
     /*printf("Address: %p\n", newnode->next);uncomment to see address of next node*/

   
    /* Insert data as the first node*/
    if (head == 0)
    {
        /* If head is empty then we insert this as first node */
        head = temp = newnode;/* So both the head and temp holds the newnode*/
    }
    else /* Insert data as the next node*/
    {
        /* Point the first node's address to the next node*/
        temp->next = newnode; /* Link the newnode to the previous node*/
        /* Point the new node's address to the previous node*/
        newnode->prev = temp; /* Link the previous node to the new node */
        /* Temp will hold the second node now so we can have a third node*/
        temp = newnode;
    }

}

/*  This is the main function*/
int main(void)
{
    int numNodes, i;
    printf("How many nodes do you want to create?:\n");
    scanf("%d", &numNodes);

    for (i = 0; i < numNodes; i++) {
        create_node();
    }

    display();

    free(newnode); /* Remember to free node after using*/
    return(0);
}

/* Function to display the nodes*/
void display(void)
{
    temp = head;

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
        count++;
    }
}