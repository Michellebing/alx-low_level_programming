#include "main.h"

/**
 * get_endianness - Checks for big or small.
 * Return: Return 0 for big and 1 for small.
 */
int get_endianness(void)
{
unsigned int i = 1;
char *c = (char *) &i;

return (*c);
}
