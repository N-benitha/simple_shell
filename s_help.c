#include "shell.h"
/**
 * sh_help - help command
 * @a:  pointer to structure data_shell (__attribute__((unused)) is added)
 *
 * Return: 1.
 */
int sh_help(data_shell * __attribute__((unused)) a)
{
	printf("Use man command to get information about other commands.\n");
	printf("more information to be added later.\n");
	return (1);
}
