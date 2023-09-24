#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    pid_t child_pid;
    const char pathname[] = "/bin/ls";
    char *const argv[] = {"ls", "-l", NULL};

    printf("Before fork\n");
    printf("1\n");
    printf("2\n");
    printf("3\n");

    child_pid = fork();
    if (child_pid == -1) {
        perror("fork failed!");
    } else if (child_pid == 0) {
        execve(pathname, argv, NULL);
    } else {
        printf("Parent process (PID: %d) is continuing execution.\n", getpid());
        printf("4\n");
        printf("5\n");
        printf("6\n");
    }

    return 0;
}

