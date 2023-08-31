#include "main.h"

/**
 * clear_bit - The value of the given bit
 * @n: A pointer to the number.
 * @index: Index of the bit.
 *
 * Return: 1 for success, -1 for failure (if index is out of range).
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
if (index > 63)
return (-1);

*n &= ~(1UL << index);
return (1);
}
