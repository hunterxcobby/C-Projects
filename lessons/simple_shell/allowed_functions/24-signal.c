#include <stdio.h>
#include <signal.h>

void signal_handler(int signum) {
    printf("Received signal %d\n", signum);
}

int main(void)
{
    void (*previous_handler)(int);

    /* Set a new signal handler for SIGINT (Ctrl+C) */
    previous_handler = signal(SIGINT, signal_handler);

    /* Do some work here */

    /* Restore the previous signal handler for SIGINT */
    signal(SIGINT, previous_handler);

    return 0;
}
