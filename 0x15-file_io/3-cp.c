#include <stdio.h>
#include <stdlib.h>

// Function declarations
char *create_buffer(char *file);
void close_file(int fd);

/**
 * Allocates memory for a buffer of 1024 bytes.
 *
 * @param file The name of the file for which the buffer is allocated.
 * @return A pointer to the newly-allocated buffer, or exits with code 99 if memory allocation fails.
 */
char *create_buffer(char *file)
{
    char *buffer;

    buffer = malloc(sizeof(char) * 1024);

    if (buffer == NULL)
    {
        dprintf(STDERR_FILENO,
            "Error: Can't allocate memory for %s\n", file);
        exit(99);
    }

    return buffer;
}

/**
 * Closes a file descriptor.
 *
 * @param fd The file descriptor to be closed.
 * @return None. Exits with code 100 if closing the file descriptor fails.
 */
void close_file(int fd)
{
    int close_result;

    close_result = close(fd);

    if (close_result == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
        exit(100);
    }
}

/**
 * Copies the contents of one file to another file.
 *
 * @param argc The number of arguments supplied to the program.
 * @param argv An array of pointers to the arguments.
 * @return 0 on success, exits with codes 97, 98, 99, or 100 on failure.
 *
 * Description: Validates the argument count, copies data from source to destination file,
 * and handles various error scenarios related to file operations and memory allocation.
 */
int main(int argc, char *argv[])
{
    int from, to, read_result, write_result;
    char *buffer;

    // Check for correct usage
    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp source_file destination_file\n");
        exit(97);
    }

    // Allocate memory for buffer
    buffer = create_buffer(argv[2]);

    // Open source file for reading
    from = open(argv[1], O_RDONLY);

    // Read initial content into the buffer
    read_result = read(from, buffer, 1024);

    // Open destination file for writing (creating if it doesn't exist, truncating if it does)
    to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

    // Copy loop
    do {
        if (from == -1 || read_result == -1)
        {
            dprintf(STDERR_FILENO, "Error: Can't read from %s\n", argv[1]);
            free(buffer);
            exit(98);
        }

        // Write content from buffer to destination file
        write_result = write(to, buffer, read_result);

        if (to == -1 || write_result == -1)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
            free(buffer);
            exit(99);
        }

        // Read more content into the buffer
        read_result = read(from, buffer, 1024);
        to = open(argv[2], O_WRONLY | O_APPEND);

    } while (read_result > 0);

    // Clean up and close files
    free(buffer);
    close_file(from);
    close_file(to);

    return 0;
}
This description breaks down
