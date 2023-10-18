#include "monty.h"
void f_push(stack_t **head, unsigned int line_no)
{
	stack_t *new;
	int val;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		free(globe.buffer);
		exit(EXIT_FAILURE);
	}
	if (globe.push_val == NULL)
	{
		printf("L%d: usage: push integer\n", line_no);
		free(globe.buffer);
		exit(EXIT_FAILURE);
	}
	val = atoi(globe.push_val);
	new->n = val;
	new->next = *head;
	new->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
}
