#include <sys/types.h>
#include <signal.h>

int main(void) 
{
    pid_t child_pid = fork();
    
    if (child_pid == -1) {
        /* Handle fork error */
    } else if (child_pid == 0) {
        /* Child process */
        printf("Child process is running\n");
        
        /* Simulate a long-running process */
        sleep(5);
        
        /* Send SIGTERM signal to terminate the process */
        kill(getpid(), SIGTERM);
    } else {
        /* Parent process */
        printf("Parent process is waiting for the child\n");
        wait(NULL);
        printf("Child process terminated\n");
    }
    
    return 0;
}
