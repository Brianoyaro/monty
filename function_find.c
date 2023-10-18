#include "monty.h"
void f_function_find(stack_t **head, char *token, unsigned int line_no)
{
	instruction_t array[] = {
		{"push", f_push},
		{"pop", f_pop},
		{"pall", f_pall},
		{"pint", f_pint},
		{"nop", f_nop},
		{"swap", f_swap},
		{"add", f_add},
		{"sub", f_sub},
		{"div", f_div},
		{"mod", f_mod},
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
