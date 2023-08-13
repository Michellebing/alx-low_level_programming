#include "lists.h"

/**
 * sum_listint - Sum of all the data in a the list.
 * @head: Pointer to the first node in the linked list.
 *
 * Return: The resulting sum of data.
 */
int sum_listint(listint_t *head)
{
int sum = 0;
listint_t *current = head;

while (current != NULL)
{
sum += current->n;
current = current->next;
}

return (sum);
}
