#include "monty.h"
void f_pop(stack_t **head, unsigned int line_no)
{
	stack_t *prev;

	if (*head == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_no);
		free(globe.buffer);
		exit(EXIT_FAILURE);
	}
	prev = *head;
	if (prev == NULL)
		*head = NULL;
	if (*head != NULL)
	{
		(*head)->prev = NULL;
		*head = (*head)->next;
	}
	free(prev);
}
