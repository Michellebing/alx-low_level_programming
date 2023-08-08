#include <stdio.h>
#include <stdlib.h>


char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - For a buffer of 1024 bytes.
 *
 * @file: The name of the file for which the buffer is allocated.
 * Return: A pointer to the allocated buffer.
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

return (buffer);
}

/**
 * close_file -  Closing the file descriptor.
 *
 * @fd: The file descriptor to be closed.
 * Return: Exits with code 100 if closing the file descriptor fails.
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
 * main - Copies the contents of one file to another file.
 *
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: Return 0 on success, exits with codes 98 failure.
 *
 * Description: Validates the argument count, copies data to destination
 * handles various error related to file operations and memory allocation.
 */
int main(int argc, char *argv[])
{
int from, to, read_result, write_result;
char *buffer;

if (argc != 3)
}
dprintf(STDERR_FILENO, "Usage: cp source_file destination_file\n");
exit(97);
}

buffer = create_buffer(argv[2]);

from = open(argv[1], O_RDONLY);

read_result = read(from, buffer, 1024);

to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
do {
if (from == -1 || read_result == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from %s\n", argv[1]);
free(buffer);
exit(98);
}

write_result = write(to, buffer, read_result);

if (to == -1 || write_result == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
free(buffer);
exit(99);
}

read_result = read(from, buffer, 1024);
to = open(argv[2], O_WRONLY | O_APPEND);

} while (read_result > 0);

free(buffer);
close_file(from);
close_file(to);

return (0);
}
