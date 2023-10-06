#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* Allocate memory for an integer */
    int *ptr = (int *)malloc(sizeof(int));

    if (ptr == NULL) {
        /* Memory allocation failed */
        printf("Error: Memory allocation failed\n");
        return 1; /* Exit with an error status */
    }

    *ptr = 42; /* Assign a value to the allocated memory */

    printf("Value before freeing: %d\n", *ptr);

    /* Free the allocated memory */
    free(ptr);

    /* Accessing 'ptr' after freeing is undefined behavior */
    /* Avoid using 'ptr' from this point onwards */

    return 0;
}
