#include "monty.h"
/**
 * push - add a new noder
 * @head: head node
 * @line_number: line being executed
 * @value: second line parameter
 * Return: Nothing
 */
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
	if (value == NULL || (number_(value) == 5))/*check if its a number because atoi returns 0 if not*/
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
/**
 * number_ - checks if a string is made of numbers
 * @s: string to check
 * Return: 5 if string has any non-number character
 * else 10 if made of numbers entirely
 */
int number_(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			i += 1;
			continue;
		}
		else
			return (5);
	}
	return (10);
}
