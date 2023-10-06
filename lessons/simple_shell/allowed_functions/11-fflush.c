#include <stdio.h>

int main(void) 
{
    /* Assume we have a file pointer 'file' that points to a file opened for writing */

    /* Write some data to the file */
    fprintf(file, "Hello, World!\n");

    /* Flush the output to ensure it's immediately written to the file */
    if (fflush(file) == 0) {
        printf("Data written successfully.\n");
    } else {
        perror("Error flushing file");
    }

    /* Close the file */
    fclose(file);

    return 0;
}
