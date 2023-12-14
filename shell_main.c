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
	data_shell DATA_SHELL_INIT = {NULL, NULL, NULL,
		0, 0, NULL, 0, NULL, NULL, 0};


	prompt(&DATA_SHELL_INIT);
	return (0);
}
