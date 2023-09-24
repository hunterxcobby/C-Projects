#include <stdio.h>
#include <unistd.h>


int main (void)
{
    pid_t my_pid;
    pid_t pid;
    
    my_pid = getppid();
    printf("This is programs parent's id:%u\n", my_pid);
    
    printf("Before fork\n");
    printf("1\n");
    printf("2\n");
    printf("3\n");
    
    my_pid = getpid();
    printf("This is programs id:%u\n", my_pid);
    printf("after fork!\n");
    
    pid = fork();
    if(pid == -1)
    {
        perror("fork failed!");
    }
    
    printf("4\n");
    printf("5\n");
    printf("6\n");

    my_pid = getpid();
    
    if (pid == 0)
    {
        printf("This is parent's pid:%u\n", getppid());
        printf("This is child's pid:%u\n", my_pid);
    }
    else if (pid > 0)
    {
        printf("This is parent's pid:%u\n", my_pid);
    }

    return (0);
}


