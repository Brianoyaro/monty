#include "monty.h"
/**
 * opcode_verifier - verifies opcode
 * @opcode: first parameter per line
 * @head: head node
 * @line_count: line being executed
 * Return: Nothing
 */
void opcode_verifier(char *opcode, stack_t **head, unsigned int line_count)
{
	instruction_t cmd[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"mul", mul},
		{"div", div_op},
		{"mod", mod},
		{"sub", sub},
		{NULL, NULL}
	};
	int flag = 0, i = 0;

	for(; cmd[i].opcode; i++)
	{
		if (strcmp(cmd[i].opcode, opcode) == 0)
		{
			flag += 1;
			cmd[i].f(head, line_count);
		}
	}
	if (flag == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_count, opcode);
		exit(EXIT_FAILURE);
	}
}
