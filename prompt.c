#include "shell.h"
/**
 * prompt - prompts the user to input commands
 *
 * Return: nothing
 */
void prompt(data_shell *a)
{
	int status, i;
	blt_in b[] = {
		{"cd", sh_cd},
		{"help", sh_help},
		{"exit", exit_shell},
		{"setenv", set_env},
		{"unsetenv", _delsetenv}, 
		{NULL, NULL}
	};

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		if (_getline(a) == -1)
		{
			if (a->input != NULL)
			{
				free(a->input);
				a->input = NULL;
			}
			continue;
		}

		int found = 0;
		a->tokens = parser(a);
		if (a->tokens[0] == 0)
		{
			free(a->input);
			free(a->tokens);
			continue;
		}

		for (i = 0; i < sizeof(b) / sizeof(b[0]); i++)
		{
			if (strcmp(a->tokens[0], b[i].str) == 0)
			{
				b[i].builtin_fun(a);
				found = 1;
				break;
			}
		}
		if (!found)
		{
			fork_exec(a->tokens, a);
		}
		int j;
		for (j = 0; a->tokens[j] != NULL; j++)
		{
			free(a->tokens[j]);
		}
		free(a->tokens);
	}
}
