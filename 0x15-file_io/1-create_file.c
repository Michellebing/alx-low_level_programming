#include "main.h"

/**
 * Create_file - Create a file and write content to be in it.
 *
 * @param filename The name of the file to be created.
 * @param text_content The text content to be written to the file.
 * @return Returns 1 on success, or -1 if an error occurs.
 */

int create_file(const char *filename, char *text_content);
{
int fd, write_result, content_length = 0;


if (filename == NULL)
return (-1);


if (text_content != NULL)
{
for (content_length = 0; text_content[content_length];)
content_length++;
}


fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);

write_result = write(fd, text_content, content_length);

if (fd == -1 || write_result == -1)
return (-1);

close(fd);
return (1);
}
