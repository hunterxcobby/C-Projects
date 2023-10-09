#include "main.h"

/**
 * This basically contains
 * the path to search
 */

char *get_path(char *command) /* It takes the tokenized string as argument as calls it a command*/
{
    char *path = getenv("PATH");
    char *path_copy = strdup(path);/* Not to modify the original environment variable*/

    char *dir = strtok(path_copy, ":");
    
    /* A loop to iterate  and concatenate*/
    while(dir != NULL)
    {
        char *full_path = malloc(strlen(dir) + strlen(command) + 2);
        sprintf(full_path, "%s/%s", dir, command);

        /* Check if the file is executable*/
        if (access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return (full_path);
        }
        free(full_path);
        dir = strtok(NULL, ":");/* Proceed to the next directory*/
    }
    free(path_copy);
    /* if no executable is found, it returns NULL*/
    return (NULL);
}