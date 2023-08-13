#include "lists.h"

/**
 * pop_listint - The nodes of a linkedin list.
 * @head: A pinter to the element in the linked list.
 *
 * Return: The element that was deleted, or 0 if the linkedin list is empty.
 */
int pop_listint(listint_t **head)
{
listint_t *temp;
int data = 0;

if (head != NULL && *head != NULL)
{
data = (*head)->n;
temp = (*head)->next;
free(*head);
*head = temp;
}

return (data);
}
