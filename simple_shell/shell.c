#include "main.h"

int main(void)
{
    /* Declare variables*/
    char *line = NULL;
    size_t len = 0;
    int characters_read;

    /* Sring tokenization*/
    char *delimiters = " "; /* Set an empty string as a delimiter*/
    char *token;

    printf("shell$ ");
    /* Getting users input*/
    characters_read = getline(&line, &len, stdin);

    if (characters_read == -1)
    {
        perror("Error reading input");
        return(-1);
    }
    else
    {
        /* Process the input using string tokenization*/
        token = strtok(line, delimiters);
        while(token != NULL)
        {
            printf("%s\n", token);
            token = strtok(NULL, delimiters);
        }

        return(0);
    }

}