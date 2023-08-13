#include "lists.h"

/**
 * add_nodeint - New nodes
 * @head: A pointer to the new nodes.
 * @n: Add data to new nodes.
 *
 * Return: Pointer to new node, NULL if fails.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *new_node;

new_node = malloc(sizeof(listint_t));
if (!new_node)
{
return (NULL);
}

new_node->n = n;
new_node->next = *head;
*head = new_node;

return (new_node);
}
