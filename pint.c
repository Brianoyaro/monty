#include "monty.h"
void pint(stack_t **head, unsigned int line_no)
{
	if (*head == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_no);
		free(globe.buffer);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*head)->n);
}
