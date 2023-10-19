#include "monty.h"
/**
 * rot1 - makes first node last node
 * @head: head node
 * @line_number: line being executed
 * Return: Nothing
 */
void rot1(stack_t **head, unsigned int line_number)
{
	stack_t *curr, *new;

	if (*head != NULL)
	{
		new = malloc(sizeof(stack_t));
		if (new == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		new->n = (*head)->n;
		curr = *head;
		while (curr->next)
			curr = curr->next;
		new->next = curr->next;
		new->prev = curr;
		curr->next = new;
		pop(head, line_number);
	}
}
