#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - Append a new node at the end of a linked list.
 * @head: A double pointer to the list.
 * @str: store string in new node.
 *
 * Returns: a pointer to the new node, or NULL if allocation fails
 */
custom_list_t *add_node_end(list_t **head, const char *str)
{
custom_list_t *new_node;
custom_list_t *temp = *head;
unsigned int length = 0;

while (str[length])
length++;

new_node = (custom_list_t *)malloc(sizeof(custom_list_t));
if (!new_node)
return (NULL);

new_node->data = strdup(str);
new_node->length = length;
new_node->next = NULL;

if (*head == NULL)
{
*head = new_node;
return (new_node);
}

while (temp->next)
temp = temp->next;

temp->next = new_node;

return (new_node);
}
