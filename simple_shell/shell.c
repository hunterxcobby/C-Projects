#include "main.h"

int main(void)
{
        /* Declare variables*/
        char *line = NULL;
        size_t len = 0;
        int characters_read;

        /* Sring tokenization*/
        char *delimiters = " \n"; /* Set an empty string as a delimiter*/
        char *tokens;
    char *line_argument[1024];
        int pid;
        char **args;


        while (1)
        {
        /* Prompt*/
        write(1, "Shell$ ", 7);

        /* Getting users input*/
        characters_read = getline(&line, &len, stdin);

        if (characters_read == -1)
        {
                perror("Error reading input");
                return(-1);
        }
        else if (characters_read == 1)
        {
          continue; /* This for when the user presses enter without any command*/
        }
        else 
        {
        int idx = 0;
		printf("This is the length of the command, %ld\n", sizeof(characters_read));
		printf("This is the content of command'%d'\n", characters_read );
                /*pid_t pid;*/
                /* Process the input using string tokenization*/
                tokens = strtok(line, delimiters);
                printf("This is the token=====>>>%s\n", tokens);
        
                /* We use a null termination tokenization*/
        while(tokens != NULL)
        {
            line_argument[idx] = tokens;
            tokens = strtok(NULL, delimiters);
            idx++;
        }
        line_argument[idx] = NULL;

        idx = 0;
                while (line_argument[idx] != NULL)
                {


                                pid = fork();

                                if (pid == -1) /* Changed from 1 to -1*/
                                {
                                        perror("Fork failed");
                                        free(line);
                                        return(-1);
                                }
                                else if (pid == 0)
                                {
                                        /*pid_t pid;*/
                                        char *cmdPath = get_path(line_argument[0]);
                                        printf("line =====>>>%s\n", line);
                                        printf("This is the token now=====>>>%s\n", tokens);
                                printf("command path is %s\n", cmdPath);
                                if (cmdPath != NULL) 
                                {
                                printf("Executing command: %s\n", cmdPath);
                                /**
                                 * Here we can check if the token is a built-in command like (i.e, cd, exit)
                                 * And handle it separately  
                                 */

                                /* If it is not a built in command, we execute it*/

                                        /* This is the child process*/
                                        args = malloc(2 * sizeof(char *));/* Do not forget to free args*/
                                        if (args == NULL)
                                        {
                                                perror("Memory allocation failed");
                                                free(line);
                                                exit(EXIT_FAILURE);
                                        }

                                        args[0] = cmdPath;
                                        args[1] = NULL;

                                        /* We execute the command with execve*/
                                        execve(args[0], args, environ);

                                        /* Check if evecve fails*/
                                        perror("Execve failed");
                                        free(args); /* Free allocated memory */
                                        free(line); /* Free allocated memory */
                                        exit(1);
                                }

                        }
                        else
                        {
                                /* This is the parent process*/
            
                                int status;
                                wait(&status);/* We will wait for the child to finish*/

                                /*if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
                                {
                                        printf("\nChild process %d exited with non-zero status %d\n", 1, WEXITSTATUS(status));
                                }*/
                        }

                        idx++;

                }
        }/* loop ends end*/

        }
                free(line); /* Free allocated memory */
        return(0);
}
