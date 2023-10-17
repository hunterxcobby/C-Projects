#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* THe maximum size for our stack*/
#define LIMIT 3
int top = -1; /* THis represnt the top of the stack and empty*/


void push(int stack[], int element) /* We are using push because in stacks, that is the term*/
{
    
    /* We first check if the stack is full*/
    if (top == LIMIT - 1) /* That is if the stop is equal to 99*/
    {
        printf("This stack is full\n"); 
    }
    else
    {
        /* Else we add to the stack*/
        top++;
        stack[top] = element;
    }
}

int main(void)
{
    int stack[LIMIT]; /* This array will be used to store the elements of the stack*/
    int element = 0;/* Used to store the element you want to push to the stack*/
    int i;

    /* We ask the user for the element affter this condition*/
    for (i = 0; i < LIMIT; i++) 
    {
        printf("Enter the element to be created: ");
        scanf("%d", &element);
        push(stack, element);
    }

    /* To display the contents of the stack*/
    printf("\nThis is the new stack: \n");
    for (i = 0; i <= top; i++) 
    {
        printf(" | %d |\n", stack[i]);
    }
    return (0);
}