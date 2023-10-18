#include <stdio.h>
#include "monty.h"
global globy;
int main(int argc, char **argv)
{
	stack_t *head;
	char *line;
	int line_no = 1;
	size_t n = 0;
	FILE *stream;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (globy.fd == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &n, stream) != -1)
	{
		globy.buff = strtok(line, "\n\t ");
		globy.push_val = strtok(NULL, "\n\t ");
		if (globy.buff != NULL)
			fxn(&head, globy.buff, line_no);
		line_no += 1;
	
	}
	free(globy.buff);
	fclose(globy.fd);
	/*fxn to clear stack*/
	return (0);
}
