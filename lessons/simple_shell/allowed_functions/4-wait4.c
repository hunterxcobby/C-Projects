#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t child_pid;
    int status;

    child_pid = fork(); /* Create a child process*/

    if (child_pid == -1) {
        perror("Fork failed");
        exit(1);
    }

    if (child_pid == 0) {
        /* This is the child process*/
        printf("I am the child, PID: %u\n", getpid());
        _exit(42); /* Terminate the child process with status 42*/
    } else {
        /*This is the parent process*/
        printf("I am the parent, PID: %u\n", getpid());

        /* Wait for the child process to terminate */
        pid_t terminated_pid = wait4(child_pid, &status, 0, NULL);

        if (terminated_pid == -1) {
            perror("Wait failed");
            exit(1);
        }

        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);
            printf("Child %u exited with status %d\n", terminated_pid, exit_status);
        }
    }

    return 0;
}
