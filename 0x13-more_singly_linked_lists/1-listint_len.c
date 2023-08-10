#include "lists.h"

/**
 * listint_len - The number of element in linked list
 * @h: Pointer to the linked list.
 *
 * Return: Number of nodes.
 */
size_t listint_len(const listint_t *h)
{
size_t num_nodes = 0;

while (h)
{
num_nodes++;
h = h->next;
}
return (0);
}
