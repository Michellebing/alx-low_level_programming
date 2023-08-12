#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * error_exit - print error message and exit with specified code.
 * @code: exit code.
 * @format: error message format.
 * Return: no return.
 */
void error_exit(int code, const char *format, ...)
{
va_list args;
va_start(args, format);
vdprintf(STDERR_FILENO, format, args);
va_end(args);
exit(code);
}

/**
 * main - entry point.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
int file_from, file_to;
ssize_t nchars, nwr;
char buf[1024];

if (argc != 3)
error_exit(97, "Usage: %s file_from file_to\n", argv[0]);

file_from = open(argv[1], O_RDONLY);
if (file_from == -1)
error_exit(98, "Error: Can't read from file %s\n", argv[1]);

file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (file_to == -1)
{
close(file_from);
error_exit(99, "Error: Can't write to %s\n", argv[2]);
}

{
do

nchars = read(file_from, buf, sizeof(buf));
if (nchars == -1)
{
close(file_from);
close(file_to);
error_exit(98, "Error: Can't read from file %s\n", argv[1]);
}

nwr = write(file_to, buf, nchars);
if (nwr == -1)
{
close(file_from);
close(file_to);
error_exit(99, "Error: Can't write to %s\n", argv[2]);
}
} while (nchars > 0);

close(file_from);
close(file_to);
return (0);
}
