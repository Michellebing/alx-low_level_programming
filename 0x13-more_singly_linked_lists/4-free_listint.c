#include "lists.h"

/**
 * free_listint - A linkedin list to be freed.
 * @head: Pointer to the head of the list to be freed.
 */
void free_listint(listint_t *head)
{
listint_t *current = head;
listint_t *next;

while (current != NULL)
{
next = current->next;
free(current);
current = next;
}
}
