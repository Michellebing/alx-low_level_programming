#include "lists.h"

/**
 * delete_nodeint_at_index - Node to be deleted in an index.
 * @head: Pointer to the first element in the list.
 * @index: The index to be deleted.
 *
 * Return: 1 for success, and -1 for fail.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
if (head == NULL || *head == NULL)
return (-1);

listint_t *current = *head;

if (index == 0)
{
*head = current->next;
free(current);
return (1);
}

for (unsigned int i = 0; current != NULL && i < index - 1; i++)
{
current = current->next;
}

if (current == NULL || current->next == NULL)
return (-1);

listint_t *next_node = current->next->next;
free(current->next);
current->next = next_node;

return (1);
}
