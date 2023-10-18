#include "monty.h"
void swap(stack_t **head, unsigned int line_no)
{
	int number, temp;

	number = total_nodes(head);
	if (number < 2)
	{
		printf("L%d: can't swap, stack too short\n", line_no);
		free(globe.buffer);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = temp;

}
int total_nodes(stack_t **head)
{
	int no = 0;
	stack_t *temp;

	temp = *head;
	while (temp)
	{
		no += 1;
		temp = temp->next;
	}
	return (no);
}
