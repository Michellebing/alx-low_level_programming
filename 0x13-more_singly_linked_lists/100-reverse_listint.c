#include "lists.h"

/**
 * reverse_listint - A linkedin list in reverse.
 * @head: A pointer to the node in the list.
 *
 * Return: A pointer to the node list.
 */
listint_t *reverse_listint(listint_t **head)
{
listint_t *prev = NULL;
listint_t *next = NULL;

while (*head)
{
next = (*head)->next;
(*head)->next = prev;
prev = *head;
*head = next;
}

*head = prev;

return (*head);
}
