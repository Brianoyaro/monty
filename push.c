#include "main.h"
void push(stack_t **head, unsigned int line_number, char *value)
{
	stack_t *new;
	int val;

	(void)line_number;/*fix this latter*/
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (value == NULL)
	{
		fprintf(stderr, "Error: USAGE push number\n");/*fix this error message*/
		exit(EXIT_FAILURE);
	}
	val = atoi(value);
	new->n = val;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
}
