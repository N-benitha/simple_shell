#include "shell.h"
/**
 * prompt - prompts the user to input commands
 *
 * Return: nothing
 */
void prompt(void)
{
	data_shell a = ARGS_INIT;
	int status, i;
	blt_in b[] = {{"cd", sh_cd}, {"help", sh_help},
		{"exit", exit_shell}, {"setenv", _setsenv},
		{"unsetenv", _delsetenv}};

	while (1)
	{
		write(1, "$ ", 2);
		if (_getline(&a) == -1)
			continue;

		int found = 0;
		a.tokens = parser(&a);

		for (i = 0; i < sizeof(b) / sizeof(b[0]); i++)
		{
			if (strcmp(a.tokens[0], b[i].str) == 0)
			{
				b[i].builtin_fun(&a);
				found = 1;
				break;
			}
		}
		if (!found)
		{
			fork_exec(a.tokens);
		}
		int j;
		for (j = 0; a.tokens[j] != NULL; j++)
		{
			free(a.tokens[j]);
		}
		free(a.tokens);
	}
}
