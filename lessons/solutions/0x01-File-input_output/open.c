#include <fcntl.h>

int main(void)
{
    int fd;  // File descriptor

    // Open a file named "example.txt" in write mode
    // O_WRONLY: Open the file for writing only
    // O_CREAT: Create the file if it doesn't exist
    // 0666: Permissions for the created file (read/write for owner, group, others)
    fd = open("example.txt", O_WRONLY | O_CREAT, 0666);

    // Check if opening the file was successful
    if (fd == -1)
    {
        perror("Error opening file"); // Print an error message
        return 1; // Return 1 to indicate an error
    }

    // Perform operations on the opened file

    // Close the file
    close(fd);

    // Return 0 to indicate successful execution
    return 0;
}

