#include "monty.h"
void add(stack_t **head, unsigned int line_no)
{
	int number;
	stack_t *temp = *head;

	number = total_nodes(head);
	if (number < 2)
	{
		printf("L%d: can't add, stack too short\n", line_no);
		free(globe.buffer);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n += (*head)->n;
	*head = temp->next;
	if (*head != NULL)
		(*head)->prev = NULL:
	free(temp);
}
