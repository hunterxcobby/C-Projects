#include <stdio.h>
#include <string.h>

int main(void) 
{
    /* Declare a character array named 'str' and initialize it with the given string.*/
    char str[] = "Hello, World! How are you?";

    /* Declare a string of characters that will be used as delimiters.*/
    const char delimiters[] = " ,!?";

    /* Declare a pointer to a character named 'token' and initialize it with the first token found in 'str'.*/
    char *token = strtok(str, delimiters);

    /* Loop as long as 'token' is not NULL.*/
    while (token != NULL) {
        /* Print the token.*/
        printf("%s\n", token);

        /* Find the next token in 'str'.*/
        token = strtok(NULL, delimiters);
    }

    /* Indicate successful execution of the program.*/
    return 0;
}

