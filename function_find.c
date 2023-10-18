#include "monty.h"
void function_find(stack_t **head, char *token, unsigned int line_no)
{
	instruction_t array[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", div},
		{"mod", mod},
		{NULL, NULL}
	};
	int i = 0, flag = 0;

	for (; array[i].opcode; i++)
	{
		if (strcmp(array[i].opcode, token) == 0)
		{
			flag += 1;
			array[i].f(head, line_no);
		}
	}
	if (flag < 1)
	{
		printf("L%d: unknown instruction %s\n", line_no, token);
		free(globe.buffer);
		exit(EXIT_FAILURE);
	}
}
