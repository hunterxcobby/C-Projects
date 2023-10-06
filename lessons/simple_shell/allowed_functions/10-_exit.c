#include <stdio.h>
#include <unistd.h>

int main(void)
{
    /* Begin main program */

    pid_t child_pid;

    child_pid = fork(); /* Create a child process */

    if (child_pid == -1) {
        perror("Fork failed");
        _exit(1); /* Terminate the process with an error status */
    }

    if (child_pid == 0) {
        /* Code executed by the child process */
        printf("I am the child process\n");
        _exit(0); /* Terminate the child process with a success status */
    } else {
        /* Code executed by the parent process */
        printf("I am the parent process\n");
        _exit(0); /* Terminate the parent process with a success status */
    }

    /* End main program */
}
