#include <unistd.h>

/**
 * main - Writes data to a file.
 *
 * Return: 0 on success, 1 on error.
 */
int main(void)
{
	int fd; // File descriptor
	char buffer[] = "Hello, world!"; // Data to write
	ssize_t bytes_written; // Number of bytes written

	// Open the file

	// Write data from the buffer to the file
	// write(fd, buffer, sizeof(buffer)) writes sizeof(buffer) bytes from buffer to the file
	bytes_written = write(fd, buffer, sizeof(buffer));

	// Check if writing to the file was successful
	if (bytes_written == -1)
	{
		perror("Error writing to file"); // Print an error message
		return 1; // Return 1 to indicate an error
	}

	// Close the file

	// Return 0 to indicate successful execution
	return 0;
}

