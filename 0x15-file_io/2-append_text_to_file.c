#include "main.h"

/**
 * Create_text_to_file - write a text in the file.
 * @filename: The name of the file to append to
 * @text_content: The text to add at the end of the file.
 *
 * Return: Return 1 on success, or -1 on failure
 *
 */
int append_text_to_file(const char *filename, char *text_content)
{
int file_descriptor, write_result, content_length = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
for (content_length = 0; text_content[content_length];)
content_length++;
}

file_descriptor = open(filename, O_WRONLY | O_APPEND);
write_result = write(file_descriptor, text_content, content_length);

if (file_descriptor == -1 || write_result == -1)
return (-1);

close(file_descriptor);

return (1);
}
