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
			/* To check when the user enters ctrl + D*/
			if (feof(stdin)) 
			{
        		/*User pressed Ctrl+D (EOF)*/
        		printf("\nExiting shell...\n");
				sleep(2);
        		free(line);
        		exit(0);
			}
			else
			{
				perror("Error reading input");
				return(-1);
			}
		}
		else if (characters_read == 1)
		{
			continue; /* This for when the user presses enter without any command*/
		}
		else 
		{
			int idx = 0;

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


			/**
			 * Here we can check if the token is a built-in command like (i.e, cd, exit)
			 * And handle it separately  
			 */
			if(strcmp(line_argument[0], "cd") == 0)
			{
				/* We call for our function*/
				builtin_cd(line_argument[1]);
			}
			/* If the user enters exit.*/
			else if(strcmp(line_argument[0], "exit") == 0) 
			{
				/* We call our exit function*/
        		builtin_exit();
			}
			else
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
					
					/* If it is not a built in command, we execute it*/

					/* This is the child process*/
					args = malloc(2 * sizeof(char *));/* Do not forget to free args*/
					if (args == NULL)
					{
						perror("Memory allocation failed");
						free(line);
						exit(EXIT_FAILURE);
					}



					/* We execute the command with execve*/
					execve(cmdPath, line_argument, environ);

					/* Check if evecve fails*/
					err_msg(line_argument[0]);
					free(args);
					free(line); /* Free allocated memory */
					exit(1);
				}

			}
			else
			{
				/* This is the parent process*/

				int status;
				waitpid(pid, &status, 0);/* We will wait for the child to finish*/

				if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
				{
					printf("\nChild process %d exited with non-zero status %d\n", pid, WEXITSTATUS(status));
				}
			}




		}/* loop ends end*/
		}/* This is for builtin*/
	}
	free(line); /* Free allocated memory */
	return(0);
}
