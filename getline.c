#include "shell.h"
/**
 * _getline - gets reads an entire line from the stream
 * @line: input
 * @len: length
 *
 * Return: 0 on Success, -1 on error
 */
int _getline(data_shell *a)
{
	char *line = NULL;
	size_t len = 0;

	if ((getline(&line, &len, stdin)) == -1)
	{
		fprintf(stderr, "Error writing to the line\n");
		return (-1);
	}
	free(a->input);
	a->input = line;
	a->tokens = NULL;
	a->len = len;
	return (0);
}
