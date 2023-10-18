#include "monty.h"
/**
 * add - add first two nodes
 * @head: head node
 * @line_number: line being executed
 * Return: Nothing
 */
void add(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n += (*head)->n;
	temp = *head;
	*head = (*head)->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(temp);
}
