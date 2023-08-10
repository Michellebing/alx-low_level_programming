#include <stdlib.h>
#include "custom_lists.h"

/**
 * free_custom_list - frees a custom linked list.
 * @head: custom list to be freed.
 */
void free_custom_list(custom_list_t *head)
{
custom_list_t *temp;

while (head)
{
temp = head->next;
free(head->data);
free(head);
head = temp;
}
}
