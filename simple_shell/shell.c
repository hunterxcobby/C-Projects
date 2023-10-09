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
            /**
             * Here we can check if the token is a built-in command like (i.e, cd, exit)
             * And handle it separately  
             */

            /* If it is not a built in command, we execute it*/
            pid_t pid = fork();

            if (pid == 1)
            {
                perror("Fork failed");
                return(-1);
            }
            else if (pid == 0)
            {
                /* This is the child process*/
                char *cmdPath = get_path(token);/* Assuming we have a function called getpath to find the command's path*/
                if (cmdPath == NULL)
                {
                    perror("Command not found");
                    exit(1);
                }

                /* We execute the command with execve*/
                execve(cmdPath, &token, __environ);

                /* Check if evecve fails*/
                if (execve(cmdPath, &token, __environ) == -1)
                {
                    perror("Failed to execute program");
                    exit(EXIT_FAILURE); /* Indicate the command could not be executed*/
                }

            }
        }

        return(0);
    }

}