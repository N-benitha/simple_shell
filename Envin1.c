#include "shell.h"
/**
 * env_comp - This is used to compare env variables names with the name passed.
 * @invro: name of the environment variable
 * @name: name passed
 *
 * Return: 0 if are not equal. Another value if they are.
 */

int env_comp(const char *invro, const char *name)
{
	int i;

	for (i = 0; invro[i] != '='; i++)
	{
		if (invro[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * _env_get - This is used to get an environment variable
 * @name: name of the environment variable
 * @_envi: environment variable
 *
 * Return: value of the environment variable if is found.
 */

char *_env_get(const char *name, char **_envi)
{
	char *ptr_env;
	int i, mov;

	/* Initialize ptr_env value */
	ptr_env = NULL;
	mov = 0;
	/* Compare all environment variables */
	/* envi is declared in the header file */
	for (i = 0; _envi[i]; i++)
	{
		/* If name and environment are equal */
		mov = env_comp(_envi[i], name);
		if (mov)
		{
			ptr_env = _envi[i];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * _env - This print the evinronment variables
 *
 * @dat: data relevant.
 * Return: 1.
 */
int _env(data_shell *dat)
{
	int i, j;

	for (i = 0; dat->_envi[i]; i++)
	{

		for (j = 0; dat->_envi[i][j]; j++)
			;

		write(STDOUT_FILENO, dat->_envi[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	dat->status = 0;

	return (1);
}
