#include "monty.h"
global globe;
int main(int argc, char **argv)
{
	char *opcode;
	stack_t *head = NULL;
	unsigned int line_no = 1;
	size_t n = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	globe.stream = fopen(argv[1], "r");
	if (globe.stream == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&globe.buffer, &n, globe.stream) != -1)
	{
		opcode = strtok(globe.buffer, " \t\n");
		if (strcmp(opcode, "push") == 0)
			globe.push_val = strtok(NULL, " \t\n");
		function_find(&head, opcode, line_no);
		line_no += 1;
	}
	free(globe.buffer);

	fclose(globe.stream);
	/*free the list*/
	return (0);
}
