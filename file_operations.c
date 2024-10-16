#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>    // For open()
#include <unistd.h>   // For close(), read(), write(), lseek()
#include <string.h>   // For strlen()

int main() {
    int file;
    ssize_t bytes;
    char buffer[100];

    // Create and open a file using open() system call
    file = open("sample.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (file < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    printf("File 'sample.txt' created and opened for writing.\n");

    // Write to file using write() system call
    char *data = "This is a test for file operations using system calls.\n";
    bytes = write(file, data, strlen(data));
    if (bytes < 0) {
        perror("Error writing to file");
        close(file);
        exit(EXIT_FAILURE);
    }
    printf("Data written to file: %ld bytes.\n", bytes);

    // Close the file using close() system call
    if (close(file) < 0) {
        perror("Error closing file after writing");
        exit(EXIT_FAILURE);
    }

    // Open the file for reading
    file = open("sample.txt", O_RDONLY);
    if (file < 0) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }
    printf("File 'sample.txt' opened for reading.\n");

    // Read from the file using read() system call
    bytes = read(file, buffer, sizeof(buffer) - 1);
    if (bytes < 0) {
        perror("Error reading from file");
        close(file);
        exit(EXIT_FAILURE);
    }
    buffer[bytes] = '\0';  // Null-terminate the buffer
    printf("Data read from file:\n%s", buffer);

    // Repositioning the file offset using lseek() system call
    if (lseek(file, 0, SEEK_SET) < 0) {
        perror("Error repositioning file offset");
        close(file);
        exit(EXIT_FAILURE);
    }
    printf("File offset repositioned to the beginning of the file.\n");

    // Close the file
    if (close(file) < 0) {
        perror("Error closing file after reading");
        exit(EXIT_FAILURE);
    }

    // Delete the file using unlink() system call
    if (unlink("sample.txt") < 0) {
        perror("Error deleting file");
        exit(EXIT_FAILURE);
    }
    printf("File 'sample.txt' deleted successfully.\n");

    return 0;
}
