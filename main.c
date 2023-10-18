#include <stdio.h>
#include "monty.h"
global globy;
int main(int argc, char **argv)
{
	char *opcode;
	stack_t *head;
	int line_no = 1;
	size_t n = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	globy.fd = fopen(argv[1], "r");
	if (globy.fd == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&globy.buff, &n, globy.fd))
	{
		opcode = strtok(globy.buff, "\n\t ");
		globy.push_val = strtok(NULL, "\n\t ");
		if (globy.buff != NULL)
			fxn(&head, opcode, line_no);
		line_no += 1;
	
	}
	free(globy.buff);
	fclose(globy.fd);
	/*fxn to clear stack*/
	return (0);
}
