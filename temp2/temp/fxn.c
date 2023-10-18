#include "monty.h"
int fxn(stack_t **head, char *token, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};
	int i = 0;

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(token, instructions[i].opcode) == 0)
			instructions[i].f(head, line_number);
	}
	/*if (instructions[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tkn);
		exit(EXIT_FAILURE);
	}*/
	/*free linked list for new commands*/
	return (0);
}
