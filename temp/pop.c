#include "monty.h"
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	/*int  value;*/

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = temp->next;
	/*value = temp->n;*/
	free(temp);
	/*return (value);*/
}
