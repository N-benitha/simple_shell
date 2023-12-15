#include "shell.h"

/**
 * main - Entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on Success, 1 on error
 */
int main(int ac, char **av)
{
	data_shell a[] = { DATA_SHELL_INIT };
	a->av = av;
	prompt(a);
	return (0);
}
