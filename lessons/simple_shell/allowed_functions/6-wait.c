#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    pid_t child_pid;

    child_pid = fork(); /* Create a child process*/

    if (child_pid == -1) {
        perror("Fork failed");
        return 1;
    }

    if (child_pid == 0) {
        /* This is the child process */
        printf("Child process executing\n");
        _exit(0); /* Terminate child process*/
    } else {
        /* This is the parent process*/
        int status;
        pid_t terminated_pid;

        terminated_pid = wait(&status); /* Wait for child process to terminate*/

        if (terminated_pid == -1) {
            perror("Wait failed");
            return 1;
        }

        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);
            printf("Child process %d terminated with status %d\n", terminated_pid, exit_status);
        }
    }

    return 0;
}
