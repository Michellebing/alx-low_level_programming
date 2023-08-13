#include "lists.h"

/**
 * get_nodeint_at_index - Returns the node to  a linked list.
 * @head: The first node in the linked list.
 * @index: Node index.
 *
 * Return: Pointer to the index, or NULL if not found.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int i = 0;
listint_t *current = head;

while (current != NULL && i < index)
{
current = current->next;
i++;
}

return (current ? current : NULL);
}
