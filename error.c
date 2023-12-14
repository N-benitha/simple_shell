#include "shell.h"

/**
 * strcat_cd - this code is used to
 * get function that concatenates
 * the message for cd error
 *
 * @dat: data relevant (directory)
 * @msg: message to print
 * @error: output message
 * @ver_str: counter lines
 * Return: error message
 */
char *strcat_cd(data_shell *dat, char *msg, char *error, char *ver_str)
{
	char *illegal_flag;

	_strcpy(error, dat->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, dat->args[0]);
	_strcat(error, msg);
	if (dat->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = dat->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(error, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(error, dat->args[1]);
	}

	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

/**
 * error_get_cd - this code is used to
 * get error message for
 * cd command in get_cd
 * @dat: data relevant (directory)
 * Return: Error message
 */

char *error_get_cd(data_shell *dat)
{
	int length, len_id;
	char *error, *ver_str, *msg;

	ver_str = aux_itoa(dat->counter);
	if (dat->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = _strlen(dat->args[1]);
	}

	length = _strlen(dat->av[0]) + _strlen(dat->args[0]);
	length += _strlen(ver_str) + _strlen(msg) + len_id + 5;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}

	error = strcat_cd(dat, msg, error, ver_str);

	free(ver_str);

	return (error);
}

/**
 * error_not_found - this is used to
 * return generic error message
 * for command not found
 * @dat: data relevant (counter, arguments)
 * Return: Error message
 */

char *error_not_found(data_shell *dat)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(dat->counter);
	length = _strlen(dat->av[0]) + _strlen(ver_str);
	length += _strlen(dat->args[0]) + 16;
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
	_strcat(error, ": not found\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}

/**
 * error_exit_shell - generic error message for exit in get_exit
 * @dat: data relevant (counter, arguments)
 *
 * Return: Error message
 */
char *error_exit_shell(data_shell *dat)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(dat->counter);
	length = _strlen(dat->av[0]) + _strlen(ver_str);
	length += _strlen(dat->args[0]) + _strlen(dat->args[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, dat->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, dat->args[0]);
	_strcat(error, ": Illegal number: ");
	_strcat(error, dat->args[1]);
	_strcat(error, "\n\0");
	free(ver_str);

	return (error);
}
/**
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}
