#include "main.h"

/**
 * set_bit - Sets a bit at a specified index to 1.
 * @n: Pointer to a number.
 * @index: The index of the bit.
 *
 * Return: 1 for success, -1 for failure (if index is out of range).
 */
int set_bit(unsigned long int *n, unsigned int index)
{
if (index > 63)
return (-1);

*n |= (1UL << index);
return (1);
}
