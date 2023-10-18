#include "main.h"
void clear(stack_t **head)
{
	stack_t *curr;

	curr = *head;
	while (curr->next != NULL)
	{
		curr = curr->next;
		free(curr->prev);
	}
	free(curr);
}
