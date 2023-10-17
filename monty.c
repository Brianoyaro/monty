#include "monty.h"
int main(int argc, char **argv)
{
	int fd1;
	unsigned int line_number = 0;
	ssize_t n = 0;
	char *token, *buff;
	stack_t *head = NULL;

	if (argc != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
	{
		write(STDERR_FILENO, "Error: Can't open file", 22);
		write(STDERR_FILENO, argv[1], strlen(argv[1]));
		write(STDERR_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
	buff = malloc(1024);
	if (!buff)
	{
		perror("MAlloc");
		exit(EXIT_FAILURE);
	}
	n = read(fd1, buff, 1024);
	if (n == -1)
	{
		free(buff);
		close(fd1);
		exit(EXIT_FAILURE);
	}
	token = strtok(buff, "\n");
	while (token)
	{
		line_number += 1;
		if (token != NULL && token[0] != '#')
		{
			fxn(&head, token, line_number);/*the fxn will free the linked list*/
			token = strtok(NULL, "\n");
			printf("token-> %s\n", token);
			continue;
		}
		token = strtok(NULL, "\n");
		printf("vampire token->%s\n", token);

	}
	close(fd1);
	return (0);
}
