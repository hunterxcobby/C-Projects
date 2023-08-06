#include <stdio.h>

/* Function prototype to swap two integers using XOR*/
void swap_int(int *a, int *b);

int main(void)
{
    int a = 10;
    int b = 20;
    
    /* Display the values of a and b before swapping*/
    printf("Before swapping:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    
    /* Call the swap_int function to swap the values of a and b*/
    swap_int(&a, &b);
    
    /* Display the values of a and b after swapping*/
    printf("After swapping:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}

/* Function definition to swap two integers using XOR*/
void swap_int(int *a, int *b)
{
    /* Perform the swap using XOR operations*/
    /* a = a XOR b*/
    *a = *a ^ *b;
    
    /* b = a XOR b (which is now equal to original a)*/
    *b = *a ^ *b;
    
    /* a = a XOR b (which is now equal to original b)*/
    *a = *a ^ *b;
}

