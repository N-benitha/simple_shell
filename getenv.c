#include "shell.h"
/**
 * _getenv - gets the environment
 * @a: pointer to structure args
 *
 * Return: 1.
 */
int _getenv(args *a)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (1);
}
