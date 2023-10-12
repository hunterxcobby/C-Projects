#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}node;

/* This is the head pointer that points to the first node*/
node *head; newnode;

/* A function to create new node*/
void creat_node(void)
{
    /* ALlocate memory for the new node*/
     newnode = malloc(sizeof(struct node ));/* 20 bytes will be allocated*/
     printf("Enter the data:%s\n");
     scanf("%d", & newnode->data);/* You can also write "(*newnode).data"*/
}

int main(void)
{

}