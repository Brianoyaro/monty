#include "main.h"
void pop(stack_t **head, unsigned  int line_number)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	(*head) = temp->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(temp);
}
