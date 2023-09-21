#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <dirent.h>
#include <signal.h>

/* function prototypes */
int our_strcmp(const char *string1, const char *string2);
void signal_handler(int signal);

/**
 * main - building my own shell
 *
 * desc: program does the following
 * 1. prompts a user to enter a line (command)
 * XX 2. command is passed into the program through main () XX
 * 3. tokenizes the command into smaller strings
 * 4. if first token (program name) contains '/' means it is a path
 * 5. if fist token (program name) does not contain '/' means it is a raw program name
 *
 * 6. if path () {execve(path, arguments, NULL)}
 * 7. if (!path) {search through all directories in $PATH environment variable to find a program,
 * 8. that has the same name as the program using strcmp. if strcmp == 0, execve(strcat(directory, line), arguments, NULL);
 * 4. smaller strings will represent the arguments parameter of execve function
 * 5. forks program to create a new process (child)
 * 6. uses execve function to execute the command in the child process
 * 7. parent process waits for another command to be inputed by user
 *
 * Return: always 0
 */

int main (int ac, char **av)
{
        /* for prompting user */
        char *prompt = "$ ";
        ssize_t characters_read = 0;
        /* for testing */
        ssize_t prompt_bytes_written = 0;
        /* for getline() */
        char *line = NULL;
        size_t len = 0;
        size_t i = 0;
	/* for freeing dir*/
	size_t free_dir_i = 0;
        /* for strtok() */
        const char *delimiters = NULL;
        char *command_token = NULL;
        /* for execve */
        char **command = NULL;
        /* for allocating space for command array */
        size_t max_command = 0;
        /* for fork */
        int child_pid = 0;
        int status = 0;
        /* for getenv() */
        char *path_env_var = NULL;
        /* for checking if string is path */
        int slash_i = 0;
        char *path = NULL;
        /* for allocating space for command array */
        size_t max_directories = 0;
        /* for tokenized path env variable to directories */
        char **directories = NULL;
        char *directories_token = NULL;
        size_t directories_i = 0;
        /* for opening directories in PATH */
        DIR *directory_stream = NULL;
        int searching_i = 0;
        /* for reading entries in directory */
        struct dirent *entry = NULL;
        /* for concatenating directory with program name */
        char *concat_path = NULL;
        /* for if program is found in an entry */
        int found = 0;

        /* ac will not be used */
        (void)ac;

        /* handling signals */
        signal(SIGINT, signal_handler);

        while (1)
        {
                line = NULL;
                delimiters = " ";
                path = NULL;

                /** 1. prompts a user to enter a line (command) */
                prompt_bytes_written = write(1, prompt, strlen(prompt));
                if (prompt_bytes_written == -1)
                {
                        perror ("write");
                        return (1);
                }

                /** get command from user */
                characters_read = getline(&line, &len, stdin);
                if (characters_read == -1)
                {
                        perror ("getline");
                        return (1);
                }

                /* if command has a new line as last character */
                if (line[characters_read - 1] == '\n')
                        line[characters_read - 1] = '\0';

                /* if command is just a new line */
                if (line[0] == '\0')
                        continue;

                /** 3. tokenizes the command into smaller strings */
                /** 4. smaller strings will represent the arguments parameter of execve function */
                command_token = strtok (line, delimiters);
                if (command_token == NULL)
                {
                        perror("strtok");
                        return (1);
                }

                /* allocating space for command array */
                max_command = 10;
                command = malloc (sizeof(char *) * max_command);
                i = 0;
                while (command_token != NULL)
                {
                        if (i >= max_command)
                        {
                                max_command *= 2;
                                command = realloc (command, sizeof(char *) * max_command);
                                if (command == NULL)
                                {
                                        perror("realloc");
                                        exit (1);
                                }
                        }
                        command[i] = strdup(command_token);
                        command_token = strtok(NULL, delimiters);
                        i++;
                }
                command[i] = NULL;


                /* check if program name is a path or just a file name */
                slash_i = 0;
                while (line[slash_i] != '\0')
                {
                        if (line[slash_i] == '/')
                        {
                                path = line;
                                break;
                        }
                        slash_i++;
                }

                /* if program name is not a path */
                if (path == NULL)
                {
                        /* taking environment variable PATH */
                        char *PATH = getenv("PATH");
                        path_env_var = strdup(PATH);

                        /* tokenize PATH into array directories*/
                        directories_token = strtok(path_env_var, ":");
                        if (directories_token == NULL)
                        {
                                perror("strtok");
                                exit(1);
                        }

                        /* allcoating space for directories array */
                        max_directories = 100;
                        directories = malloc(sizeof(char *) * max_directories);
                        directories_i = 0;
                      while (directories_token != NULL)
                        {
                                if (directories_i >= max_directories)
                                {
                                        max_directories *= 2;
                                        directories = realloc (directories, sizeof(char *) * max_directories);
                                        if (directories == NULL)
                                        {
                                                perror("realloc");
                                                exit(1);
                                        }
                                }
                                directories[directories_i] = strdup(directories_token);
                                directories_token = strtok(NULL, ":");
                                directories_i++;
                        }

			/*directories = NULL;*/
			
                        /* opening all directories to look for line(e.g "ls") */
                        searching_i = 0;
                        while (directories[searching_i] != NULL)
                        {
                                directory_stream = opendir(directories[searching_i]);

                                if (directory_stream == NULL)
                                {
                                        searching_i++;
                                        continue;
                                }

                                found = 0;
                                entry = readdir(directory_stream);
                                while (entry != NULL)
                                {
                                        if (our_strcmp(line, entry->d_name) == 0)
                                        {
                                                found = 1;
                                                break;
                                        }

                                        entry = readdir(directory_stream);
                                }

				closedir (directory_stream);

                                if (found == 1)
				{
                                        break;
				}
                                searching_i++;
                        }
                        free(directories);
			path_env_var = NULL;
                } /* CHECK FOR WHEN ALL SEARCH IS DONE BUT PROGRAM NOT FOUND */

                /** 5. forks program to create a new process (child) */
                child_pid = fork();
                if (child_pid == -1)
                {
                        perror("fork");
                        return (1);
                }
                else if (child_pid == 0)
                {
                        /* this is the child */
                        /** 6. uses execve function to execute the command in the child process */
                        if (path != NULL)
                        {
                                execve(path, command, NULL);
                                printf("%s: No such file or directory\n", av[0]);
                                return (1);
                        }
                        else
                        {
                                concat_path = malloc (strlen(directories[searching_i]) + strlen(line) + 2);
                                if (concat_path == NULL)
                                {
                                        perror("malloc");
                                        return (1);
                                }
                                strcpy(concat_path, directories[searching_i]);
                                strcat(concat_path, "/");
                                strcat(concat_path, line);
                                execve(concat_path, command, NULL);
                                perror("execve");
                                free(concat_path);
                                free(command);
                                return (1);
                        }

                }

                /* continuing what happens in the parent (this program) */
                wait (&status);
		
		/* freeing directories_i*/
		for (free_dir_i = 0; directories[free_dir_i]; free_dir_i++)
                {
                       free(directories[free_dir_i]);
                }

		/* freeing command[i]*/
		for (i = 0; command[i] != NULL; i++)
 		{
    			free(command[i]);
		}

                /* reset path_env_var variable */
                /*path_env_var = NULL;*/
		free(path_env_var);
                free (concat_path);
                free (command);
                free(line);
		/*closedir(directory_stream);*/
        }


        return (0);
}


int our_strcmp(const char *string1, const char *string2)
{
        int i = 0;

        while (string1[i] != '\0')
        {
                if (string1[i] != string2[i])
                {
                        return (string1[i] -  string2[i]);
                }
                i = i + 1;
        }

        while (string2[i] != '\0')
        {
                if (string2[i] != string1[i])
                {
                        return (string1[i] -  string2[i]);
                }
                i = i + 1;
        }

        return (string1[i] - string2[i]);
}

void signal_handler(int signal)
{
        (void)signal;
        printf("\n$ ");
        fflush(stdout);
}
