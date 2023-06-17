#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - prints the alphabet without q and e.
 *
 * Return: Always 0
 */
int main(void)
{
	int n = 97;

	while (n <= 122)
	{
		if (n == 101 || n == 113)
		{
			n++;
			continue;
		}
		putchar(n);
		n++;
	}
	putchar('\n');
	return (0);
}
