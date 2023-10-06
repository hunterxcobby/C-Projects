#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t child_pid;
    int status;
    struct rusage usage;

    child_pid = fork();

    if (child_pid == -1) 
    {
        perror("Fork failed");
        exit(1);
    }
    else if (child_pid == 0) 
    {
        /* This is the child process*/
        printf("I am the child, PID: %u\n", getpid());
        exit(42); /* Exit with status 42 */
    } 
    else 
    {
        /* This is the parent process*/
        pid_t waiting = wait3(&status, 0, &usage);

        if (waiting == -1) 
        {
            perror("Waiting failed");
            exit(1);
        }
        else 
        {
            if (WIFEXITED(status)) {
                int exit_status = WEXITSTATUS(status);
                printf("Child process exited with status: %d\n", exit_status);
            }

            // Print resource usage information
            printf("User CPU time used: %ld.%06ld seconds\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
            printf("System CPU time used: %ld.%06ld seconds\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
        }
    }

    return 0;
}
