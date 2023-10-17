#include "monty.h"
int fxn(stack_t **head, char *token, unsigned int line_number)
{
	char *tkn, *dump;
	instruction_t instructions[] = {
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};
	int i = 0;

	tkn = strtok(dump, " \t\n");
	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(tkn, "push") == 0)
		{
			tkn = strtok(NULL, " \t\n");
			push(head, line_number, tkn);
		}
		else if (strcmp(tkn, instructions[i].opcode) == 0)
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
