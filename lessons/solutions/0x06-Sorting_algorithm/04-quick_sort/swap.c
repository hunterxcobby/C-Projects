#include "main.h"

/**
 * Function to swap the values of two integers
*/

void swap(int *a, int *b)
{
    /* Create a temporary variable to store the value of 'a'*/
    int temp = *a;

    /* Update the value of 'a' with the value of 'b'*/
    *a = *b;

    /* Update the value of 'b' with the temporary variable (original value of 'a')*/
    *b = temp;
}

/**
 * The function swap takes two integer pointers (a and b) as parameters.
 * It uses a temporary variable (temp) to store the original value of a.
 * it updates the value of a with the value of b.
 * Finally, it updates the value of b with the original value of a stored in the temporary variable.
*/

