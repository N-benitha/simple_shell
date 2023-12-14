#include "shell.h"

/**
 * exit_shell - This is used to exit the shell.
 * @dat: data relevant
 * (status and args)
 * Return: 0 on success.
 */

int exit_shell(data_shell *dat)
{
unsigned int ustatus;
int is_digit;
int str_len;
int big_number;

if (dat->args[1] != NULL)
{
ustatus = strtoi(dat->args[1]);
is_digit = _isdigit(dat->args[1]);
str_len = _strlen(dat->args[1]);
big_number = ustatus > (unsigned int)INT_MAX;
if (!is_digit || str_len > 10 || big_number)
{
get_error(dat, 2);
dat->status = 2;
return (1);
}
dat->status = (ustatus % 256);
}
return (0);
}
