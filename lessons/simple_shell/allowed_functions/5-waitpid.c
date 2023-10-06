#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    pid_t child_pid;
    int status;

    /* Create a child process*/
    child_pid = fork();

    if (child_pid == 0) {
        /* Child process*/
        printf("I am the child process\n");
        _exit(42); /* Terminate child with status 42*/
    } else if (child_pid > 0) {
        /* Parent process*/
        printf("I am the parent process waiting for child to terminate\n");
        pid_t terminated_pid = waitpid(child_pid, &status, 0);

        if (terminated_pid == -1) {
            perror("waitpid");
            return 1;
        }

        if (WIFEXITED(status)) {
            printf("Child process %d exited with status %d\n", terminated_pid, WEXITSTATUS(status));
        } else {
            printf("Child process %d did not exit normally\n", terminated_pid);
        }
    } else {
        perror("fork");
        return 1;
    }

    return 0;
}
