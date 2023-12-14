#include "shell.h"

/**
 * error_env - this is used for
 * the error message for
 * env in get_env.
 * @dat: data relevant (counter, arguments)
 * Return: error message.
 */

char *error_env(data_shell *dat)
{
	int length;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = aux_itoa(dat->counter);
	msg = ": Unable to add/remove from environment\n";
	length = _strlen(dat->av[0]) + _strlen(ver_str);
	length += _strlen(dat->args[0]) + _strlen(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, dat->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, dat->args[0]);
	_strcat(error, msg);
	_strcat(error, "\0");
	free(ver_str);

	return (error);
}

/**
 * error_path_126 - this is used to
 * display the error message for path
 * and failure denied permission.
 * @dat: data relevant (counter, arguments).
 *
 * Return: The error string.
 */

char *error_path_126(data_shell *dat)
{
	int length;
	char *ver_str;
	char *error;

	ver_str = aux_itoa(dat->counter);
	length = _strlen(dat->av[0]) + _strlen(ver_str);
	length += _strlen(dat->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, dat->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, dat->args[0]);
	_strcat(error, ": Permission denied\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}
