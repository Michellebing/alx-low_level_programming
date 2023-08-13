#include "lists.h"

/**
 * listint_len - Returns number of a linkedin list.
 * @head: A pointer to the head list.
 *
 * Return: The number of nodes in the linked list.
 */
size_t listint_len(const listint_t *head)
{
size_t count = 0;
const listint_t *current = head;

while (current != NULL)
{
count++;
current = current->next;
}

return (count);
}
