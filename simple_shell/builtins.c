#include "main.h"

/* In this file, we check if command is a builtin*/

void builtin_cd(char *arg)/* Remember our function returns void*/
{   
    /* If the user does not pass any argument to it, we take them home*/
    if (arg == NULL) 
    {
        char *home = getenv("HOME");
        /* If the person does not have the HOME env set*/
        if (home == NULL) 
        {
            fprintf(stderr, "cd: HOME environment variable not set\n");
        }
        else
        {
            /* This will take the user home*/
            if (chdir(home) != 0) 
            {
                perror("Could not change directory");
            }
        } 
    }
    else 
    {
        /* We change directory*/
        if (chdir(arg) != 0) 
        {
            perror("Could not change directory");
        }
    }
}


/* THis is for exiting*/
void builtin_exit() 
{
    /* Remember clear also works*/
    printf("Exiting the shell...\n");
    /* Before it exists, it can sleep*/
    sleep(2);
    exit(0);/* To indicate success*/
}