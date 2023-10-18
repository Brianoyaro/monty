#include "monty.h"
void pall(stack_t **head, __attribute__((unused))unsigned int line_number)
{
	stack_t *curr;

	curr = *head;
	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
