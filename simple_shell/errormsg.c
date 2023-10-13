#include "main.h"


void err_msg(char *command)
{
    /* For the error msg*/
    char *error_msg;
    char *error_msg2;

/* Display an error message to the screen*/
    error_msg = "Command '";
    write(STDERR_FILENO, error_msg, strlen(error_msg));
    write(STDERR_FILENO, command, strlen(command));
    error_msg2 = "' not found\n";
    write(STDERR_FILENO, error_msg2, strlen(error_msg2));
    exit(EXIT_FAILURE);/* This goes back to the child process*/
}