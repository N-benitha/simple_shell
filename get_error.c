#include "shell.h"
/**
 * get_error - This fetches and calls the error 
 * @dat: data structure that contains
 * all the arguments
 * @eval: error value
 * Return: error
 */
int get_error(data_shell *dat, int eval)
{
char *error = NULL;

if (eval == -1) {
error = error_env(dat);
}
else if (eval == 126)
{
error = error_path_126(dat);
}
else if (eval == 127)
{
error = error_not_found(dat);
}
else if (eval == 2)
{
if (str_cmp("exit", dat->args[0]) == 0)
{
error = error_exit_shell(dat);
}
else if (str_cmp("cd", dat->args[0]) == 0)
{
error = error_get_cd(dat);
}
}

if (error)
{
write(STDERR_FILENO, error, _strlen(error));
free(error);
}

dat->status = eval;
return eval;
}
