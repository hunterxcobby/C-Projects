#include "main.h"

/**
 * This basically contains
 * the path to search
 */

char *get_path(char *command) /* It takes the tokenized string as argument and calls it a command*/
{

    /* For the error msg*/
    char *error_msg;
    char *error_msg2;
    char *path = getenv("PATH");
    char *path_copy = strdup(path); /* Not to modify the original environment variable*/

    char *dir = strtok(path_copy, ":");

    /* A loop to iterate and concatenate*/
    while (dir != NULL)
    {
        char *full_path = malloc(strlen(dir) + strlen(command) + 2);
        sprintf(full_path, "%s/%s", dir, command);
        /*printf("Constructed full_path: %s\n", full_path);*/

        /* To see what is in full_path*/
        printf("Checking path: %s\n", full_path);

        /* Check if the file exists */
        if (access(full_path, F_OK) == 0 || access(full_path, X_OK) == 0)
        {
            printf("File found\n");
            free(path_copy); /* Free path_copy since it's not used anymore */
            return full_path; /* Return the full path */
        }

        free(full_path);
        dir = strtok(NULL, ":"); /* Proceed to the next directory*/
    }

    /* Display an error message to the screen*/
    error_msg = "Command '";
    write(STDERR_FILENO, error_msg, strlen(error_msg));
    write(STDERR_FILENO, command, strlen(command));
    error_msg2 = "' not found\n";
    write(STDERR_FILENO, error_msg2, strlen(error_msg2));

    exit(EXIT_FAILURE);
    free(path_copy);
    /* if no executable is found, it returns NULL*/
    return NULL;
}
