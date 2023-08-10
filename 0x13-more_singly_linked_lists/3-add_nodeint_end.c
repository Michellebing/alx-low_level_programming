#include "lists.h"

/**
 * add_nodeint - Ad node to linked list
 * @head: Pointer to the node in list
 * @n: New node
 *
 * Return: Pointer to the new node, or NULL if fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *new_node;

new_node = malloc(sizeof(listint_t));
if (!new_node)
return (NULL);

new_node->n = n;
new_node->next = *head;
*head = new_node;

return (new);
}
