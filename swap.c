#include "monty.h"
/**
 * swap - swaps two nodes
 * @head: head node
 * @line_number: line being executed
 * Return: Nothing
 */
void swap(stack_t **head, unsigned int line_number)
{
	int temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = temp;
}
