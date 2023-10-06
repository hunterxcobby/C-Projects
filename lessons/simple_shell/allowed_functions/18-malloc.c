int main(void) 
{
    char *buffer; /* Declare a pointer to hold allocated memory*/
    
    /* Allocate memory for a string */
    buffer = (char *)malloc(10 * sizeof(char)); /* Allocate memory for a string of 10 characters*/
    
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n"); /* Print an error message if allocation fails*/
        return 1; /* Return an error code*/
    }
    
    /* Use the allocated memory */
    sprintf(buffer, "Hello"); /* Write "Hello" into the allocated memory*/
    
    printf("String: %s\n", buffer); /* Print the string*/
    
    /* Free the allocated memory when done */
    free(buffer); /* Release the allocated memory*/
    
    return 0; /* Return success*/
}
