#include "monty.h"
/**
 * pall - prints data part of list
 * @head: head node
 * @line_number: line being executed
 * Return: Nothing
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *curr;

	(void)line_number;
	curr = *head;
	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
