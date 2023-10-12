#include <stdio.h>
#include <stdlib.h>

/**
 * We are going to be implementin g
 * how to insert a node 
 * at the beginning of a linked list
 */
void display(void);

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}node;

node *newnode;
node *temp; /* Here we will use it to traverse the list*/
node *head = 0;
node *tail = 0;
int count = 1;


void insert_beg(void)
{
    /* Allocate memory*/
    newnode = malloc(sizeof(struct node));

    /*Insert data */
    printf("Enter data:\n");
    scanf("%d", &newnode->data);

    /* Set the addresses to 0*/
    newnode->next = 0;
    newnode->prev = 0;

    /* Set the firs node*/
    if (head == 0)/* We can not move head because it should always point to the first node */
    {
        head = tail = newnode;
    }
    else
    { /* This will insert the given node at the beginning*/
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}

/*  This is the main function*/
int main(void)
{
    int numNodes, i;
    printf("How many nodes do you want to create?:\n");
    scanf("%d", &numNodes);

    for (i = 0; i < numNodes; i++) {
        insert_beg();
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