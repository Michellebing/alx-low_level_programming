#include "main.h"

/**
 * get_bit - Returns the value of a bit index in a decimal number.
 * @n: The number to be seen.
 * @index: The bit index.
 *
 * Return: Value of the bit at the given index, or -1 if index is out of range.
 */
int get_bit(unsigned long int n, unsigned int index)
{
int bit_val;

if (index > 63)
return (-1);

bit_val = (n >> index) & 1;

return (bit_val);
}
