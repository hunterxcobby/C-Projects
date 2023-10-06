#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {

    pid_t child_pid;
    pid_t waiting;
    int newprgm;
    int status;
    int exit_status;
    int i;
    const char pathname[] = "/bin/ls"; 

    char *const argv[] = {"ls", "-l", "/tmp", NULL};

    printf("I am the father: %u\n", getpid());

    for (i = 0; i < 5; i++) {
        child_pid = fork();
        if (child_pid == -1) {
            perror("Fork failed");
            exit(1);
        } else if(child_pid == 0) {
            printf("I am the child %d, PID: %u\n", i + 1, getpid());
            printf("I am starting my operation\n");
            newprgm = execve(pathname, argv, NULL);
            if (newprgm == -1) {
                perror("Failed to open new program!\n");
                exit(2);
            }
        } else {
            waiting = wait(&status);
            printf("I am waiting for child %d, PID: %u\n", i + 1, getpid());
            if(waiting == -1) {
                perror("Waiting failed!\n");
                exit(1);
            } else {
                if(WIFEXITED(status)) {
                    exit_status = WEXITSTATUS(status);
                    printf("Child %d process exited with status: %d\n", i + 1, exit_status);
                }
                printf("My child %d is done processing, PID: %u\n", i + 1, getpid());
            }
        }
    }

    return(0);
}

