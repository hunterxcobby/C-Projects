#include <unistd.h>  /* Include the necessary header file for isatty */

int main(void) 
{
    int result;

    /* Check if file descriptor 1 (stdout) is associated with a terminal */
    result = isatty(1);

    if (result == 1) {
        /* File descriptor 1 is associated with a terminal */
        /* Execute code for interactive mode */
    } else if (result == 0) {
        /* File descriptor 1 is not associated with a terminal */
        /* Execute code for non-interactive mode */
    } else {
        /* An error occurred while checking */
        /* Handle the error */
    }

    return 0;
}
