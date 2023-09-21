#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>



int main (void)
{
    pid_t child_pid;
    int status;
    int newpro;
    pid_t waiting;
    const char pathname[] = "/bin/ls";
    char *const argv[] = {"ls", "-l", NULL};


    printf("Before fork\n");
    printf("1\n");
    printf("2\n");
    printf("3\n");

    child_pid = fork();
    if(child_pid == -1)
    {
        perror("fork failed!");
    }
    else if(child_pid == 0)
    {
       newpro = execve(pathname, argv, NULL);
        if(newpro == -1)
        {
            perror("Failed to open program\n");
            return(1);
        }
    }
    else 
    {
        waiting = wait(&status);
     if (waiting == -1)
     {
         perror("wait failed\n");
         return(1);
     }
    }
        printf("4\n");
        printf("5\n");
        printf("6\n");

    return (0);
}

