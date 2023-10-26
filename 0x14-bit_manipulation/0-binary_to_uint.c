#include "main.h"

/**
 * binary_to_uint - Converts a binary number.
 * @b: A binary number.
 *
 * Return: The converted unsigned int value, or 0 if an error occurs.
 */
unsigned int binary_to_uint(const char *b)
{
int i;
unsigned int dec_val = 0;

if (!b)
return (0);

for (i = 0; b[i]; i++)
{
if (b[i] < '0' || b[i] > '1')
return (0);

dec_val = 2 * dec_val + (b[i] - '0');
}

return (dec_val);
}
