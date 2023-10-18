#include "monty.h"
void f_pall(stack_t **head, __attribute__((unused))unsigned int line_no)
{
	stack_t *curr;

	curr = *head;
	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
