#include "main.h"

void mixed_operations(void)
{
    int max_operations = 10;
    int operation_count = 0;
    char operation;
    double number;
    int i;
    double result;
    double numbers[15];
    char operations[15];

    /* Collect operations and numbers from the user*/
    printf("Enter operation (+, -, *, /, 0 to stop): ");

    while (1) 
    {

        scanf(" %c", &operation); /* Note the space before %c to skip whitespace characters */
        
        if (operation == '0') 
        {
            break; /* Exit the loop when '0' is entered as operation*/
        }

        /* Make sure to also get the corresponding number */
        scanf("%lf", &number); 

        if (operation_count < max_operations) /* Check if max_operations limit is not reached*/
        {
            operations[operation_count] = operation;
            numbers[operation_count] = number;
            operation_count++;
        }
        else
        {
            printf("Maximum number of operations reached.\n");
            break; /* Exit the loop if max_operations limit is reached*/
        }
    }

    /* Call the calculate function with collected data */
    result = numbers[0];

    for (i = 0; i < operation_count; i++) 
    {
        result = mixed(2, result, operations[i], numbers[i + 1]);
    }

    printf("Result: %.2f\n", result);
}

