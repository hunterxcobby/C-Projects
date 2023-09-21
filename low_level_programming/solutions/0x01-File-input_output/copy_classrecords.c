#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * main - Copies data from one file to another.
 *
 * Return: Always 0 on success, 1 on error.
 */
int main(void)
{
	int cr, sr; // File descriptors for class_records.txt and school_records.txt
	char BUFFER[200]; // Buffer to read and write data
	ssize_t data_read, data_written; // Number of bytes read and written

	// Open class_records.txt in read mode
	cr = open("class_records.txt", O_RDONLY);
	if (cr == -1) {
		perror("Could not open class_records.txt");
		return 1;
	}

	// Open school_records.txt in write mode or create if it doesn't exist
	sr = open("school_records.txt", O_WRONLY | O_CREAT, 0666);
	if (sr == -1) {
		perror("Could not open school_records.txt");
		return 1;
	}

	// Loop to read and write data in chunks
	while ((data_read = read(cr, BUFFER, sizeof(BUFFER))) > 0) {
		data_written = write(sr, BUFFER, data_read);
		if (data_written == -1) {
			perror("Could not write data");
			return 1;
		}
	}

	// Check for read error after the loop
	if (data_read == -1) {
		perror("Could not read data");
		return 1;
	}

	// Close both file descriptors
	close(sr);
	close(cr);

	return 0; // Return 0 to indicate successful execution
}

