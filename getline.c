#include "shell.h"
/**
 * _getline - gets reads an entire line from the stream
 * @a: pointer to structure args
 *
 * Return: 0 on Success, -1 on error
 */
int _getline(args *a)
{
	char *line = NULL;
	size_t len = 0;

	if ((getline(&line, &len, stdin)) == -1)
	{
		fprintf(stderr, "Error writing to the line\n");
		return (-1);
	}
	a->line = line;
	a->tokens = NULL;
	a->len = len;
	return (0);
}
