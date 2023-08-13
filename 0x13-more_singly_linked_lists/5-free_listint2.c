#include "lists.h"

/**
 * free_listint2 - A free linkedin list.
 * @head: A Pointer that points to a free linkedin list.
 */
void free_listint2(listint_t **head)
{
listint_t *current;

if (head == NULL || *head == NULL)
return;

while (*head != NULL)
{
current = (*head)->next;
free(*head);
*head = current;
}

*head = NULL;
}
