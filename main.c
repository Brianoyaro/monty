#include "monty.h"
/**
 * main - entry point of program
 * @argc: argument count
 * @argc: argument vector
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *line, *opcode;
	FILE *file;
	unsigned int line_number = 0;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line = malloc(sizeof(char) * 100000);
	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");/*correct error message*/
		exit(EXIT_FAILURE);
	}
	while(fgets(line, 100000, file) != NULL)
	{
		line_number += 1;
		opcode = strtok(line, " \t\n");
		if (opcode != NULL || opcode[0] != '#')
		{
			if (strcmp(opcode, "push") == 0)
			{
				opcode = strtok(NULL, " \t\n");
				push(&head, line_number, opcode);
			}
			else
				opcode_verifier(opcode, &head, line_number);
		}
	}
	fclose(file);
	clear(&head);
	return (0);
}
