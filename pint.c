#include "monty.h"
/**
 * pint - prints top node value
 * @head: head node
 * @line_number: line being executed
 * Return: Nothing
 */
void pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
