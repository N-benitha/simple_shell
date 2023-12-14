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
	data_shell my_data = ARGS_INIT;

	prompt(&my_data);
	return (0);
}
