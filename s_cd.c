#include "shell.h"
/**
 * sh_cd - change directory
 * @a: pointer to structure args
 *
 * Return: 1.
 */
int sh_cd(args *a)
{
	if (a->len < 2 || a->tokens[1] == NULL)
	{
		fprintf(stderr, "hsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(a->tokens[1]) != 0)
			perror("hsh");
	}
	return (1);
}
