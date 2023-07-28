#include <stdio.h>
#include <"lists.h">
/**
 * print_lists - check all the element of a linked list
 * @h: list the number of nodes
 */
size_t print_len(const list_t *h)
{
	int nodes = 0;

	while (h)
	{
		if (h->str)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%d] %s\n", h->len, h->str);
		}
		nodes++;
	}
	return (nodes);
}
